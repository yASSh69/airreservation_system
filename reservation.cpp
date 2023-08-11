#include <iostream>
#include <vector>
#include <iomanip>

class Flight {
public:
    Flight(std::string flightNumber, int numRows, int numCols)
        : flightNumber(flightNumber), numRows(numRows), numCols(numCols) {
        initializeSeatingArrangement();
    }

    void drawSeatingArrangement();
    bool bookSeat(int row, int col);

private:
    std::string flightNumber;
    int numRows;
    int numCols;
    std::vector<std::vector<bool>> seatingArrangement;

    void initializeSeatingArrangement() {
        seatingArrangement.assign(numRows, std::vector<bool>(numCols, false));
    }
};

void Flight::drawSeatingArrangement() {
    std::cout << "Seating Arrangement for Flight " << flightNumber << ":" << std::endl;

    // Print column numbers
    std::cout << "  ";
    for (int col = 0; col < numCols; ++col) {
        std::cout << std::setw(3) << col + 1;
    }
    std::cout << std::endl;

    for (int row = 0; row < numRows; ++row) {
        std::cout << std::setw(2) << row + 1;
        for (int col = 0; col < numCols; ++col) {
            char seatChar = seatingArrangement[row][col] ? 'X' : ' ';
            std::cout << "[" << seatChar << "]";
        }
        std::cout << std::endl;
    }
}

bool Flight::bookSeat(int row, int col) {
    if (row >= 0 && row < numRows && col >= 0 && col < numCols && !seatingArrangement[row][col]) {
        seatingArrangement[row][col] = true;
        return true;
    }
    return false;
}


int main() {
    std::cout << "Welcome to the Airline Seating Arrangement!" << std::endl;

    while (true) {
        std::string passengerName, address;
        int age;
        
        std::cout << "Enter your name: ";
        std::cin.ignore();  // Clear newline character from previous input
        std::getline(std::cin, passengerName);

        std::cout << "Enter your age: ";
        std::cin >> age;
        
        std::cout << "Enter your address: ";
        std::cin.ignore();  // Clear newline character from previous input
        std::getline(std::cin, address);

        Flight flight1("F123", 5, 10);
        Flight flight2("F456", 5, 10);

        while (true) {
            int flightChoice;
            std::cout << "Choose a flight to view seating arrangement:" << std::endl;
            std::cout << "1. Flight F123 (City A to City B)" << std::endl;
            std::cout << "2. Flight F456 (City C to City D)" << std::endl;
            std::cin >> flightChoice;

            if (flightChoice == 1) {
                flight1.drawSeatingArrangement();
            } else if (flightChoice == 2) {
                flight2.drawSeatingArrangement();
            } else {
                std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
                continue;
            }

            int row, col;
            std::cout << "Enter row and column numbers for seat booking: ";
            std::cin >> row >> col;

            if (flightChoice == 1) {
                if (flight1.bookSeat(row - 1, col - 1)) {
                    std::cout << "Seat booked successfully!" << std::endl;
                } else {
                    std::cout << "Seat is already booked or invalid seat." << std::endl;
                }
            } else if (flightChoice == 2) {
                if (flight2.bookSeat(row - 1, col - 1)) {
                    std::cout << "Seat booked successfully!" << std::endl;
                } else {
                    std::cout << "Seat is already booked or invalid seat." << std::endl;
                }
            }

            std::cout << "Do you want to make another booking? (yes/no): ";
            std::string anotherBooking;
            std::cin >> anotherBooking;
            if (anotherBooking != "yes") {
                break;
            }
        }

        std::cout << "Thank you, " << passengerName << "! Your booking details:" << std::endl;
        std::cout << "Name: " << passengerName << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Address: " << address << std::endl;

        std::cout << "Do you want to make another reservation? (yes/no): ";
        std::string anotherReservation;
        std::cin >> anotherReservation;
        if (anotherReservation != "yes") {
            break;
        }
    }

    return 0;
}
