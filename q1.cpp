/*
Name: Azmar Kashif
Section: B
Roll no: 22i-2716
*/
#include<iostream>
#include<iomanip>
using namespace std;

class Product{
    protected:
    string name;
    int IdNum;
    int Quantity;
    double Price;
    string SuppliedFrom;
    public:
/*
Default Constructor
*/
    Product(){
        name = "";
        IdNum = 0;
        Quantity = 0;
        Price = 0.0;
        SuppliedFrom = "";
    }
/*
parametized Constructor
*/
    Product(string name, int IdNum, int Quantity, double Price, string SuppliedFrom){
        this-> name = name;
        this-> IdNum = IdNum;
        this-> Quantity = Quantity;
        this-> Price = Price;
        this-> SuppliedFrom = SuppliedFrom;
    }
/*
getter setters
*/
    string getName(){
        return name;
    }
    int getIdNum(){
        return IdNum;
    }
    void setQuantity(int newQuant){
        Quantity = newQuant;
    }
    int getQuantity(){
        return Quantity;
    }
    double getPrice(){
        return Price;
    }
    string getSuppliedFrom(){
        return SuppliedFrom;
    }
};
class ProductForCustomer {
protected:
    string name;
    int quantity;
    int price;
public:
    ProductForCustomer(string n, int q, int p) : name(n), quantity(q), price(p) {}
    int getQuantity() const { return quantity; }
    int getPrice() const { return price; }
    void setQuantity(int q) { quantity = q; }
};
class Receipt {
private:
    string name;
    int category;
    int quantity;
    int price;
    string category_name;
public:
    Receipt(string name, int category, int quantity, int price, string category_name) {
        this->name = name;
        this->category = category;
        this->quantity = quantity;
        this->price = price;
        this->category_name = category_name;
    }
    void print() {
        cout << "--------------------------" << endl;
        cout << "         Receipt          " << endl;
        cout << "--------------------------" << endl;
        cout << setw(20) << left << "Product name:" << setw(10) << right << name << endl;
        cout << setw(20) << left << "Category:" << setw(10) << right << category_name << endl;
        cout << setw(20) << left << "Quantity:" << setw(10) << right << quantity << endl;
        cout << setw(20) << left << "Total Price:" << setw(10) << right << price << " $" << endl;
        cout << "--------------------------" << endl;
        }
    };

