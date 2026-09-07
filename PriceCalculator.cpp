#include <vector>
using namespace std;

class PriceCalculator {
public:
    // Compile-time polymorphism: overloaded calculate() methods.
    double calculate(const vector<ShowSeat*>& seats) const {
        double total = 0;
        for (auto seat : seats)
            total += seat->getSeat()->getPrice();
        return total;
    }

    double calculate(const ShowSeat& seat) const {
        return seat.getSeat()->getPrice();
    }
};
