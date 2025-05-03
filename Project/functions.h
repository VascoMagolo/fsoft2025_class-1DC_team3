#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void create_bank_account(); // Function to create a bank account
int login(); // Function to login into an account
int login_verify(int account_number, const std::string &password);

void menu(int account_number); // Function to display the menu
void read_from_json(); // Function to read from a json file

#endif //FUNCTIONS_H