class Clothes : public ProductForCustomer {
public:
    Clothes() : ProductForCustomer("Clothes", 0, 0) {} // Constructor that initializes the name, quantity and price of the product
    void buy(int ch) {
        int c;
        int remPants;
        cout << "What do you wanna buy: " << endl;
        cout << "1. Pants" << endl;
        cout << "2. Shirts" << endl;
        cin >> c;
        int q, bill = 0, P_price = 15, S_price = 20; // Initialize the quantity, bill and prices for pants and shirts
        if(c == 1) { // Buy pants
            int pants = 50; // Initialize the quantity of pants in stock
            char c = 'y'; // Initialize the character to keep asking the user if they want to buy more pants
            while (pants > 0 && c == 'y') { // Keep asking the user until they don't want to buy anymore or we run out of stock
                cout << "Enter the quantity for pants: ";
                cin >> q; // Get the quantity of pants the user wants to buy
                if (q > pants) { // Check if we have enough pants in stock
                    cout << "Sorry, we don't have enough pants in stock." << endl;
                    continue; // If not, ask again
                }
                bill += q * P_price; // Add the price of the pants to the bill
                remPants = pants - q;
                pants -= q; // Reduce the quantity of pants in stock
                if (pants > 0) { // If we have more pants in stock, ask the user if they want to buy more
                    cout << "Want more? (y/n) ";
                    cin >> c;
                } else {
                    cout << "Sorry, we are out of stock for pants." << endl; // If not, inform the user that we are out of stock
                }
            }
            if(bill > 50) { // If the bill is more than $50, give a 10% discount
                cout << "You got a 10% discount!" << endl;
                bill -= bill / 10;
            }
            setQuantity(getQuantity() + q); // Update the quantity of the product
            Receipt r("Pants", 1, q, bill, "Clothes");
            r.print(); // Print the receipt
        } else if(c == 2) { // Buy shirts
            int shirts = 50; // Initialize the quantity of shirts in stock
            char c = 'y'; // Initialize the character to keep asking the user if they want to buy more shirts
            while (shirts > 0 && c == 'y') { // Keep asking the user until they don't want to buy anymore or we run out of stock
                cout << "Enter the quantity for shirts: ";
                cin >> q; // Get the quantity of shirts the user wants to buy
                if (q > shirts) { // Check if we have enough shirts in stock
                    cout << "Sorry, we don't have enough shirts in stock." << endl;
                    continue; // If not, ask again
                }
                bill += q * S_price; // Add the price of the shirts to the bill
                shirts -= q; // Reduce the quantity of shirts in stock
                if (shirts > 0) { // If we have more shirts in stock, ask the user if they want to buy more
                    cout << "Want more? (y/n) ";
                    cin >> c;
                } else {
                    cout << "Sorry, we are out of stock for shirts." << endl; // If not, inform the user that we are out of stock

                }
            }
            if(bill > 100) {
                cout << "You got a 20% discount!" << endl;
                bill -= bill / 5;
            }
            setQuantity(getQuantity() + q);
            Receipt r("Shirts", 1, q, bill, "Clothes");
            r.print();
        }
    }
};
class Fruit : public ProductForCustomer {
public:
    Fruit() : ProductForCustomer("Fruit", 0, 0) {}
    // This function allows the customer to buy the fruit product
// The function takes an integer argument "ch" which represents the fruit choice
// 1 - Apples, 2 - Oranges, 3 - Bananas
void buy(int ch) {
    int c;
    cout << "What do you wanna buy: " << endl;
    cout << "1. Apples " << endl;
    cout << "2. Oranges " << endl;
    cout << "3. Mangoes " << endl;
    cin >> c;
    // Initialize quantity, bill and prices for each fruit
    int q, bill = 0, A_price = 1, O_price = 2, B_price = 3;

    // Buy apples
    if(c == 1) {
        int apples = 50; // Initialize the stock for apples
        char c = 'y'; // Initialize choice for buying more apples
        while (apples > 0 && c == 'y') {
            cout << "Enter the quantity for apples: ";
            cin >> q;
            if (q > apples) {
                cout << "Sorry, we don't have enough apples in stock." << endl;
                continue; // Go back to the start of the while loop if the input quantity is greater than the stock
            }
            bill += q * A_price;
            apples -= q;
            if (apples > 0) {
                cout << "Want more? (y/n) ";
                cin >> c;
            } else {
                cout << "Sorry, we are out of stock for apples." << endl;
            }
        }
        // Apply discount if the bill is above $10
        if(bill > 10) {
            cout << "You got a 5% discount!" << endl;
            bill -= bill / 20;
        }
        // Update the quantity of fruit product in the cart and set the price for the current purchase
        setQuantity(getQuantity() + q);
        // Print the receipt for the current purchase
        Receipt r("Apples", 2, q, bill, "Fruits");
        r.print();
    } 
    // Buy oranges
    else if(c == 2) {
        int oranges = 50; // Initialize the stock for oranges
        char c = 'y'; // Initialize choice for buying more oranges
        while (oranges > 0 && c == 'y') {
            cout << "Enter the quantity for oranges: ";
            cin >> q;
            if (q > oranges) {
                cout << "Sorry, we don't have enough oranges in stock." << endl;
                continue; // Go back to the start of the while loop if the input quantity is greater than the stock
            }
            bill += q * O_price;
            oranges -= q;
            if (oranges > 0) {
                cout << "Want more? (y/n) ";
                cin >> c;
            } else {
                cout << "Sorry, we are out of stock for oranges." << endl;
            }
        }
        // Apply discount if the bill is above $15
        if(bill > 15) {
            cout << "You got a 10% discount!" << endl;
            bill -= bill / 10;
        }
        // Update the quantity of fruit product in the cart and set the price for the current purchase
        setQuantity(getQuantity() + q);
        // Print the receipt for the current purchase
            Receipt r("Mangoes", 2, q, bill, "Fruits");
            r.print();
        }else if(c == 3){
            int Mangoes = 50; // Initialize the stock for oranges
        char c = 'y'; // Initialize choice for buying more oranges
        while (Mangoes > 0 && c == 'y') {
            cout << "Enter the quantity for Mangoes: ";
            cin >> q;
            if (q > Mangoes) {
                cout << "Sorry, we don't have enough Mangoes in stock." << endl;
                continue; // Go back to the start of the while loop if the input quantity is greater than the stock
            }
            bill += q * O_price;
            Mangoes -= q;
            if (Mangoes > 0) {
                cout << "Want more? (y/n) ";
                cin >> c;
            } else {
                cout << "Sorry, we are out of stock for Mangoes." << endl;
            }
        }
        // Apply discount if the bill is above $15
        if(bill > 15) {
            cout << "You got a 10% discount!" << endl;
            bill -= bill / 10;
        }
        // Update the quantity of fruit product in the cart and set the price for the current purchase
        setQuantity(getQuantity() + q);
        // Print the receipt for the current purchase
            Receipt r("Mangoes", 2, q, bill, "Fruits");
            r.print();
        }
    }
};
class Vegetable : public ProductForCustomer {
public:
    Vegetable() : ProductForCustomer("Vegetable", 0, 0) {}
    // This function allows a customer to buy vegetables.
void buy(int ch) {
    int c;
    int q, bill = 0, P_price = 10, T_price = 15, O_price = 5;
    cout << "What do you wanna buy " << endl;
    cout << "1. Potatoes " << endl;
    cout << "2. Tomatoes " << endl;
    cout << "3. Onions " << endl;
    cin >> c;
    // If the customer chooses potatoes (ch = 1).
    if(c == 1) {
        int potatoes = 50;
        char c = 'y';
        // Keep asking for the quantity until the customer says no or there's no more potatoes left in stock.
        while (potatoes > 0 && c == 'y') {
            cout << "Enter the quantity for potatoes: ";
            cin >> q;
            if (q > potatoes) {
                cout << "Sorry, we don't have enough potatoes in stock." << endl;
                continue;
            }
            bill += q * P_price;
            potatoes -= q;
            if (potatoes > 0) {
                cout << "Want more? (y/n) ";
                cin >> c;
            } else {
                cout << "Sorry, we are out of stock for potatoes." << endl;
            }
        }
        // If the bill is greater than 50, the customer gets a 10% discount.
        if(bill > 50) {
            cout << "You got a 10% discount!" << endl;
            bill -= bill / 10;
        }
        // Add the quantity purchased to the quantity of the product in the store.
        setQuantity(getQuantity() + q);
        // Create a receipt and print it.
        Receipt r("Potatoes", 2, q, bill, "Vegetables");
        r.print();
    } 
    
    // If the customer chooses tomatoes (ch = 2).
    else if(c == 2) {
        int tomatoes = 50;
        char c = 'y';
        // Keep asking for the quantity until the customer says no or there's no more tomatoes left in stock.
        while (tomatoes > 0 && c == 'y') {
            cout << "Enter the quantity for tomatoes: ";
            cin >> q;
            if (q > tomatoes) {
                cout << "Sorry, we don't have enough tomatoes in stock." << endl;
                continue;
            }
            bill += q * T_price;
            tomatoes -= q;
            if (tomatoes > 0) {
                cout << "Want more? (y/n) ";
                cin >> c;
            } else {
                cout << "Sorry, we are out of stock for tomatoes." << endl;
            }
        }
        // If the bill is greater than 100, the customer gets a 20% discount.
        if(bill > 100) {
            cout << "You got a 20% discount!" << endl;
            bill -= bill / 5;
        }
        // Add the quantity purchased to the quantity of the product in the store.
        setQuantity(getQuantity() + q);
        // Create a receipt and print it.
        Receipt r("Tomatoes", 2, q, bill, "Vegetables");
        r.print();
    }
    else if (c == 3) { // If user selects option 3, which is buying onions
        int onions = 50; // Initialize the quantity of onions in stock
        char c = 'y'; // Initialize the character for user input
        while (onions > 0 && c == 'y') { // Loop until there are onions in stock and user wants to buy more
            cout << "Enter the quantity for onions: ";
            cin >> q; // Read the quantity of onions from the user
            if (q > onions) { // If the user enters a quantity greater than available in stock
                cout << "Sorry, we don't have enough onions in stock." << endl;
                continue; // Prompt the user again to enter the correct quantity
            }
            bill += q * O_price; // Calculate the cost of onions purchased
            onions -= q; // Reduce the quantity of onions in stock
            if (onions > 0) { // If there are still onions in stock
                cout << "Want more? (y/n) ";
                cin >> c; // Ask user if they want to buy more onions
            } else { // If there are no onions left in stock
                cout << "Sorry, we are out of stock for onions." << endl;
            }
        }
        if (bill > 75) { // If the bill amount is greater than 75$
            cout << "You got a 15% discount!" << endl;
            bill -= bill / 7; // Apply 15% discount
        }
        setQuantity(getQuantity() + q); // Add the quantity of onions purchased to the cart
        Receipt r("Onions", 2, q, bill, "Vegetables"); // Create a receipt object for onions purchased
        r.print(); // Print the receipt
        }
    }
};

