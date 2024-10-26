/******************************************************
** Program: coffee_shop.cpp
** Author: Jinhui zhen
** Date: 11/12/2023
** Description: A coffee shop management system.
** Input: User input for menu interactions and order placements.
** Output: Display of menu, order details, and relevant information.
******************************************************/


#include "shop.h"

using namespace std;

//function defintions from shop.h goes here

//Defulat constructor
Shop::Shop(){
	this->phone = "";
	this->address = "";
	this->revenue = 0.0;
	this->order_arr = nullptr;
	this->num_orders = 0;
}

Shop::Shop(string phone, string address, float revenue, Order *order_arr, int num_orders ){
	this-> phone = phone;
	this-> address = address;
	this-> revenue = revenue;
	this-> order_arr = new Order[num_orders];
	this-> num_orders = num_orders;
}

//CC
Shop::Shop(const Shop &clone) {
    this->phone = clone.phone;
    this->address = clone.address;
    this->revenue = clone.revenue;
    this->num_orders = clone.num_orders;

    this->order_arr = new Order[this->num_orders];
    for (int i = 0; i < this->num_orders; i++){
        this->order_arr[i] = order_arr[i];
    }
}

//AOO
Shop& Shop::operator=(const Shop &clone) {
    if (this != &clone){
        this->phone = clone.phone;
        this->address = clone.address;
        this->revenue = clone.revenue;
        this->num_orders = clone.num_orders;

        delete[] this->order_arr;

        this->order_arr = new Order[this->num_orders];
        for (int i = 0; i < this->num_orders; i++){
            this->order_arr[i] = order_arr[i];
        }
    }
    return *this;
}

//Destrutor
Shop::~Shop(){
	delete[] order_arr;
}

void Shop::load_data(){
	m.populate_menu();
}
/**************************************************
 * Name: view_shop_detail()
 * Description: Displays detailed information about the coffee shop, including menu items,
 *              current orders, and total revenue.
 * Parameters: None
 * Pre-conditions: The Shop object must be instantiated and contain valid data.
 * Post-conditions: The detailed information about the coffee shop is printed to the console.
 ***********************************************/
void Shop::view_shop_detail(){
	ifstream infoFile;
	infoFile.open("shop_info.txt");
	if(infoFile.is_open()){
		getline(infoFile, phone);
		cout << "Phone #: " << phone << endl;
		getline(infoFile, address);
		cout << "Address: " << address << endl;
	}
	infoFile.close();

	cout << "The shop revenue is: $" << revenue << endl << " \n--Shop Menu: " << endl;

	m.load_menu();

	cout << endl << "order info: " << endl << "-----------------------" << endl;
	read_orders();

    cout << endl << "--- The best seller --- " << endl;
    populate_top_seller();
    cout << "-----------------------" << endl;

    cout << endl << "-The Top 3 best drinks today!-" << endl;
    populate_top_drinks();
    cout << "-----------------------------" << endl;
	
}

/**************************************************
 * Name: add_to_menu()
 * Description: Prompts the user to add a new coffee item to the shop's menu.
 * Parameters: None
 * Pre-conditions: The Shop object must be instantiated.
 * Post-conditions: If the user confirms, a new coffee item is added to the menu.
 *                 If the user cancels, the menu remains unchanged.
 ***********************************************/ 
void Shop::add_to_menu(){
    string name;
    float small_cost, medium_cost, large_cost;

    //Asks user to input a name and prices of different sizes (small, medium, large)
    cout << "Enter the name of the new coffee drink (1 word): ";
    cin >> name;

    cout << "Enter price of small size (8oz): ";
    cin >> small_cost;

    cout << "Enter price of medium size (16oz): ";
    cin >> medium_cost;

    cout << "Enter price of large size (24oz): ";
    cin >> large_cost;

    Coffee new_menu_arr(name, small_cost, medium_cost, large_cost);
    m.add_to_menu(new_menu_arr);

    cout << "This new drink has been successfully added to the coffee menu!" << endl;
}

