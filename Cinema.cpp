#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Composition: Cinema owns its Screen objects.
class Cinema {
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(string name) : name(name) {}

    void addScreen(const Screen& screen) {
        screens.push_back(screen);
    }

    string getName() const { return name; }
    vector<Screen>& getScreens() { return screens; }
    const vector<Screen>& getScreens() const { return screens; }

    Screen* getScreen(int number) {
        for (auto& screen : screens)
            if (screen.getScreenNumber() == number) return &screen;
        return nullptr;
    }
};