class Products {
private:
    string name;
    int quantity;
    int price;
    string supplier;
public:
    Products(){};
    Products(string n, int q, int p, string s) : name(n), quantity(q), price(p), supplier(s) {}
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    void setQuantity(int q) { quantity = q; }
    int getPrice() const { return price; }
    string getSupplier() const { return supplier; }
};

class Inventory {
private:
    Products* products;
    int size;
public:
    Inventory(int s) : size(s) {
        products = new Products[size];
    }
    ~Inventory() {
        delete[] products;
    }
    void addProduct(Products p, int i) {
        products[i] = p;
    }
    void checkInventory() {
        for (int i = 0; i < size; i++) {
            if (products[i].getQuantity() < 100) {
                cout << products[i].getName() << " is out of stock or has low inventory." << endl;
                orderFromSupplier(products[i]);
            } else {
                cout << products[i].getName() << " is in stock with quantity " << products[i].getQuantity() << endl;
            }
        }
    }
    void orderFromSupplier(Products p) {
        cout << "Contacting supplier " << p.getSupplier() << " to order more " << p.getName() << endl;
        // code to contact supplier and place order
        // ...
        p.setQuantity(p.getQuantity() + 100); // assume we ordered 100 more units
        cout << "Received " << p.getName() << " from supplier. New quantity is " << p.getQuantity() << endl;
    }
};
class SalesReport {
    private:
    const int m_numProducts = 5;
    const int m_numDays = 7;
    const int m_numCustomers = 3;
    double* m_productSales;
    double* m_daySales;
    double* m_customerSales;
public:
    SalesReport(double* productSales, double* daySales, double* customerSales) :
        m_productSales(productSales),
        m_daySales(daySales),
        m_customerSales(customerSales)
    {}

