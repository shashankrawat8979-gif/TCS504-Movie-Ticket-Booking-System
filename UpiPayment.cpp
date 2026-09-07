#include <iostream>
#include <string>
using namespace std;

// Inheritance: UpiPayment is a Payment.
class UpiPayment : public Payment {
private:
    string upiId;

public:
    UpiPayment(double amount, string upiId)
        : Payment(amount), upiId(upiId) {}

    bool pay() override {
        if (upiId.empty() || upiId == "fail@upi") {
            status = "FAILED";
            cout << "UPI payment failed.\n";
            return false;
        }
        status = "SUCCESS";
        cout << "UPI payment successful.\n";
        return true;
    }
};
