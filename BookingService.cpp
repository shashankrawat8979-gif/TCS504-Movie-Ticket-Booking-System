#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Dependency Inversion: service accepts a Payment abstraction.
class BookingService {
private:
    PriceCalculator calculator;
    TicketPrinter printer;
    vector<Booking*> bookings;

public:
    ~BookingService() {
        for (auto booking : bookings) delete booking;
    }

    Booking* book(Customer* customer, Show* show,
                  const vector<string>& seatNumbers, int paymentChoice) {
        vector<ShowSeat*> selected;

        for (const string& number : seatNumbers) {
            ShowSeat* seat = show->findShowSeat(number);

            if (!seat) {
                cout << "Invalid seat number: " << number << "\n";
                return nullptr;
            }

            if (!seat->isAvailable()) {
                cout << "Seat " << number << " is already BOOKED. Booking rejected.\n";
                return nullptr;
            }

            selected.push_back(seat);
        }

        double total = calculator.calculate(selected);

        cout << "\nTotal Amount: Rs. " << total << "\n";

        // Create payment according to selected method.
        Payment* payment = nullptr;

        if (paymentChoice == 1) {
            string upi;
            cout << "Enter UPI ID (use fail@upi to test failure): ";
            cin >> upi;
            payment = new UpiPayment(total, upi);
        } else if (paymentChoice == 2) {
            string card;
            cout << "Enter Card Number (use FAIL to test failure): ";
            cin >> card;
            payment = new CardPayment(total, card);
        } else if (paymentChoice == 3) {
            payment = new CashPayment(total);
        } else {
            cout << "Invalid payment option.\n";
            return nullptr;
        }

        // Temporarily book seats. If payment fails, release them.
        for (auto seat : selected) seat->book();

        bool paid = payment->pay();

        if (!paid) {
            for (auto seat : selected) seat->cancel();
            delete payment;
            cout << "Payment failed. Booking NOT confirmed and seats released.\n";
            return nullptr;
        }

        Booking* booking = new Booking(customer, show, selected, total);
        booking->setPayment(payment);
        booking->confirm();
        bookings.push_back(booking);

        printer.printTicket(*booking);
        return booking;
    }

    bool cancelBooking(const string& bookingId) {
        for (auto booking : bookings) {
            if (booking->getBookingId() == bookingId) {
                if (!booking->isConfirmed()) {
                    cout << "Booking cannot be cancelled.\n";
                    return false;
                }

                booking->cancel();
                cout << "Booking cancelled. Seats are AVAILABLE again.\n";
                return true;
            }
        }

        cout << "Booking ID not found.\n";
        return false;
    }
};
