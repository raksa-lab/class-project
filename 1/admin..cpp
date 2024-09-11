 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
};

struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

vector<User> users;
vector<Product> products;

void adminMenu();
void updateProduct();

void addProduct() {
    Product newProduct;
    cout<<"----------------------------------"<<endl;
    cout<<" Enter product Id:   ";
    cin>>newProduct.id;
    cout << "Enter Product Name: ";
    cin >> newProduct.name;
    cout << "Enter Product Price: ";
    cin >> newProduct.price;
    cout << "Enter Product Quantity: ";
    cin >> newProduct.quantity;

    products.push_back(newProduct);
    cout << "Product added successfully! "<<endl;
    adminMenu();
}

void viewProducts() {
    if (products.empty()) {
        cout << "No products available ." << endl;
    } else {
        for (size_t i = 0; i < products.size(); ++i) {
            cout  << i + 1 <<" | Id: "<< products[i].id 
                << " | Name: " << products[i].name
                 << " | Price: $" << products[i].price
                 << " | Quantity: " << products[i].quantity << endl;
        }
    }
}

void removeProduct() {
    viewProducts();
    if (!products.empty()) {
        int productNumber;
        cout << "Enter the product number to remove: ";
        cin >> productNumber;

        if (productNumber > 0 && productNumber <= products.size()) {
            products.erase(products.begin() + (productNumber - 1));
            cout << "Product removed successfully."<<endl;
        } else {
            cout << "Invalid product number.\n";
        }
    }
    adminMenu();
}

void updateProduct() {
    viewProducts();
    if (!products.empty()) {
        int productNumber;
        cout << "Enter the product number to update: ";
        cin >> productNumber;

        if (productNumber > 0 && productNumber <= products.size()) {
            Product &selectedProduct = products[productNumber - 1];
            int choice;
            
            cout << "Which detail would you like to update?"<<endl;
            cout <<" 1. Id      "<<endl;
            cout << "2. Name    "<<endl;
            cout << "3. Price   "<<endl;
            cout << "4. Quantity"<<endl;
            cout<<"+------------------------+"<<endl;
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    cout<<"Enter new Id: ";
                    cin>>selectedProduct.id;
                    cout << "Product Id updated successfully!"<<endl;
                case 2:
                    cout << "Enter new name: ";
                    cin >> selectedProduct.name;
                    cout << "Product name updated successfully!"<<endl;
                    break;
                case 3:
                    cout << "Enter new price: ";
                    cin >> selectedProduct.price;
                    cout << "Product price updated successfully!"<<endl;
                    break;
                case 4:
                    cout << "Enter new quantity: ";
                    cin >> selectedProduct.quantity;
                    cout << "Product quantity updated successfully!"<<endl;
                    break;
                default:
                    cout << "Invalid option!"<<endl;
                    break;
            }
        } else {
            cout << "Invalid product number."<<endl;
        }
    }
    adminMenu();
}


void adminMenu() {
    int choice;
    cout<<"------------------- Admin Menu --------------------------"<<endl;
    cout<<"                  1. Add Product                         "<<endl;
    cout<<"                  2. View Products                       "<<endl;
    cout<<"                  3. Remove Product                      "<<endl;
    cout<<"                  4. Update Product                      "<<endl;
    cout<<"                  0. Logout                              "<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: addProduct(); 
        break;
        case 2: viewProducts(); 
        adminMenu(); 
        break;
        case 3: 
        removeProduct(); 
        break;
        case 4: 
        updateProduct(); 
        break;
        case 0: 
        cout << "Logging out.........."<<endl; 
        break;
        default: 
        cout << "Invalid option!........"<<endl; 
        adminMenu();
    }
}

void adminLogin() {
    string inputUsername, inputPassword;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"+               E-Commerce System                   +"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    cout << "Admin Username:       "; 
    cin >> inputUsername;
    cout << "Admin Password:       ";
     cin >> inputPassword;

    if (inputUsername == "teamkitty" && inputPassword == "kitty168") {
        cout << "Admin login successful!"<<endl;
        adminMenu();
    } else {
        cout << "Please try again";
    }
}

int main() {
    adminLogin();
    return 0;
}
