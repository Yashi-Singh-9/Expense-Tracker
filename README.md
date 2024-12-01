# Expense Tracker

This is a simple **Expense Tracker** application built in C++ that allows you to manage your finances by adding, updating, deleting, viewing, and exporting expenses. It helps you track your spending habits and stay within your budget.

## Features

- **Add Expense**: Allows users to add an expense with a description, amount, category, and date.
- **Update Expense**: Modify an existing expense by changing its description, amount, category, or date.
- **Delete Expense**: Remove an expense from the list.
- **View All Expenses**: Displays all expenses stored in the system.
- **Expense Summary**: View the total amount of all expenses and a warning if you exceed your monthly budget.
- **Expense Summary by Month**: View the total expenses for a specific month.
- **Filter by Category**: Filter expenses by category and view the total spent in that category.
- **Set Monthly Budget**: Set a monthly budget and receive a warning if your expenses exceed it.
- **Export to CSV**: Export your expenses to a CSV file for record-keeping or analysis.

## Features Added:

- Expense categories to better manage spending.
- Monthly budget tracking and alerts when exceeded.
- Export expenses to a CSV file for easy reporting.

## Prerequisites

To run this project, you need to have:

- A C++ compiler (e.g., GCC, Clang).
- Basic knowledge of using the command line.

## How to Run

### Step 1: Download or Clone the Repository

You can clone or download the project files from the repository:

```bash
git clone https://github.com/Yashi-Singh-9/Expense-Tracker.git
```

### Step 2: Compile the Program

Navigate to the folder where you have saved the project files and compile the program using the following command:

```bash
g++ -o Expense-Tracker main.cpp
```

### Step 3: Run the Program

Once compiled, you can run the program with:

```bash
./Expense-Tracker
```

### Step 4: Use the Application

The program will present you with a menu of options. You can add, update, delete, view expenses, set your monthly budget, and export expenses to a CSV file.

### Export to CSV

When you choose the "Export Expenses to CSV" option, the program will prompt you to enter a filename (e.g., `expenses.csv`). The file will be saved in the current working directory, or you can specify a full path to save it elsewhere.

## Example Output

After running the program and choosing to export the expenses to a CSV file, the contents of the `expenses.csv` file will look something like:

```csv
Description,Amount,Category,Day,Month,Year
"Lunch",10.5,Food,1,12,2024
"Movie Ticket",15.0,Entertainment,5,12,2024
```

## Link to Roadmap

This project is part of a larger **Roadmap for building an Expense Tracker** as outlined on [roadmap.sh](https://roadmap.sh/projects/expense-tracker). You can follow this guide to enhance the functionality of this project further.

## License

This project is open source and available under the [MIT License](LICENSE).