/**************************************************
 * Name: remove_from_menu()
 * Description: Prompts the user to remove a coffee item from the shop's menu.
 * Parameters: None
 * Pre-conditions: The Shop object must be instantiated.
 * Post-conditions: If the user confirms, the specified coffee item is removed from the menu.
 *                 If the user cancels, the menu remains unchanged.
 ***********************************************/
void Shop::remove_from_menu() {
    int remove_coffee;

    cout << "------------------------------------" << endl;
    int numCoffee = m.load_item(); // Assuming load_menu() returns the number of coffee items
    cout << endl << "------------------------------------" << endl << endl;
    cout << "Please select which coffee number you would like to remove: ";
	cin >> remove_coffee;
    
    // Input error handling
    while (true) {

		// Check if the input is within the valid range
		if (remove_coffee >= 1 && remove_coffee <= numCoffee) {
			// Valid input, break out of the loop
			m.remove_from_menu(remove_coffee - 1);
			cout << "This coffee item has been successfully removed!" << endl;
			break;
		} else {
			// Invalid input, clear the input buffer and display an error message
			cout << "Invalid input. Please enter a valid coffee number. ";
			cin >> remove_coffee;
		}
   	}
}

/**************************************************
 * Name: search_by_name()
 * Description: Allows the user to search for a coffee item in the shop's menu by name.
 * Parameters: None
 * Pre-conditions: The Shop object must be instantiated, and the menu should not be empty.
 * Post-conditions: Displays information about the found coffee item or indicates if it's not in the menu.
 ***********************************************/
void Shop::search_by_name(){
	string coffee_name ;

	cout << "Enter a coffee name: ";
	cin >> coffee_name;
	
	m.search_coffee_by_name(coffee_name);
	
}

/**************************************************
 * Name: search_by_price()
 * Description: Allows the user to search for coffee items in the shop's menu by price range.
 * Parameters: None
 * Pre-conditions: The Shop object must be instantiated, and the menu should not be empty.
 * Post-conditions: Displays information about the found coffee items within the specified price range.
 ***********************************************/
void Shop::search_by_price(){
    float budget;

    cout << "Enter your budget for one drink, and I will list out our products that below or equal to your budget:";
    cin >> budget;

    cout << endl << "Coffee items within the budget:" << endl;
    m.search_coffee_by_price(budget);

}

/**************************************************
 * Name: place_order()
 * Description: Initiates the process for a customer to place an order in the coffee shop.
 * Parameters: None
 * Pre-conditions: The Shop object must be instantiated, and the menu should not be empty.
 * Post-conditions: If the order is confirmed, it adds a new order to the shop's records and updates the revenue.
 ***********************************************/
void Shop::place_order() {

    cout << "Welcome to the order menu!" << endl;
    int coffeeItems = m.load_item();
    cout << endl << "----------------------" << endl;

    int coffee_number;
    cout << "Please enter a drink from above that you would like to order! (Enter a number from the list): ";
    cin >> coffee_number;

    // Input error handling
    while (coffee_number < 1 || coffee_number > coffeeItems) {
        cout << "Invalid input. Please enter a valid coffee number: ";
        cin >> coffee_number;
    }

    cout << endl << "Drinks: " << endl;
    m.get_coffee_at(coffee_number - 1).print_coffee();
    cout << "----------------------" << endl << endl;

    char size;
    cout << "Please select a size for your coffee! (S-small, M-medium, L-large): ";
    cin >> size;

    while (size != 'S' && size != 'M' && size != 'L') {
        cout << "Invalid input. Please enter a valid size (S/M/L): ";
        cin >> size;
    }

    // Asks for the quantity of items
    int quantity;
    cout << "Enter quantity: ";
    cin >> quantity;

    confirm_order(coffee_number, size, quantity);   
}

/**************************************************
 * Name: confirm_order()
 * Description: Confirms and processes the customer's order with specified details.
 * Parameters:
 *   - coffee_number: The number corresponding to the selected coffee item in the menu.
 *   - size: The size of the coffee (S, M, or L).
 *   - quantity: The quantity of the ordered items.
 * Pre-conditions: The Shop object must be instantiated, and the menu should not be empty.
 * Post-conditions: If the order is confirmed, it adds a new order to the shop's records and updates the revenue.
 ***********************************************/
