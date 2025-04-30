# 💼 Bank Account Management System

## FSOFT Project
**fsoft2025\_class-1DC\_team3**

**Team Members:**
* Vasco Magolo (1231562)
* Andre Moreira (1240567)
* Francisco Silva (1230985)
* Bernardo Meireles (1232024)

## 📌 Project Overview
A simple yet functional Bank Account Management System implemented in C++ that stores account data in JSON files. This application demonstrates our understanding of Object-Oriented Programming (OOP) principles, file handling using JSON, and implementation of a user-friendly Graphical User Interface (GUI).

## ✅ Core Functionality
* **Account Management**
  * Create new bank accounts with unique account numbers
  * Update account information (name, contact details)
  * Delete/close accounts
  * View account details
  
* **Financial Operations**
  * Deposit funds into accounts
  * Withdraw money with balance validation
  * Check account balances

* **Data Persistence**
  * Store all data in JSON format
  * Load account data from JSON on startup
  * Save account changes to JSON in real-time
  * Ensure data integrity between sessions

## 🔐 Authentication & Access Control
* Login system using account number and PIN/password
* Different access levels (user vs. admin)
* Admin privileges to view and manage all accounts
* Secure account operations

## 🖥️ GUI Implementation
* User-friendly graphical interface
* Login screen with authentication
* Screens for account creation, deposits, and withdrawals
* Account information display
* Confirmation and error messages
* Real-time updates reflected in the UI

## Project Structure
* `classes.h` & `classes.cpp` - Core classes including Account class definition and implementation
* `main.cpp` - Application entry point and GUI initialization
* `auth.cpp` & `auth.h` - Authentication system implementation
* `json_handler.cpp` & `json_handler.h` - JSON data handling
* `gui/` - Directory containing GUI implementation files
* `accounts.json` - JSON storage file for account data

## 🧪 Testing & Validation
* Core functionality validation
* Edge case handling (negative deposits, over-withdrawals)
* Input validation for all operations
* JSON data integrity checks

## Getting Started
1. **Prerequisites**
   * C++ compiler supporting C++17
   * nlohmann/json library
   * GUI library (to be determined)

2. **Installation**
   ```bash
   # Clone the repository
   git clone https://github.com/VascoMagolo/fsoft2025_class-1DC_team3.git
   cd fsoft2025_class-1DC_team3
   
   # Build the project (instructions may vary based on chosen GUI library)
   mkdir build && cd build
   cmake ..
   make
   ```

3. **Running the Application**
   ```bash
   ./bank_account_system
   ```

## Current Status
This project is under active development. We are currently implementing:
* Core account functionality and JSON integration
* Basic authentication system
* Initial GUI design and implementation

## 📦 Future Enhancements
* Transaction history tracking
* Advanced search and filtering options
* Report generation
* Enhanced security features
* Multi-currency support

## Authors
* Vasco Magolo
* Andre Moreira
* Francisco Silva
* Bernardo Meireles
