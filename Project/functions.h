#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void create_bank_account(); // Function to create a bank account
int login(); // Function to login into an account
int login_verify(int account_number, const std::string &password);
void menu(); // Function to display the menu
void write_into_json(int account_number, double balance, int age, const std::string &name, const std::string &address,
                     const std::string &password); // Function to write into a json file and create one if not found
void read_from_json(); // Function to read from a json file
#endif //FUNCTIONS_H
