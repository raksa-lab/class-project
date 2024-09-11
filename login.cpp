#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

struct User {
    string username;
    string password;
};

// Global vector to store user data
vector<User> users;

// void clearScreen() {
// #ifdef _WIN32
//     system("cls");
// #else
//     system("clear");
// #endif
// }

// Function to display the main menu
void firstMenu() {
  
    cout << "=====================================================================================================================================" << endl;
    cout << "                                   1. Login                                                                                          " << endl;
    cout << "                                   2. List all Products                                                                              " << endl;
    cout << "                                   3. Add Products to Cart                                                                           " << endl;
    cout << "                                   4. Order Product                                                                                  " << endl;
    cout << "                                   5. Setting                                                                                        " << endl;
    cout << "                                   0. Exit                                                                                           " << endl;
    cout << "=====================================================================================================================================" << endl;
    cout << "Please Enter Your Choice: ";
}

// Function to register a new user
void registerUser() {
    
    cout << "                      [+1]. Register Account               " << endl;
    string username, userPassword;
    cout << "         USERNAME: ";
    cin >> username;
    cout << "         PASSWORD: ";
    cin >> userPassword;

    // Check if user already exists
    for (const auto& user : users) {
        if (user.username == username) {
            cout << "Username already exists. Please try a different username." << endl;
            return;
        }
    }

    // Add new user to vector
    users.push_back({username, userPassword});
    cout << "......................................................" << endl;
    cout << " You completed your Account Successfully. " << endl;
}

// Function to log in a user
void login() {
    
    string username, userPassword;
    cout << "                 [+2]. Login Account                                     " << endl;
    cout << "           USERNAME:                     ";
    cin >> username;
    cout << "           PASSWORD:                     ";
    cin >> userPassword;

    bool found = false;
    for (const auto& user : users) {
        if (user.username == username && user.password == userPassword) {
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

// Function to handle forgotten passwords
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

void MenuSetting(){
    cout << "_________________________|" << endl;
    cout << "|      User Setting      |" << endl;
    cout << "|------------------------|" << endl;
    cout << "| 1. View Account        |" << endl;
    cout << "| 2. Contact Us          |" << endl;
    cout << "| 3. Change Password     |" << endl;
    cout << "| 4. Add New Account     |" << endl;
    cout << "| 5. View All Accounts   |" << endl;
    cout << "| 6. Log Out             |" << endl;
    cout << "|________________________|" << endl;    
}
class Setting {
    public :
        string newpassword;

    void viewAcc(){

    }
    void contactus(){
        cout << "______________________________" << endl;
        cout << "|     Contact Us             |" << endl;
        cout << "| Email: weffefeof@gmail.com |" << endl;
        cout << "| Phone: 093738333           |" << endl;
        cout << "| Facebook: www.facebook.com |" << endl;
        cout << "|_____________________________" << endl;        
    }
};

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
                // Settings functionality (not implemented)
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
