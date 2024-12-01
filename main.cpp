#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <map>
#include <ctime>

using namespace std;

// Structure to store expense details
struct Expense {
    string description;
    float amount;
    string category;
    int day, month, year;

    Expense(string desc, float amt, string cat, int d, int m, int y)
        : description(desc), amount(amt), category(cat), day(d), month(m), year(y) {}
};

// Function to get the current year
int getCurrentYear() {
    time_t now = time(0);
    struct tm tstruct;
    tstruct = *localtime(&now);
    return tstruct.tm_year + 1900;
}

// Function to get the current month
int getCurrentMonth() {
    time_t now = time(0);
    struct tm tstruct;
    tstruct = *localtime(&now);
    return tstruct.tm_mon + 1;
}

// Class to manage the expenses
class ExpenseTracker {
private:
    vector<Expense> expenses;
    float monthlyBudget;

public:
    ExpenseTracker() : monthlyBudget(0.0f) {}

    void setMonthlyBudget(float budget) {
        monthlyBudget = budget;
    }

    void addExpense() {
        string description, category;
        float amount;
        int day, month, year;

        cout << "Enter expense description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter category: ";
        cin.ignore();
        getline(cin, category);
        cout << "Enter day of expense: ";
        cin >> day;
        cout << "Enter month of expense: ";
        cin >> month;
        cout << "Enter year of expense: ";
        cin >> year;

        expenses.push_back(Expense(description, amount, category, day, month, year));
        cout << "Expense added successfully!\n";
    }

    void updateExpense() {
        int index;
        cout << "Enter the index of the expense to update (0 to " << expenses.size() - 1 << "): ";
        cin >> index;

        if (index < 0 || index >= expenses.size()) {
            cout << "Invalid index!\n";
            return;
        }

        string description, category;
        float amount;
        int day, month, year;

        cout << "Enter new description (current: " << expenses[index].description << "): ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter new amount (current: " << expenses[index].amount << "): ";
        cin >> amount;
        cout << "Enter new category (current: " << expenses[index].category << "): ";
        cin.ignore();
        getline(cin, category);
        cout << "Enter new day (current: " << expenses[index].day << "): ";
        cin >> day;
        cout << "Enter new month (current: " << expenses[index].month << "): ";
        cin >> month;
        cout << "Enter new year (current: " << expenses[index].year << "): ";
        cin >> year;

        expenses[index] = Expense(description, amount, category, day, month, year);
        cout << "Expense updated successfully!\n";
    }

    void deleteExpense() {
        int index;
        cout << "Enter the index of the expense to delete (0 to " << expenses.size() - 1 << "): ";
        cin >> index;

        if (index < 0 || index >= expenses.size()) {
            cout << "Invalid index!\n";
            return;
        }

        expenses.erase(expenses.begin() + index);
        cout << "Expense deleted successfully!\n";
    }

    void viewAllExpenses() {
        if (expenses.empty()) {
            cout << "No expenses to show!\n";
            return;
        }

        for (int i = 0; i < expenses.size(); ++i) {
            cout << "Expense " << i << ": " << expenses[i].description
                 << " | Amount: " << expenses[i].amount
                 << " | Category: " << expenses[i].category
                 << " | Date: " << expenses[i].day << "/" << expenses[i].month << "/" << expenses[i].year
                 << endl;
        }
    }

    void viewExpenseSummary() {
        float total = 0.0f;
        for (const auto& expense : expenses) {
            total += expense.amount;
        }

        cout << "Total expenses: " << total << endl;

        if (monthlyBudget > 0.0f && total > monthlyBudget) {
            cout << "Warning: You have exceeded your budget!" << endl;
        }
    }

    void viewExpenseSummaryByMonth(int month) {
        float total = 0.0f;
        for (const auto& expense : expenses) {
            if (expense.month == month) {
                total += expense.amount;
            }
        }

        cout << "Total expenses for month " << month << ": " << total << endl;

        if (monthlyBudget > 0.0f && total > monthlyBudget) {
            cout << "Warning: You have exceeded your budget for this month!" << endl;
        }
    }

    void filterExpensesByCategory() {
        string category;
        cout << "Enter category to filter: ";
        cin.ignore();
        getline(cin, category);

        float total = 0.0f;
        for (const auto& expense : expenses) {
            if (expense.category == category) {
                cout << expense.description << " | Amount: " << expense.amount
                     << " | Date: " << expense.day << "/" << expense.month << "/" << expense.year
                     << endl;
                total += expense.amount;
            }
        }

        cout << "Total expenses for category '" << category << "': " << total << endl;
    }

    void exportToCSV() {
        string filename;
        cout << "Enter filename to export to (e.g., expenses.csv): ";
        cin >> filename;
    
        // Open the file in write mode
        ofstream file(filename);
    
        // Check if the file is successfully opened
        if (!file.is_open()) {
            cout << "Error: Could not open file for writing. Please check your file path and permissions.\n";
            return;
        }
    
        // Writing the header row
        file << "Description,Amount,Category,Day,Month,Year\n";
    
        // Writing each expense's details to the CSV file
        for (const auto& expense : expenses) {
            file << "\"" << expense.description << "\","
                 << expense.amount << ","
                 << "\"" << expense.category << "\","
                 << expense.day << ","
                 << expense.month << ","
                 << expense.year << "\n";
        }
    
        // Debugging: Confirm that the file is written
        cout << "Expenses have been exported to " << filename << " successfully!\n";
    
        // Close the file
        file.close();
    }

};

int main() {
    ExpenseTracker tracker;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n=== Expense Tracker ===\n";
        cout << "1. Add Expense\n";
        cout << "2. Update Expense\n";
        cout << "3. Delete Expense\n";
        cout << "4. View All Expenses\n";
        cout << "5. View Expense Summary\n";
        cout << "6. View Expense Summary for Specific Month\n";
        cout << "7. Filter Expenses by Category\n";
        cout << "8. Set Monthly Budget\n";
        cout << "9. Export Expenses to CSV\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tracker.addExpense();
                break;
            case 2:
                tracker.updateExpense();
                break;
            case 3:
                tracker.deleteExpense();
                break;
            case 4:
                tracker.viewAllExpenses();
                break;
            case 5:
                tracker.viewExpenseSummary();
                break;
            case 6: {
                int month;
                cout << "Enter month (1-12): ";
                cin >> month;
                tracker.viewExpenseSummaryByMonth(month);
                break;
            }
            case 7:
                tracker.filterExpensesByCategory();
                break;
            case 8: {
                float budget;
                cout << "Enter monthly budget: ";
                cin >> budget;
                tracker.setMonthlyBudget(budget);
                break;
            }
            case 9:
                tracker.exportToCSV();
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
