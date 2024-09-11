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

//Function about Product
class Product {
public:
    int id;
    string name;
    float price;
    string description;
    string category;

    Product(int id, const string& name, float price, const string& description, const string& category)
        : id(id), name(name), price(price), description(description), category(category) {}
};

// Function to get the width of the console
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return columns;
}

// Function to print centered text with tabs
void printCenteredWithTabs(const string& text, int consoleWidth) {
    int padding = (consoleWidth - text.length()) / 2;
    int tabs = padding / 8;
    cout << string(tabs, '\t') << text << endl;
}

// Function to format price to two decimal places
string formatPrice(float price) {
    ostringstream oss;
    oss << fixed << setprecision(2) << price;
    return oss.str();
}

// Function to display products by pages
void displayPage(const vector<Product>& products, int pageNumber, int itemsPerPage, int consoleWidth) {
    int start = (pageNumber - 1) * itemsPerPage;
    int end = min(start + itemsPerPage, static_cast<int>(products.size()));

    // Print some newlines before the content for vertical centering
    cout << string(5, '\n');

    if (start >= products.size()) {
        printCenteredWithTabs("Page number out of range.", consoleWidth);
        return;
    }
    

    printCenteredWithTabs("Displaying page " + to_string(pageNumber) + ":", consoleWidth);

    for (int i = start; i < end; ++i) {
        const Product& product = products[i];
        string productInfo = "|ID:" + to_string(product.id) + " | Name: " + product.name +
                             " | Price: $" + formatPrice(product.price) +
                             " | Description: " + product.description +
                             " | Types: " + product.category;
        printCenteredWithTabs(" ____________________________________________________________________________", consoleWidth);
        printCenteredWithTabs(productInfo, consoleWidth);
    }
    cout << endl;
}

// Calculate the total number of pages
int calculateTotalPages(const vector<Product>& products, int itemsPerPage) {
    return (products.size() + itemsPerPage - 1) / itemsPerPage;
}

// Function to search a product by ID
void searchProductById(const vector<Product>& products, int id, int consoleWidth) {
    auto it = find_if(products.begin(), products.end(), [id](const Product& p) { return p.id == id; });
    if (it != products.end()) {
        printCenteredWithTabs("Product found:", consoleWidth);
        string productInfo = "|ID:" + to_string(it->id) + " | Name: " + it->name +
                             " | Price: $" + formatPrice(it->price) +
                             " | Description: " + it->description +
                             " | types: " + it->category;
        printCenteredWithTabs(productInfo, consoleWidth);
    } else {
        printCenteredWithTabs("Product with ID " + to_string(id) + " not found.", consoleWidth);
    }
}

// Function to display products by category
void displayProductsByCategory(const vector<Product>& products, const string& category, int consoleWidth) {
    vector<Product> filteredProducts;
    copy_if(products.begin(), products.end(), back_inserter(filteredProducts),
            [&category](const Product& p) { return p.category == category; });
            

    if (filteredProducts.empty()) {
        printCenteredWithTabs("No products found in category: " + category, consoleWidth);
    } else {
        printCenteredWithTabs("Products in Type: " + category, consoleWidth);
        for (const auto& product : filteredProducts) {
            string productInfo = "|ID:" + to_string(product.id) + " | Name: " + product.name +
                                 "| Price: $" + formatPrice(product.price) +
                                 "| Description: " + product.description +
                                 "| Type :" + product.category;
            printCenteredWithTabs(" ____________________________________________________________________________", consoleWidth);
            printCenteredWithTabs(productInfo, consoleWidth);
        }
    }
}