void Shop::confirm_order(int coffee_number, char size, int quantity) {

    float cost;
    switch (size) {
        case 'S':
            cost = m.get_coffee_at(coffee_number - 1).get_small_cost()* quantity;
            break;
        case 'M':
            cost = m.get_coffee_at(coffee_number - 1).get_medium_cost()* quantity;
            break;
        case 'L':
            cost = m.get_coffee_at(coffee_number - 1).get_large_cost()* quantity;
            break;
    }

	// Display order cost
    cout << endl << "Your total cost is: $"  << cost << endl;

	// Ask for confirmation
    char confirm;
    cout << endl << "Confirm your order? (Y/N): ";
    cin >> confirm;

	if (confirm == 'Y' || confirm == 'y') {

		//get coffee name for the order
		string coffee_name = m.get_coffee_at(coffee_number - 1).get_name();

		// Create an Order object and add it to the shop's orders
		Order new_order(coffee_number, coffee_name, size, quantity);
		add_order(new_order);

		// Update the shop's revenue
		revenue += cost; 

		cout << "Order placed successfully! Thank you for your purchase." << endl;
	} else {
		cout << "Your order has been canceled." << endl;
	}  
}

/**************************************************
 * Name: add_order()
 * Description: Adds a new order to the shop's records.
 * Parameters:
 *   - order: The Order object representing the customer's order.
 * Pre-conditions: The Shop object must be instantiated.
 * Post-conditions: The order is added to the shop's records.
 ***********************************************/
    void Shop::add_order(const Order& order) {
        // Increase the size of the array when a new order is added
        int new_num_orders = num_orders + 1;
        Order* new_order_arr = new Order[new_num_orders];

        // Copy elements from the old array
        for (int i = 0; i < num_orders; i++) {
            new_order_arr[i] = order_arr[i];
        }

        // Add the new order to the end of the new array
        new_order_arr[num_orders] = order;

        // Delete old array to prevent memory leaks
        delete[] order_arr;

        // Update the class variables
        order_arr = new_order_arr;
        num_orders = new_num_orders;

        int count = 0;
        ofstream orderFile;
        orderFile.open("orders.txt");

        // Write order information to the file
        orderFile << num_orders << endl;
        for(int i=0; i < num_orders; i++) {
            count++;
            orderFile << "" <<  count;
            orderFile << " " << order_arr[i].get_coffee_name();
            orderFile << " " << order_arr[i].get_coffee_size();
            orderFile << " " << order_arr[i].get_quantity() << endl;
        }

        orderFile.close();
    }

/**************************************************
 * Name: read_orders()
 * Description: Reads and processes orders from a file.
 * Parameters: None
 * Pre-conditions: The Shop object must be instantiated.
 * Post-conditions: Orders from a file are processed and added to the shop's records.
 ***********************************************/
void Shop::read_orders() {

    int count = 0;
	ifstream file;
	file.open("orders.txt");

    int numOrders;
    file >> numOrders; // Read the number of orders from the file

    Order* order_arr = new Order[numOrders];

    // Loop through each order and print its details to the terminal
    for (int i = 0; i < numOrders; ++i) {
        order_arr[i].populate_order(file);
        // Print order details to the terminal
		count++;
        cout << " Order ID: " << count << endl;
        cout << " Coffee Name: " << order_arr[i].get_coffee_name() << endl;
        cout << " Size: " << order_arr[i].get_coffee_size() << endl;
        cout << " Quantity: " << order_arr[i].get_quantity() << endl;
		cout << "-----------------------" << endl;

    }
    file.close();

    delete[] order_arr;
}

/**************************************************
 * Name: clone_shop()
 * Description: Creates and returns a clone of the current Shop object.
 * Parameters: None
 * Pre-conditions: The Shop object must be instantiated.
 * Post-conditions: A new Shop object is created as a clone of the current shop.
 ***********************************************/
Shop Shop::clone_shop() {
	//handle "Clone a shop" option
	//note: the purpose of this option is to test
	//your big three implementation
	Shop cloned_shop;

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}


