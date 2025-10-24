# Bank Management System in C++ (OOP)

This repository contains a comprehensive, console-based Bank Management System. It serves as a **key learning project** designed to apply and demonstrate a strong understanding of **Object-Oriented Programming (OOP) principles**. This project showcases my skills in C++ development, software design, and practical **problem-solving**.

## 🎯 Project Objective & Demonstrated Skills

The primary goal of this project is to build a robust mini-banking system by implementing core OOP principles. This demonstrates a clear understanding of:

* **Encapsulation:** Bundling data (attributes) and methods (functions) into clean, logical classes (e.s., `clsBankClient`, `clsUser`).
* **Inheritance:** Reusing code effectively by having classes like `clsBankClient` and `clsUser` inherit from a base `clsPerson` class.
* **Polymorphism:** Using virtual functions in the base `clsScreen` class to create a flexible and scalable UI framework.
* **Abstraction:** Hiding complex implementation details (like file I/O operations) behind simple, high-level interfaces for easy management.

This project also highlights problem-solving skills in areas such as data persistence (managing text files as a database), secure user authentication, and logical business rule implementation (e.g., balance checking during withdrawals).

---

## ✨ Key Features

The system is packed with a wide range of features that simulate a real-world banking application:

### 1. Client Management
* [✔️] Add New Client with complete details.
* [✔️] Update Existing Client Information.
* [✔️] Delete a Client from the system.
* [✔️] Find a Client by their account number.
* [✔️] Display a list of all clients.
* [✔️] View a summary of all client balances (Total Balances).

### 2. Bank Transactions
* [✔️] **Deposit:** Add funds to a client's account.
* [✔️] **Withdraw:** Withdraw funds from an account, with validation to prevent overdrawing.
* [✔️] **Transfer:** Securely transfer money from one client to another within the system.
* [✔️] **Transfer Log:** All transfer operations are logged in a separate file for auditing and review.

### 3. User (Employee) Management
* [✔️] Secure login system for system users (employees).
* [✔️] Full User Management (Add, Update, Delete, Find users).
* [✔️] **Permissions System:** Control which actions each user is authorized to perform (e.g., manage clients, view transactions, manage users).
* [✔️] **Login Register:** Logs all login attempts (successful or failed) for security.

### 4. Currency Exchange
* [✔️] Add and update currency exchange rates.
* [✔️] A built-in currency calculator to convert amounts between different currencies based on saved rates.
* [✔️] Find and list all available currencies.

---

## 🛠️ Technologies Used

* **Programming Language:** C++
* **Paradigm:** Object-Oriented Programming (OOP)
* **Database:** Text Files (`.txt`) for data persistence (using C++ `fstream` library).
* **Environment:** Visual Studio (project includes `.sln` and `.vcxproj` files).

---

## 🚀 How to Run

1.  Clone the repository to your local machine:
    ```sh
    git clone [https://github.com/MohmmadSadiq/Bank-C--Project-OOP--learning-.git](https://github.com/MohmmadSadiq/Bank-C--Project-OOP--learning-.git)
    ```
2.  Open the `ClientProject.sln` file using **Visual Studio**.
3.  Build the solution (Build > Build Solution or press `Ctrl+Shift+B`).
4.  Run the project (Debug > Start Without Debugging or press `Ctrl+F5`).
5.  Write UserName User2 and Password 1234
