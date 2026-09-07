#include <iostream>
#include <string>
using namespace std;

class ShowSeat {
public:
    enum Status { AVAILABLE, BOOKED };

private:
    Seat* seat;
    Status status;

public:
    ShowSeat(Seat* seat) : seat(seat), status(AVAILABLE) {}

    bool isAvailable() const { return status == AVAILABLE; }
    Seat* getSeat() const { return seat; }
    string getSeatNumber() const { return seat->getNumber(); }

    bool book() {
        if (!isAvailable()) return false;
        status = BOOKED;
        return true;
    }

    void cancel() {
        status = AVAILABLE;
    }

    string getStatusName() const {
        return isAvailable() ? "AVAILABLE" : "BOOKED";
    }
};
