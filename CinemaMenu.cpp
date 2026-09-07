#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class CinemaMenu {
private:
    Cinema* cinema;
    vector<Movie*> movies;
    vector<Show*> shows;
    BookingService* bookingService;
    Customer* customer;

public:
    CinemaMenu(Cinema* cinema, vector<Movie*> movies,
               vector<Show*> shows, BookingService* bookingService,
               Customer* customer)
        : cinema(cinema), movies(movies), shows(shows),
          bookingService(bookingService), customer(customer) {}

    void listMovies() const {
        cout << "\n===== MOVIES PLAYING =====\n";
        for (size_t i = 0; i < movies.size(); ++i) {
            cout << i + 1 << ". ";
            movies[i]->getDetails();
            cout << "\n";
        }
    }

    void listShows() const {
        listMovies();
        int movieChoice;
        cout << "Select movie: ";
        cin >> movieChoice;

        if (movieChoice < 1 || movieChoice > (int)movies.size()) {
            cout << "Invalid movie choice.\n";
            return;
        }

        cout << "\n===== SHOWS =====\n";
        for (auto show : shows) {
            if (show->getMovie() == movies[movieChoice - 1]) {
                cout << show->getId() << ". Screen "
                     << show->getScreen()->getScreenNumber()
                     << " - " << show->getStartTime() << "\n";
            }
        }
    }

    Show* chooseShow() {
        cout << "\nAvailable Shows:\n";
        for (auto show : shows)
            cout << show->getId() << ". "
                 << show->getMovie()->getTitle()
                 << " | Screen " << show->getScreen()->getScreenNumber()
                 << " | " << show->getStartTime() << "\n";

        int id;
        cout << "Enter show ID: ";
        cin >> id;

        for (auto show : shows)
            if (show->getId() == id) return show;

        cout << "Invalid show ID.\n";
        return nullptr;
    }

    void viewSeats() const {
        int id;
        cout << "Enter show ID: ";
        cin >> id;

        for (auto show : shows) {
            if (show->getId() == id) {
                show->displaySeats();
                return;
            }
        }
        cout << "Invalid show ID.\n";
    }

    void bookTicket() {
        Show* show = chooseShow();
        if (!show) return;

        show->displaySeats();

        string line;
        cout << "Enter seat numbers separated by spaces (example: A1 A2): ";
        cin.ignore();
        getline(cin, line);

        stringstream ss(line);
        vector<string> seatNumbers;
        string seat;
        while (ss >> seat) seatNumbers.push_back(seat);

        if (seatNumbers.empty()) {
            cout << "No seat selected.\n";
            return;
        }

        cout << "\nPayment Method:\n";
        cout << "1. UPI\n2. Card\n3. Cash\n";
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        bookingService->book(customer, show, seatNumbers, choice);
    }

    void cancelBooking() {
        string id;
        cout << "Enter booking ID: ";
        cin >> id;
        bookingService->cancelBooking(id);
    }

    void start() {
        while (true) {
            cout << "\n====================================\n";
            cout << "      MOVIE TICKET BOOKING SYSTEM\n";
            cout << "====================================\n";
            cout << "1. List Movies\n";
            cout << "2. List Shows\n";
            cout << "3. View Seats\n";
            cout << "4. Book Ticket\n";
            cout << "5. Cancel Booking\n";
            cout << "6. Exit\n";
            cout << "Enter choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1: listMovies(); break;
                case 2: listShows(); break;
                case 3: viewSeats(); break;
                case 4: bookTicket(); break;
                case 5: cancelBooking(); break;
                case 6: cout << "Thank you!\n"; return;
                default: cout << "Invalid menu choice. Please try again.\n";
            }
        }
    }
};
