// Functions File
#include "classes.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <ctime>// Library to generate random numbers
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
// Function to create a bank account
void create_bank_account() {
    string name, address, password;
    int age, op = 0;
    double balance = 0.0;

    cout << "Name:\n";
    cin.ignore(); // Clear the input buffer
    getline(cin, name); // Get the name

    cout << "Age:\n";
    while (!(cin >> age)) {
        cout << "Invalid input. Please enter a valid age:\n";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }

    cout << "Address:\n";
    cin.ignore(); // Clear the input buffer
    getline(cin, address); // Get the address

    cout << "Password:\n";
    getline(cin, password); // Get the password

    while (op != 1 && op != 2) {
        cout << "Do you want to add balance? \n Yes-1 No-2\n";
        cin >> op;
        if (op == 1) {
            cout << "Add Balance:\n";
            while (!(cin >> balance)) {
                cout << "Invalid input. Please enter a valid balance:\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (op != 2 && op != 1) {
            cout << "Invalid\n";
        }
    }
    Bank_Account account(rand(), balance, age, name, address,
                         password);// Creates an account with a random account number, later its going to be change by a unique number
    cout << "Account Created!\n";
    account.display(); // Display the account number and balance
    account.saveBalanceToFile(account.account_number); // Save the account balance to a file
}

// Function to login into an account
int login() {
    //login menu

    return 0;
}

int login_verify(int account_number, const std::string &password) {
    //read from json file and 'see' if there is any account that matches password and account_number, if yes, returns true otherwise returns false
    return 0;
}

// Function to display the menu
void menu() {

}

void write_into_json(int account_number, double balance, int age, const std::string &name, const std::string &address,
                     const std::string &password) {
    //to implement
    // Create JSON object directly using variables
    json Doc = {
            {"name",           name},
            {"account_number", account_number},
            {"balance",        balance},
            {"age",            age},
            {"address",        address},
            {"password",       password}
    };
    // Read existing data first
    json existingData;
    std::ifstream readFile("output.json");
    if (readFile.is_open()) {
        try {
            if (readFile.peek() != std::ifstream::traits_type::eof()) {
                readFile >> existingData;
            }
        } catch (const json::parse_error &e) {
            std::cerr << "JSON parse error reading existing file: " << e.what() << std::endl;
            existingData = json::array(); // Reset to empty array on error
        }
        readFile.close();
    }

    // If it's not an array yet, create one
    if (!existingData.is_array()) {
        existingData = json::array();
    }

    // Add new object to array
    existingData.push_back(Doc);

    // Write the entire array back to the file
    std::ofstream writeFile("output.json");
    if (!writeFile.is_open()) {
        std::cerr << "Failed to open file for writing!" << std::endl;
        return;
    }

    writeFile << existingData.dump(4); // Write with indentation
    writeFile.close();
}

void read_from_json() {
    std::ifstream file("output.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }

    try {
        json Doc;
        file >> Doc;

        // Example: Access fields
        for (const auto &account: Doc) {
            std::cout << "Name: " << account["name"] << std::endl;
            std::cout << "Account Number: " << account["account_number"] << std::endl;
            std::cout << "Account Balance: " << account["balance"] << std::endl;
        }
    } catch (const json::parse_error &e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
    }

    file.close();
}