#include <iostream>
#include <vector>
#include <string>
using namespace std;

// No header files are used, as required by the assignment.
// One class is kept in each .cpp file; these files are included here
// so the project can be compiled as one translation unit.

#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "PriceCalculator.cpp"
#include "Booking.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"
#include "CinemaMenu.cpp"

int main() {
    // this keyword is used in constructors throughout the classes.

    Cinema cinema("PVR Demo Cinema");

    Screen screen1(1);
    Screen screen2(2);

    // Silver seats
    for (int i = 1; i <= 4; ++i)
        screen1.addSeat(Seat("A" + to_string(i), Seat::SILVER));

    // Gold seats
    for (int i = 5; i <= 8; ++i)
        screen1.addSeat(Seat("B" + to_string(i - 4), Seat::GOLD));

    // Platinum seats
    for (int i = 9; i <= 10; ++i)
        screen1.addSeat(Seat("C" + to_string(i - 8), Seat::PLATINUM));

    for (int i = 1; i <= 6; ++i)
        screen2.addSeat(Seat("A" + to_string(i), Seat::SILVER));

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    Movie movie1("Avengers: Endgame", "English", 181);
    Movie movie2("Inception", "English", 148);
    Movie movie3("Interstellar", "English", 169);

    vector<Movie*> movies = { &movie1, &movie2, &movie3 };

    Show show1(1, &movie1, cinema.getScreen(1), "10:00 AM");
    Show show2(2, &movie1, cinema.getScreen(2), "02:00 PM");
    Show show3(3, &movie2, cinema.getScreen(1), "06:00 PM");
    Show show4(4, &movie3, cinema.getScreen(2), "09:00 PM");

    vector<Show*> shows = { &show1, &show2, &show3, &show4 };

    Customer customer("Demo Customer", "9876543210");

    BookingService bookingService;

    CinemaMenu menu(&cinema, movies, shows, &bookingService, &customer);
    menu.start();

    return 0;
}
