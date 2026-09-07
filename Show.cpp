#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Composition: Show owns ShowSeat objects for this particular show.
// Aggregation: Show uses an existing Movie and Screen.
class Show {
private:
    int id;
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:
    Show(int id, Movie* movie, Screen* screen, string startTime)
        : id(id), movie(movie), screen(screen), startTime(startTime) {
        for (auto& seat : screen->getSeats())
            showSeats.emplace_back(&seat);
    }

    int getId() const { return id; }
    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    string getStartTime() const { return startTime; }

    vector<ShowSeat>& getShowSeats() { return showSeats; }

    ShowSeat* findShowSeat(const string& number) {
        for (auto& showSeat : showSeats)
            if (showSeat.getSeatNumber() == number) return &showSeat;
        return nullptr;
    }

    void displaySeats() const {
        cout << "\n===== SEAT STATUS =====\n";
        for (const auto& s : showSeats)
            cout << s.getSeatNumber() << " [" << s.getSeat()->getTypeName()
                 << "] - " << s.getStatusName() << "\n";
    }
};
