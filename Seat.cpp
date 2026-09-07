#include <iostream>
#include <string>
using namespace std;

class Seat {
public:
    enum Type { SILVER = 1, GOLD = 2, PLATINUM = 3 };

private:
    string number;
    Type type;

public:
    Seat(string number, Type type) : number(number), type(type) {}

    string getNumber() const { return number; }
    Type getType() const { return type; }

    double getPrice() const {
        if (type == SILVER) return 150;
        if (type == GOLD) return 250;
        return 400;
    }

    string getTypeName() const {
        if (type == SILVER) return "SILVER";
        if (type == GOLD) return "GOLD";
        return "PLATINUM";
    }
};
