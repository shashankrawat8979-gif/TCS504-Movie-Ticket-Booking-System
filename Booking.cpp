#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Static member concept: unique booking IDs are shared across objects.
class Booking {
public:
    enum Status { PENDING, CONFIRMED, CANCELLED };

private:
    static int nextBookingId;
    string bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    double amount;
    Status status;
    Payment* payment;

public:
    Booking(Customer* customer, Show* show,
            const vector<ShowSeat*>& seats, double amount)
        : customer(customer), show(show), seats(seats),
          amount(amount), status(PENDING), payment(nullptr) {
        bookingId = "BK" + to_string(nextBookingId++);
    }

    string getBookingId() const { return bookingId; }
    double getAmount() const { return amount; }
    Show* getShow() const { return show; }
    const vector<ShowSeat*>& getSeats() const { return seats; }
    Customer* getCustomer() const { return customer; }
    Status getStatus() const { return status; }

    void setPayment(Payment* payment) { this->payment = payment; }

    void confirm() { status = CONFIRMED; }

    void cancel() {
        for (auto seat : seats) seat->cancel();
        status = CANCELLED;
    }

    bool isConfirmed() const { return status == CONFIRMED; }
};

int Booking::nextBookingId = 1001;
