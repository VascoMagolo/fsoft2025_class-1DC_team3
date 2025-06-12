#include "functions.h"
// Functions File
#include "../classes.h"
#include <iostream>
#include <random>
#include <ctime>// Library to generate random numbers

using namespace std;

// Function to generate a unique account number
// int generateUniqueAccountNumber() {
//     unsigned seed = static_cast<unsigned>(time(nullptr));
//     mt19937 gen(seed);
//     uniform_int_distribution<> dist(10000, 99999);
//     int newAccountNumber = dist(gen);
//     try {
//         Bank_Account::loadFromJson(newAccountNumber);
//         return generateUniqueAccountNumber();
//     } catch (const std::runtime_error &) {
//         return newAccountNumber;
//     }
// }