    // Displays the sales for each product.
    void viewSalesByProduct() const {
        cout << "Sales by product:" << endl;
        for (int i = 0; i < m_numProducts; i++) {
            cout << "Product " << (i + 1) << ": $" << m_productSales[i] << endl;
        }
    }

    // Displays the sales for each day.
    void viewSalesByDay() const {
        cout << "Sales by day:" << endl;
        for (int i = 0; i < m_numDays; i++) {
            cout << "Day " << (i + 1) << ": $" << m_daySales[i] << endl;
        }
    }

    // Displays the sales for each customer.
    void viewSalesByCustomer() const {
        cout << "Sales by customer:" << endl;
        for (int i = 0; i < m_numCustomers; i++) {
            cout << "Customer " << (i + 1) << ": $" << m_customerSales[i] << endl;
        }
    }
};

class InventoryReport {
    // Number of products, locations, and suppliers are constant and initialized to specific values
    const int m_numProducts = 5;
    const int m_numLocations = 3;
    const int m_numSuppliers = 2;
    
    // Pointers to arrays holding inventory data for products, locations, and suppliers
    int* m_productInventory;
    int* m_locationInventory;
    int* m_supplierInventory;
    
public:
    // Constructor takes pointers to arrays holding inventory data and initializes member variables
    InventoryReport(int* productInventory, int* locationInventory, int* supplierInventory) :
        m_productInventory(productInventory),
        m_locationInventory(locationInventory),
        m_supplierInventory(supplierInventory)
    {}

