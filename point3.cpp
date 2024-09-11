#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iomanip> // For formatting output
#include <windows.h> // For Windows-specific console manipulation

using namespace std;

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
                             " | Category: " + product.category;
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
                             " | Category: " + it->category;
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
                                 "| Type " + product.category;
            printCenteredWithTabs(" ____________________________________________________________________________", consoleWidth);
            printCenteredWithTabs(productInfo, consoleWidth);
        }
    }
}
int main() {
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
        printCenteredWithTabs("Enter |n| for next page\t\t\t", consoleWidth);
        printCenteredWithTabs("Enter |p| for previous page\t\t\t", consoleWidth);
        printCenteredWithTabs("Enter |c| search by type\t\t\t", consoleWidth);
        printCenteredWithTabs("Enter |q| to quit\t\t\t\t\t\t\t\t\t\t\t\t", consoleWidth);
        char command;
        cin >> command;
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

    return 0;
}
