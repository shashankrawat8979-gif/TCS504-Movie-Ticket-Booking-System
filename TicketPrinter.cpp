#include <iostream>
using namespace std;

// Single Responsibility: this class only prints/formats tickets.
class TicketPrinter {
public:
    void printTicket(const Booking& booking) const {
        cout << "\n====================================\n";
        cout << "              TICKET\n";
        cout << "====================================\n";
        cout << "Booking ID : " << booking.getBookingId() << "\n";
        cout << "Customer   : " << booking.getCustomer()->getName() << "\n";
        cout << "Movie      : " << booking.getShow()->getMovie()->getTitle() << "\n";
        cout << "Screen     : " << booking.getShow()->getScreen()->getScreenNumber() << "\n";
        cout << "Time       : " << booking.getShow()->getStartTime() << "\n";
        cout << "Seats      : ";
        for (auto seat : booking.getSeats())
            cout << seat->getSeatNumber() << " ";
        cout << "\nTotal      : Rs. " << booking.getAmount() << "\n";
        cout << "Status     : CONFIRMED\n";
        cout << "====================================\n";
    }
};