    // Displays inventory data by product
    void viewInventoryByProduct() const {
        cout << "Inventory by product:" << endl;
        for (int i = 0; i < m_numProducts; i++) {
            cout << "Product " << (i + 1) << ": " << m_productInventory[i] << endl;
        }
    }

    // Displays inventory data by location
    void viewInventoryByLocation() const {
        cout << "Inventory by location:" << endl;
        for (int i = 0; i < m_numLocations; i++) {
            cout << "Location " << (i + 1) << ": " << m_locationInventory[i] << endl;
        }
    }

    // Displays inventory data by supplier
    void viewInventoryBySupplier() const {
        cout << "Inventory by supplier:" << endl;
        for (int i = 0; i < m_numSuppliers; i++) {
            cout << "Supplier " << (i + 1) << ": " << m_supplierInventory[i] << endl;
        }
    }
};


class ProfitReport {
    const int m_numProducts = 5;
    const int m_numDays = 7;
    const int m_numCustomers = 3;
    double* m_productProfits; // pointer to an array of product profits
    double* m_dayProfits; // pointer to an array of daily profits
    double* m_customerProfits; // pointer to an array of customer profits
public:
    // constructor that takes pointers to arrays of product, day, and customer profits
    ProfitReport(double* productProfits, double* dayProfits, double* customerProfits) :
        m_productProfits(productProfits),
        m_dayProfits(dayProfits),
        m_customerProfits(customerProfits)
    {}

    // prints the profits by product, using the m_productProfits array
    void viewProfitsByProduct() const {
        cout << "Profits by product:" << endl;
        for (int i = 0; i < m_numProducts; i++) {
            cout << "Product " << (i + 1) << ": $" << m_productProfits[i] << endl;
        }
    }

    // prints the profits by day, using the m_dayProfits array
    void viewProfitsByDay() const {
        cout << "Profits by day:" << endl;
        for (int i = 0; i < m_numDays; i++) {
            cout << "Day " << (i + 1) << ": $" << m_dayProfits[i] << endl;
        }
    }

    // prints the profits by customer, using the m_customerProfits array
    void viewProfitsByCustomer() const {
        cout << "Profits by customer:" <<endl;
        for (int i = 0; i < m_numCustomers; i++) {
            cout << "Customer " << (i + 1) << ": $" << m_customerProfits[i] << endl;
        }
    }
};

