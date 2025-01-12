#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for setting precision
using namespace std;

// Structure to store employee data
struct Employee {
    int id;
    string name;
    int totalDays;   // Total working days
    int daysPresent; // Days the employee was present
};

// Function prototypes
void markAttendance(vector<Employee>& employees);
void viewAnalytics(const vector<Employee>& employees);

int main() {
    vector<Employee> employees = {
        {1, "Alice", 30, 0},
        {2, "Bob", 30, 0},
        {3, "Charlie", 30, 0},
    };

    int choice;

    do {
        // Main menu
        cout << "\n--- Employee Attendance Tracker ---\n";
        cout << "1. Mark Attendance\n";
        cout << "2. View Analytics\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            markAttendance(employees);
            break;
        case 2:
            viewAnalytics(employees);
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// Function to mark attendance for employees
void markAttendance(vector<Employee>& employees) {
    cout << "\nMark Attendance: \n";
    for (auto& employee : employees) {
        char present;
        cout << "Is " << employee.name << " (ID: " << employee.id << ") present? (y/n): ";
        cin >> present;
        if (tolower(present) == 'y') {
            employee.daysPresent++;
        }
    }
    cout << "Attendance marked successfully.\n";
}

// Function to display analytics
void viewAnalytics(const vector<Employee>& employees) {
    cout << "\n--- Attendance Analytics ---\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Days Present" << "Attendance %\n";
    cout << string(50, '-') << "\n";

    for (const auto& employee : employees) {
        double attendancePercentage = (static_cast<double>(employee.daysPresent) / employee.totalDays) * 100;
        cout << left << setw(10) << employee.id << setw(20) << employee.name << setw(15) << employee.daysPresent << fixed << setprecision(2) << attendancePercentage << "%\n";
    }
}
