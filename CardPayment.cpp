#include <iostream>
#include <string>
using namespace std;

class CardPayment : public Payment {
private:
    string cardNo;

public:
    CardPayment(double amount, string cardNo)
        : Payment(amount), cardNo(cardNo) {}

    bool pay() override {
        if (cardNo.empty() || cardNo == "FAIL") {
            status = "FAILED";
            cout << "Card payment failed.\n";
            return false;
        }
        status = "SUCCESS";
        cout << "Card payment successful.\n";
        return true;
    }
};
