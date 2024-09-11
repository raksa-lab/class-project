#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iomanip> // For formatting output
#include <windows.h> // For Windows-specific console manipulation
#include <conio.h> // For formatting output
using namespace std;

struct User {
    string username;
    string email;
    string password;
};

// Admin credentials (hardcoded for this example)
const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "admin123";

// Global vector to store user data
vector<User> users;

void clearScreen() {
    system("cls");
}

// Function to display the main menu
void firstMenu() {
    cout << "=====================================================================================================================================" << endl;
    cout << "                                   1. Login                                                                                          " << endl;
    cout << "                                   2. List all Products                                                                              " << endl;
    cout << "                                   3. Add Products to Cart                                                                           " << endl;
    cout << "                                   4. Order Product                                                                                  " << endl;
    cout << "                                   5. Settings                                                                                       " << endl;
    cout << "                                   6. Admin Login                                                                                    " << endl; // New Admin Login option
    cout << "                                   0. Exit                                                                                           " << endl;
    cout << "=====================================================================================================================================" << endl;
    cout << "Please Enter Your Choice: ";
}

// Function to register a new user
void registerUser() {
    cout << "                      [+1]. Register Account               " << endl;
    string username, email, password;
    cout << "         USERNAME: ";
    cin >> username;
    cout << "         EMAIL: ";
    cin >> email;
    cout << "         PASSWORD: ";
    cin >> password;

    // Check if user already exists
    for (const auto& user : users) {
        if (user.username == username) {
            cout << "Username already exists. Please try a different username." << endl;
            return;
        }
    }

    // Add new user to vector
    users.push_back({username, email, password});
    cout << "......................................................" << endl;
    cout << " You completed your Account Successfully. " << endl;
}

// Function to log in a user
void login() {
    string username, password;
    cout << "                 [+2]. Login Account                                     " << endl;
    cout << "           USERNAME:                     ";
    cin >> username;
    cout << "           PASSWORD:                     ";
    cin >> password;

    bool found = false;
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << username << "  Your Login is Successful." << endl;
    } else {
        cout << "  Your Login is Incorrect. Please try again!! " << endl;
    }
}

void forgot() {
    int option;
    cout << "|       1. Search Id by Username           |" << endl;
    cout << "|       2. Go Back to the Menu             |" << endl;
    cout << "Please Enter Your Option: ";
    cin >> option;

    switch (option) {
        case 1: {
            string susername;
            cout << "USERNAME: ";
            cin >> susername;

            bool found = false;
            for (const auto& user : users) {
                if (user.username == susername) {
                    found = true;
                    cout << "Your Account is Found." << endl;
                    cout << "Your Password is: " << user.password << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Sorry! Your Account is Not Found." << endl;
            }
            break;
        }
        case 2:
            firstMenu();
            break;
        default:
            cout << "Invalid option. Please try again!" << endl;
    }
}

void secondMenu() {
    cout << "......................................................................................................" << endl;
    cout << "                                        [+1]. Register Account                                        " << endl;
    cout << "                                        [+2]. Login Account                                           " << endl;
    cout << "                                        [+3]. Forgot Password                                         " << endl;
    cout << "                                        [+0]. Exit                                                    " << endl;
    cout << "......................................................................................................" << endl;
    cout << "Please Enter your Choice: ";
}

void loginRegisterUser() {
    int option;
    do {
        secondMenu();
        cin >> option;
        switch (option) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                forgot();
                break;
            case 0:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again!" << endl;
        }
    } while (option != 0);
}

// Function for admin login
void adminLogin() {
    string username, password;
    cout << "Admin Username: ";
    cin >> username;
    cout << "Admin Password: ";
    cin >> password;

    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
        cout << "Admin login successful!" << endl;
        // Admin functionality menu
        int adminChoice;
        do {
            cout << "\n============================" << endl;
            cout << "     Admin Control Panel     " << endl;
            cout << "============================" << endl;
            cout << "1. View All User Accounts" << endl;
            cout << "2. Manage Products" << endl;
            cout << "0. Logout" << endl;
            cout << "============================" << endl;
            cout << "Enter choice: ";
            cin >> adminChoice;

            switch (adminChoice) {
                case 1: {
                    if (users.empty()) {
                        cout << "No accounts to display!" << endl;
                    } else {
                        for (const auto& user : users) {
                            cout << "Username: " << user.username << endl;
                            cout << "Email: " << user.email << endl;
                            cout << "Password: " << user.password << endl;
                            cout << "---------------------------" << endl;
                        }
                    }
                    break;
                }
                case 2:
                    // Add product management functionality here
                    cout << "Manage Products feature is not implemented yet." << endl;
                    break;
                case 0:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "Invalid choice! Try again." << endl;
            }
        } while (adminChoice != 0);
    } else {
        cout << "Invalid admin credentials!" << endl;
    }
}

// Main menu handler
int main() {
    int choice;
    do {
        firstMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                loginRegisterUser();
                break;
            case 2:
                // List all products functionality (not implemented)
                break;
            case 3:
                // Add products to cart functionality (not implemented)
                break;
            case 4:
                // Order product functionality (not implemented)
                break;
            case 5:
                // Settings menu (user settings)
                break;
            case 6:
                adminLogin(); // New Admin Login option
                break;
            case 0:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
        }
    } while (choice != 0);

    return 0;
}
