#include <iostream>
#include <string>
using namespace std;

// Encapsulation: data is private and exposed through controlled methods.
class Movie {
private:
    string title, language;
    int duration;

public:
    Movie(string title, string language, int duration)
        : title(title), language(language), duration(duration) {}

    string getTitle() const { return title; }
    string getLanguage() const { return language; }
    int getDuration() const { return duration; }

    void getDetails() const {
        cout << title << " (" << language << ", " << duration << " min)";
    }
};
