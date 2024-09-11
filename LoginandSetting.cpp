#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

struct User {
    string username;
    string email;
    string password;
};

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

// Function to handle forgotten passwords


// Function to change the password
void changePassword() {
    cout << "Enter username to change password: ";
    string username;
    cin.ignore();
    getline(cin, username);

    bool found = false;
    for (auto& user : users) {
        if (user.username == username) {
            string old_password;
            cout << "Enter old password: ";
            getline(cin, old_password);

            if (old_password == user.password) {
                cout << "Enter new password: ";
                string newpassword;
                getline(cin, newpassword);
                user.password = newpassword;
                cout << "Password changed successfully!" << endl;
            } else {
                cout << "Password incorrect!" << endl;
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Username not found!" << endl;
    }
}

// Function to display settings menu
void MenuSetting() {
    cout << "_________________________|" << endl;
    cout << "|      User Settings      |" << endl;
    cout << "|------------------------|" << endl;
    cout << "| 1. Change Password     |" << endl;
    cout << "| 2. View All Accounts   |" << endl;
    cout << "| 3. Contact Us          |" << endl;
    cout << "| 0. Back to Main Menu   |" << endl;
    cout << "|________________________|" << endl;
}

// Function to contact support
void contactUs() {
    cout << "______________________________" << endl;
    cout << "|     Contact Us             |" << endl;
    cout << "| Email: support@example.com |" << endl;
    cout << "| Phone: 093738333           |" << endl;
    cout << "| Facebook: www.facebook.com |" << endl;
    cout << "|_____________________________" << endl;
}

// Function to view all user accounts
void viewAllAccounts() {
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
}

// Main settings menu
void settingsMenu() {
    int option;
    do {
        MenuSetting();
        cin >> option;
        switch (option) {
            case 1:
                changePassword();
                break;
            case 2:
                viewAllAccounts();
                break;
            case 3:
                contactUs();
                break;
            case 5:
                cout << "Back..." << endl;
                break;
            default:
                cout << "BACk......" << endl;

        }
    } while (option != 0);
}

// Main menu handler
int main() {
    int choice;
    do {
        firstMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                // registerUser();
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
                settingsMenu();
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
