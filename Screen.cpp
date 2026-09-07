#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Composition: Screen owns its Seat objects.
class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int screenNumber) : screenNumber(screenNumber) {}

    int getScreenNumber() const { return screenNumber; }

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    vector<Seat>& getSeats() { return seats; }
    const vector<Seat>& getSeats() const { return seats; }

    Seat* findSeat(const string& number) {
        for (auto& seat : seats)
            if (seat.getNumber() == number) return &seat;
        return nullptr;
    }

    void displaySeats() const {
        cout << "\nScreen " << screenNumber << " Seat Layout\n";
        for (const auto& seat : seats)
            cout << seat.getNumber() << " [" << seat.getTypeName() << "] ";
        cout << "\n";
    }
};