/**************************************************
 * Name: populate_top_seller()
 * Description: Reads orders from a file, populates the order array, 
 *              and finds and displays the top-selling item in the shop based on quantity sold.
 * Parameters: None
 * Pre-conditions: The shop must have a valid "orders.txt" file containing order information.
 * Post-conditions: The order array is populated, and the top-selling item is displayed on the console.
 ***********************************************/
void Shop::populate_top_seller(){

    ifstream file;
    file.open("orders.txt");

    int maxDrinks;
    file >> maxDrinks;

    Order* order_arr = new Order[maxDrinks]; 

    // Read orders from the file and populate the order_arr array
    for (int i = 0; i < maxDrinks; ++i) {
        order_arr[i].populate_order(file);
    }

    file.close();

    find_top_seller(order_arr, maxDrinks);

    delete[] order_arr;  

    
}
/**************************************************
 * Name: find_top_seller()
 * Description: Finds and displays the top-selling item in the shop.
 * Parameters: None
 * Pre-conditions: The shop must have items in its inventory.
 * Post-conditions: The top-selling item is displayed.
 ***********************************************/
void Shop::find_top_seller(Order* order_arr, int maxDrinks) {

    // Initialize variables to store the information of the most popular drink
    string topDrink;
    char topSize;
    int maxQuantity = 0;

    // Find the top drink in terms of quantity
    for (int i = 0; i < maxDrinks; ++i) {
        if (order_arr[i].get_quantity() > maxQuantity) {
            maxQuantity = order_arr[i].get_quantity();
            topDrink = order_arr[i].get_coffee_name();
            topSize = order_arr[i].get_coffee_size();
        }
    }

    if (maxQuantity > 0) {
        cout << "Top Drink: " << topDrink << " (Size: " << topSize << ") - Quantity: " << maxQuantity << endl;
    } else {
        cout << " No orders has been placed yet! " << endl;
    }

}

/**************************************************
 * Name: populate_top_drinks()
 * Description: Reads orders from a file, populates the order array, 
 *              and finds and displays the top-selling item as well as the top three drinks based on quantity sold.
 * Parameters: None
 * Pre-conditions: The shop must have a valid "orders.txt" file containing order information.
 * Post-conditions: The order array is populated, and the top-selling item and top three drinks are displayed on the console.
 ***********************************************/
void Shop::populate_top_drinks(){

    ifstream file;
    file.open("orders.txt");

    int maxDrinks;
    file >> maxDrinks;

    Order* order_arr = new Order[maxDrinks]; 

    // Read orders from the file and populate the order_arr array
    for (int i = 0; i < maxDrinks; ++i) {
        order_arr[i].populate_order(file);
    }

    file.close();

    find_top_drinks(order_arr, maxDrinks);

    delete[] order_arr;
}

/**************************************************
 * Name: find_top_drinks()
 * Description: Finds and displays the top three drinks based on quantity sold.
 * Parameters: None
 * Pre-conditions: The shop must have recorded orders.
 * Post-conditions: The top three drinks are displayed.
 ***********************************************/
void Shop::find_top_drinks(Order* order_arr, int maxDrinks) {

    // Initialize variables to store the information of the top drinks
    string topDrinks[3];
    char topSizes[3];
    int maxQuantities[3] = {0};

    // Find the top 3 drinks in terms of quantity
    for (int i = 0; i < maxDrinks; ++i) {
        int quantity = order_arr[i].get_quantity();
        for (int j = 0; j < 3; ++j) {
            if (quantity > maxQuantities[j]) {

                // Shift elements to make room for the new top drink
                for (int k = 2; k > j; --k) {
                    maxQuantities[k] = maxQuantities[k - 1];
                    topDrinks[k] = topDrinks[k - 1];
                    topSizes[k] = topSizes[k - 1];
                }

                // Update the top drink information
                maxQuantities[j] = quantity;
                topDrinks[j] = order_arr[i].get_coffee_name();
                topSizes[j] = order_arr[i].get_coffee_size();
                break;
            }
        }
    }

    // Display the top 3 drinks
    if (maxQuantities[0] == 0) {
        cout << "Please, place orders to view top 3 drinks! " << endl;
    } else {
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << ". " << topDrinks[i] << " (Size: " << topSizes[i] << ") - Quantity: " << maxQuantities[i] << endl;
        }
    }
}

