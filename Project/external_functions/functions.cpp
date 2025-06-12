#include "functions.h"
// Functions File
#include "../classes.h"
#include <iostream>
#include <random>
#include <ctime>// Library to generate random numbers

using namespace std;

// Function to generate a unique account number
int generateUniqueAccountNumber() {
    // Get current time as seed
    unsigned seed = static_cast<unsigned>(time(nullptr));

    // Use a proper random number generator
    mt19937 gen(seed);

    // Generate 5-digit account numbers (10000-99999)
    uniform_int_distribution<> dist(10000, 99999);

    int newAccountNumber = dist(gen);

    // You could check here if the account number already exists in your system
    // by trying to load an account with this number
    try {
        Bank_Account::loadFromJson(newAccountNumber);
        // If we get here, account exists, so recursively try again
        return generateUniqueAccountNumber();
    } catch (const std::runtime_error &) {
        // If we get an exception, account doesn't exist, so we can use this number
        return newAccountNumber;
    }
}