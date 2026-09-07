#include <string>
using namespace std;

// Abstraction: Payment defines the common payment contract.
class Payment {
protected:
    double amount;
    string status;

public:
    Payment(double amount) : amount(amount), status("PENDING") {}
    virtual ~Payment() = default;

    // Runtime polymorphism: child classes implement pay().
    virtual bool pay() = 0;

    double getAmount() const { return amount; }
    string getStatus() const { return status; }
};
