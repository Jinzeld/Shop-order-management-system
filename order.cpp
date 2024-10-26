#include "order.h"

using namespace std;


//function defintions from order.h goes here

Order::Order(){

}

// Implementation of the new constructor
Order::Order(int id, string coffee_name, char coffee_size, int quantity) {
    this->id = id;
    this->coffee_name = coffee_name;
    this->coffee_size = coffee_size;
    this->quantity = quantity;
}

//getter
/**************************************************
 * Name: get_id()
 * Description: Returns the ID of the Order.
 * Parameters: None
 * Pre-conditions: The Order must be properly initialized.
 * Post-conditions: Returns the ID of the Order.
 ***********************************************/
int Order::get_id() const {
    return this->id; 
}

/**************************************************
 * Name: get_coffee_name()
 * Description: Returns the name of the coffee in the Order.
 * Parameters: None
 * Pre-conditions: The Order must be properly initialized.
 * Post-conditions: Returns the name of the coffee in the Order.
 ***********************************************/
string Order::get_coffee_name() const {
    return this->coffee_name; 
}

/**************************************************
 * Name: get_coffee_size()
 * Description: Returns the size of the coffee in the Order.
 * Parameters: None
 * Pre-conditions: The Order must be properly initialized.
 * Post-conditions: Returns the size of the coffee in the Order.
 ***********************************************/
char Order::get_coffee_size() const {
    return this->coffee_size; 
}

/**************************************************
 * Name: get_quantity()
 * Description: Returns the quantity of the coffee in the Order.
 * Parameters: None
 * Pre-conditions: The Order must be properly initialized.
 * Post-conditions: Returns the quantity of the coffee in the Order.
 ***********************************************/
int Order::get_quantity() const {
    return this->quantity; 
}

// setter

/**************************************************
 * Name: set_id()
 * Description: Sets the ID of the Order.
 * Parameters: 
 *   - const int id: The ID to set for the Order.
 * Pre-conditions: None
 * Post-conditions: The ID of the Order is set to the provided value.
 ***********************************************/
void Order::set_id (const int id) {
    this->id = id;
}

/**************************************************
 * Name: set_coffee_name()
 * Description: Sets the coffee name of the Order.
 * Parameters: 
 *   - const string coffee_name: The coffee name to set for the Order.
 * Pre-conditions: None
 * Post-conditions: The coffee name of the Order is set to the provided value.
 ***********************************************/
void Order::set_coffee_name(const string coffee_name) {
    this->coffee_name = coffee_name;
}

/**************************************************
 * Name: set_coffee_size()
 * Description: Sets the coffee size of the Order.
 * Parameters: 
 *   - const char coffee_size: The coffee size to set for the Order.
 * Pre-conditions: None
 * Post-conditions: The coffee size of the Order is set to the provided value.
 ***********************************************/
void Order::set_coffee_size(const char coffee_size) {
    this->coffee_size = coffee_size;
}

/**************************************************
 * Name: set_quantity()
 * Description: Sets the quantity of the Order.
 * Parameters: 
 *   - const int quantity: The quantity to set for the Order.
 * Pre-conditions: None
 * Post-conditions: The quantity of the Order is set to the provided value.
 ***********************************************/
void Order::set_quantity(const int quantity) {
    this->quantity = quantity;
}

/**************************************************
 * Name: populate_order()
 * Description: Populates the Order object with data from a file.
 * Parameters: 
 *   - ifstream& file: Reference to the file stream for reading data.
 * Pre-conditions: The file stream is open and contains valid data.
 * Post-conditions: The Order object is populated with data from the file.
 ***********************************************/
void Order::populate_order(ifstream& file){
    file >> this->id >> this->coffee_name >> this->coffee_size >> this->quantity;
}

/**************************************************
 * Name: print_order()
 * Description: Prints the details of the Order object.
 * Parameters: None
 * Pre-conditions: The Order object is valid and contains data.
 * Post-conditions: The details of the Order object are printed to the console.
 ***********************************************/
void Order::print_order() const {

    // Write order information to the file
    cout << "Order ID: " << this->id << endl;
    cout << "Order Name: " << this->coffee_name << endl;
    cout << "Size: " << this->coffee_size << endl;
    cout << "Quantity: " << this->quantity << endl;
    cout << "------------------------" << endl;


}
