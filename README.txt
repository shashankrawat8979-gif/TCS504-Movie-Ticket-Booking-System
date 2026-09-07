TCS-504 Assignment 1
Movie Ticket Booking System - C++

HOW TO RUN
1. Put all .cpp files in the same folder.
2. Open terminal in that folder.
3. Compile:
   g++ -std=c++17 main.cpp -o movie
4. Run:
   Windows: movie.exe
   Linux/macOS: ./movie

FILES
Movie.cpp
Seat.cpp
Screen.cpp
Cinema.cpp
ShowSeat.cpp
Show.cpp
Customer.cpp
Booking.cpp
Payment.cpp
UpiPayment.cpp
CardPayment.cpp
CashPayment.cpp
PriceCalculator.cpp
TicketPrinter.cpp
BookingService.cpp
CinemaMenu.cpp
main.cpp

TEST CASES
1. Normal booking:
   Choose Book Ticket -> select a free seat -> UPI -> enter any normal UPI ID.

2. Already booked seat:
   Book A1 successfully, then try A1 again. It should be rejected.

3. Failed payment:
   Choose UPI and enter:
   fail@upi
   The seats should become AVAILABLE again.

4. Failed card payment:
   Choose Card and enter:
   FAIL
   The seats should become AVAILABLE again.

5. Cancellation:
   After a successful booking, use Cancel Booking and enter its Booking ID.
   The seats become AVAILABLE again.

6. Invalid input:
   Enter an invalid menu choice or seat number. The program should show a
   clear message and continue instead of crashing.

OOP CONCEPTS PRESENT
- Encapsulation
- Abstraction
- Inheritance
- Runtime Polymorphism
- Compile-time Polymorphism
- Static Member
- this keyword
- Composition
- Aggregation

NOTE
The assignment says "one class per file" and "no header files", so the project
uses one class per .cpp file. main.cpp includes those implementation files
to compile the project without .h files.