void product(){
    vector<Product> products = {
        {1, "Banana", 0.3, "A healthy fruit.", "fruit"},
        {2, "Orange", 0.5, "A sweet fruit.", "fruit"},
        {3, "Mango", 1, "A tropical fruit.", "fruit"},
        {4, "Pineapple", 1.6, "A juicy fruit.", "fruit"},
        {5, "Coconut", 1.5, "Sweet water.", "drink"},
        {6, "Avocado", 1, "Yummy and sweet.", "fruit"},
        {7, "Papaya", 1.5, "Sweet.", "fruit"},
        {8, "Kiwi", 0.7, "Juicy fruit.", "fruit"},
        {9, "Apple", 0.8, "Sweet and fragile.", "fruit"},
        {10, "Plum", 0.5, "Juicy and sweet.", "fruit"},
        {11, "Sting", 0.5, "Energy drink.", "drink"},
        {12, "Karabav", 0.5, "Energy drink.", "drink"},
        {13, "Red-bull", 0.5, "Energy drink.", "drink"},
        {14, "Monster", 2, "Energy drink.", "drink"},
        {15, "Pepsi", 0.5, "Soft drink.", "drink"},
        {16, "Sprite", 0.5, "Soft drink.", "drink"},
        {17, "Water", 0.3, "Healthy drink.", "drink"},
        {18, "Kit-Kat", 1, "Snack.", "Snack"},
        {19, "Chocolate", 2, "Snack.", "Snack"},
        {20, "Brownie", 1, "Snack.", "snack"},
        {21, "beer", 2, "drink.", "drink"},
        {32, "Hotdog", 1, "snack.", "snack"},
        {33,"chip", 1  , "snack.", "snack"},
        {34,"chees", 2  , "snack.", "snack"},
        {35,"fries", 1  , "snack.", "snack"},
    };
    int itemsPerPage = 5;
    int totalPages = calculateTotalPages(products, itemsPerPage);
    int currentPage = 1;
    int consoleWidth = getConsoleWidth();
    while (true) {
        system("cls"); // Clear the console screen
        displayPage(products, currentPage, itemsPerPage, consoleWidth);
         printCenteredWithTabs("Page " + to_string(currentPage) + " of " + to_string(totalPages), consoleWidth);
         printCenteredWithTabs("Enter |n| for next page.\t\t\t", consoleWidth);
         printCenteredWithTabs("Enter |p| for previous page.\t\t\t", consoleWidth);
         printCenteredWithTabs("Enter |c| search by types.\t\t\t", consoleWidth);
         printCenteredWithTabs("Enter |q| to quit.\t\t\t\t\t\t\t\t\t\t\t\t", consoleWidth);
        char command;
        cout<<"\t\tEnter option :";cin >> command;
        
        if (command == 'n') {
            if (currentPage < totalPages) {
                currentPage++;
            } else {
                printCenteredWithTabs("You are on the last page.", consoleWidth);
                system("pause");
            }
        } else if (command == 'p') {
            if (currentPage > 1) {
                currentPage--;
            } else {
                printCenteredWithTabs("You are on the first page.", consoleWidth);
                system("pause");
            }
        } else if (command == 'c') {
            string category;
            cout << "Enter Type of products: ";
            cin.ignore();
            getline(cin, category);
            system("cls");
            displayProductsByCategory(products, category, consoleWidth);
            system("pause");
        } else if (command == 'q') {
            break;
        } else {
            printCenteredWithTabs("Invalid command.", consoleWidth);
            system("pause");
        }
    }
}

void usercontrol(){
    int choice ;
        do {
        firstMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                // registerUser();
                loginRegisterUser();
                break;
            case 2:
                product();
                
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


}

void admin() {
    string nameadmin, passwordAdmin;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, nameadmin);
    cout << "Enter your password: ";
    getline(cin, passwordAdmin);

    if (nameadmin == "admin" && passwordAdmin == "admin123") {
        cout << "Welcome, Admin!" << endl;
        int adminChoice;
        do {
            cout << "===========================" << endl;
            cout << "        ADMIN CONTROL      " << endl;
            cout << "===========================" << endl;
            cout << " 1. View All User Account  " << endl;
            cout << " 2. Manage Product         " << endl;
            cout << " 4. Logout                 " << endl;
            cout << "===========================" << endl;
            cout << "Enter your choice: ";
            cin >> adminChoice;

            switch (adminChoice) {
                case 1:
                    // viewAllUserAccount(); (Assuming this function exists)
                    cout << "Displaying all user accounts..." << endl;
                    break;
                case 2: {
                    int productChoice;
                    cout << "===========================" << endl;
                    cout << "       Manage Product!     " << endl;
                    cout << "===========================" << endl;
                    cout << " 1. Add Product            " << endl;
                    cout << " 2. Update Product         " << endl;
                    cout << " 3. Delete Product         " << endl;
                    cout << " 4. Logout                 " << endl;
                    cout << "===========================" << endl;
                    cout << "Enter your choice: ";
                    cin >> productChoice;

                    switch (productChoice) {
                        case 1:
                            // addProduct(); (Assuming this function exists)
                            cout << "Adding product..." << endl;
                            break;
                        case 2:
                            // updateProduct(); (Assuming this function exists)
                            cout << "Updating product..." << endl;
                            break;
                        case 3:
                            // deleteProduct(); (Assuming this function exists)
                            cout << "Deleting product..." << endl;
                            break;
                        case 4:
                            cout << "Logout successful!" << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again!" << endl;
                    }
                    break;
                }
                case 4:
                    cout << "Logout successful!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again!" << endl;
            }
        } while (adminChoice != 4); // The loop continues until the admin chooses to logout
    } else {
        cout << "Invalid admin credentials. Please try again!" << endl;
    }
}

// Main menu handler
int main() {
    int option;
    cout << "Admin Orr User "<<endl;
    cout << " 1.Admin " <<endl;
    cout << " 2.User " << endl;
    cout << " 0. Exit " << endl;
    cout << "Enter your choice: ";
    cin >> option;
    switch (option) {
        case 1:
            
            break;
        case 2:
            usercontrol();
            break;
        case 0:
            cout << "Exiting the program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again!" << endl;
    }
    
    return 0;   
}