int main() {
    int choice;
    cout << string(65, '*') << endl;
    cout << setw(40) << "WELCOME TO OUR STORE" << setw(30) << "" << endl;
    cout << string(65, '*') << endl;
    cout << setw(29) << "1. Customer" << setw(35) << "|" << endl;
    cout << string(65, '-') << endl;
    cout << setw(29) << "2. Sales Man" << setw(35) << "|" << endl;
    cout << string(65, '-') << endl;
    cout << setw(29) << "3. Exit" << setw(35) << "|" << endl;
    cout << string(65, '*') << endl;
    cin >> choice;
    if(choice == 1){
        // Products p;
    while(1){
        int ch;
        cout << "Enter what kind of products you wanna buy " << endl;
        cout << "1.Clothes" <<endl;
        cout << "=>In Clothes we have " << endl;
        cout << "   ->Pants" << endl;
        cout << "   ->Shirts" << endl;
        cout << "2.Fruits" <<endl;
        cout << "=>In Fruits we have " << endl;
        cout << "   ->Apples" << endl;
        cout << "   ->Oranges" << endl;
        cout << "   ->Bananas" << endl;
        cout << "3.Vegetables" <<endl;
        cout << "=>In Vegetables we have " << endl;
        cout << "   ->Potatoes" << endl;
        cout << "   ->Tomatoes" << endl;
        cout << "   ->Onions" << endl;

        cin >> ch;
        if(ch == 1){
            Clothes c;
            c.buy(ch);
        }
        else if(ch == 2){
            Fruit f;
            f.buy(ch);
        }
        else if(ch == 3){
            Vegetable v;
            v.buy(ch);
        }
        else {
            cout << "Invalid Input! Terminating the program " << endl; 
        }
    }
    }else if(choice == 2){
        int s;
        cout << "Enter the size for inventory: ";
        cin >> s;
        cout << "The total size for inventory is " << s << endl;
        while(1){
            int choice;
            Inventory i(s);
            cout << "What do you wanna check in the store?" << endl;
            cout << "1. Want to add products to inventory? " << endl;
            cout << "2. Want to check inventory to check for the products? " << endl;
            cout << "3. Want to contact the supplier for the missing products? " << endl;
            cout << "4. Do you want to check the record for sales and profits? " << endl;
            cin >> choice;
            if(choice == 1){
                int ch;
                cout << "What kind of products you wanna add to store: " << endl;
                cout << "1.   ->Apples" << endl;
                cout << "2.   ->Orange" << endl;
                cout << "3.   ->Banana" << endl;
                cin >> ch;
                if(ch == 1){
                    int inv;
                    cout << "Now enter the inventory number where you want to place apples: ";
                    cin >> inv;
                    Products apple("Apple", 50, inv, "");
                    i.addProduct(apple, inv);
                    cout << "You placed apples at inventory " << inv << endl;
                }else if(ch == 2){
                    int inv;
                    cout << "Now enter the inventory number where you want to place Orange: ";
                    cin >> inv;
                    Products Orange("Orange", 50, inv, "");
                    i.addProduct(Orange, inv);
                    cout << "You placed Orange at inventory " << inv << endl;
                }else if(ch == 3){
                    int inv;
                    cout << "Now enter the inventory number where you want to place Banana: ";
                    cin >> inv;
                    Products Banana("Banana", 50, inv, "");
                    i.addProduct(Banana, inv);
                    cout << "You placed Banana at inventory " << inv << endl;
                }
            }else if(choice == 2){
                i.checkInventory();
            }else if(choice == 3){
                int ch;
                cout << "For which product you want to contact supplier: " << endl;
                cout << "1.   ->Apples" << endl;
                cout << "2.   ->Orange" << endl;
                cout << "3.   ->Banana" << endl;
                cin >> ch;
                char supp;
                if(ch == 1){
                    cout << "Which Supplier you want to contact for Apples: " << endl;
                    cout << "A" << endl;
                    cout << "B" << endl;
                    cout << "C" << endl;
                    cin >> supp;
                    if(supp == 'a' || supp == 'A'){
                        cout << "You have contacted the supplier " << supp << " for apples " << endl;
                    }else if(supp == 'b' || supp == 'B'){
                        cout << "You have contacted the supplier " << supp << " for apples " << endl;
                    }else if(supp == 'c' || supp == 'C'){
                        cout << "You have contacted the supplier " << supp << " for apples " << endl;
                    }
                }else if(ch == 2){
                    cout << "Which Supplier you want to contact for Oranges: " << endl;
                    cout << "A" << endl;
                    cout << "B" << endl;
                    cout << "C" << endl;
                    cin >> supp;
                    if(supp == 'a' || supp == 'A'){
                        cout << "You have contacted the supplier " << supp << " for Oranges " << endl;
                    }else if(supp == 'b' || supp == 'B'){
                        cout << "You have contacted the supplier " << supp << " for Oranges " << endl;
                    }else if(supp == 'c' || supp == 'C'){
                        cout << "You have contacted the supplier " << supp << " for Oranges " << endl;
                    }
                }else if(ch == 3){
                    cout << "Which Supplier you want to contact for Bananas: " << endl;
                    cout << "A" << endl;
                    cout << "B" << endl;
                    cout << "C" << endl;
                    cin >> supp;
                    if(supp == 'a' || supp == 'A'){
                        cout << "You have contacted the supplier " << supp << " for Bananas " << endl;
                    }else if(supp == 'b' || supp == 'B'){
                        cout << "You have contacted the supplier " << supp << " for Bananas " << endl;
                    }else if(supp == 'c' || supp == 'C'){
                        cout << "You have contacted the supplier " << supp << " for Bananas " << endl;
                    }
                }
            }
            else if(choice == 4){
                double productSales[5] = {100, 200, 300, 400, 500};
                double daySales[7] = {1000, 2000, 3000, 4000, 5000, 6000, 7000};
                double customerSales[3] = {10000, 20000, 30000};
                SalesReport salesReport(productSales, daySales, customerSales);

                int productInventory[5] = {10, 20, 30, 40, 50};
                int locationInventory[3] = {100, 200, 300};
                int supplierInventory[2] = {1000, 2000};
                InventoryReport inventoryReport(productInventory, locationInventory, supplierInventory);

                double productProfits[5] = {50, 100, 150, 200, 250};
                double dayProfits[7] = {500, 1000, 1500, 2000, 2500, 3000, 3500};
                double customerProfits[3] = {5000, 10000, 15000};
                ProfitReport profitReport(productProfits, dayProfits, customerProfits);

                int choice;
                int ch;
                cout << "Enter 1 to view sales reports, 2 to view inventory reports, or 3 to view profit reports: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "Enter 1 to view sales by product, 2 to view sales by day, or 3 to view sales by customer: ";
                    cin >> ch;

                    if (ch == 1) {
                        salesReport.viewSalesByProduct();
                    } else if (ch == 2) {
                        salesReport.viewSalesByDay();
                    } else if (ch == 3) {
                        salesReport.viewSalesByCustomer();
                    } else {
                        cout << "Invalid choice" << endl;
                    }
                } else if (choice == 2) {
                    cout << "Enter 1 to view inventory by product, 2 to view inventory by location, or 3 to view inventory by supplier: ";
                    cin >> ch;

                    if (ch == 1) {
                        inventoryReport.viewInventoryByProduct();
                    } else if (ch == 2) {
                        inventoryReport.viewInventoryByLocation();
                    } else if (ch == 3) {
                        inventoryReport.viewInventoryBySupplier();
                    } else {
                        cout << "Invalid choice" << endl;
                    }
                } else if (choice == 3) {
                    cout << "Enter 1 to view profits by product, 2 to view profits by day, or 3 to view profits by customer: ";
                    cin >> ch;

                    if (ch == 1) {
                        profitReport.viewProfitsByProduct();
                    } else if (ch == 2) {
                        profitReport.viewProfitsByDay();
                    } else if (ch == 3) {
                        profitReport.viewProfitsByCustomer();
                    } else {
                        cout << "Invalid choice" << endl;
                    }
                } else {
                    cout << "Invalid choice" << endl;
                }
            }
        }
    }else if(choice == 4){
        cout << "Terminating the program. " << endl;
    }
}
