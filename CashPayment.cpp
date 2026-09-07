#include <iostream>
using namespace std;

class CashPayment : public Payment {
public:
    CashPayment(double amount) : Payment(amount) {}

    bool pay() override {
        status = "SUCCESS";
        cout << "Cash payment successful.\n";
        return true;
    }
};
