#include "menu.h"

using namespace std;

//function defintions from menu.h goes here

//Default constructor
Menu::Menu(){
    num_coffee = 0;
    coffee_arr = nullptr;
}


Menu::Menu(int num_coffee, Coffee* coffee_arr){
    this->num_coffee = num_coffee;
    this->coffee_arr = new Coffee[num_coffee];
    for (int i = 0; i < num_coffee; i++){
        this->coffee_arr[i] = coffee_arr[i];
    }
}

//Destructor
Menu::~Menu(){
    delete[] coffee_arr;
}


/**************************************************
 * Name: populate_menu()
 * Description: Reads coffee menu items from a file and populates the menu.
 * Parameters: None
 * Pre-conditions: The menu must have a valid "menu.txt" file containing coffee items.
 * Post-conditions: The menu is populated with coffee items.
 ***********************************************/
void Menu::populate_menu(){ // populates the menu from menu.txt
	ifstream file;
	file.open("menu.txt");

    file >> this->num_coffee;

    // Avoid double allocation and deallocation
    delete[] coffee_arr;

    this->coffee_arr = new Coffee [this->num_coffee];

    for (int i = 0; i < this->num_coffee; i++){
        //populate a single coffee
        coffee_arr[i].populate_coffee(file);
    }
	file.close();   

}


/**************************************************
 * Name: load_menu()
 * Description: Reads coffee menu items from a file and loads them into the menu.
 * Parameters: None
 * Pre-conditions: The menu must have a valid "menu.txt" file containing coffee items.
 * Post-conditions: The menu is loaded with coffee items.
 ***********************************************/
void Menu::load_menu(){ //prints the item number and displays the item name and price
	ifstream file;
	file.open("menu.txt");
	
    file >> this->num_coffee;

    delete[] coffee_arr;

    this->coffee_arr = new Coffee [this->num_coffee];

    for (int i = 0; i < this->num_coffee; i++){
        //populate a single coffee
        coffee_arr[i].populate_coffee(file);
    }

    for (int i = 0; i < num_coffee; i++){
        cout << endl << i + 1 << ". ";
        coffee_arr[i].print_coffee();
    }

	file.close();

}


/**************************************************
 * Name: load_item()
 * Description: Reads the number of coffee items from a file and returns the count.
 * Parameters: None
 * Pre-conditions: The menu must have a valid "menu.txt" file containing the number of coffee items.
 * Post-conditions: Returns the count of coffee items.
 ***********************************************/
int Menu::load_item() { // loads the item numbers and display the item name
    Coffee found;
    ifstream file;

    file.open("menu.txt");
    file >> this->num_coffee;
  
    for (int i = 0; i < num_coffee; i++) {
        cout << endl << i + 1 << ". ";
        found = coffee_arr[i];
        cout << found.get_name() << endl;  
    }
    file.close();

    return num_coffee;
}


/**************************************************
 * Name: search_coffee_by_name()
 * Description: Searches for a coffee item in the menu by its name.
 * Parameters:
 *   - name (string): The name of the coffee item to search for.
 * Pre-conditions: The menu must be populated with coffee items.
 * Post-conditions: Returns the Coffee object with the specified name. If not found, returns an empty Coffee object.
 ***********************************************/
Coffee Menu::search_coffee_by_name(string name) {
	Coffee found; 
	bool coffeeFound = false;

	for(int i=0; i < this->num_coffee; i++){
		if(coffee_arr[i].get_name() == name){
			found = coffee_arr[i];
			coffeeFound = true;

			// Display the found coffee's details
            cout << endl << "Found Coffee:" << endl << "#" << i + 1 << " ";
			coffee_arr[i].print_coffee();
		}
	}

	if(!coffeeFound) {
		cout << "No coffee with '" << name << "' was found." << endl;
	}

	return found;
}


/**************************************************
 * Name: add_to_menu()
 * Description: Adds a Coffee item to the menu.
 * Parameters:
 *   - coffee_to_add (Coffee&): The Coffee object to add to the menu.
 * Pre-conditions: The menu must be properly initialized.
 * Post-conditions: The specified Coffee item is added to the menu.
 ***********************************************/
void Menu::add_to_menu(Coffee& coffee_to_add){

    //Increase size of array when new coffee item gets added
    Coffee* new_coffee_arr = new Coffee[num_coffee + 1];

    //Copy elements from old array
    for(int i=0; i < num_coffee; i++){
        new_coffee_arr[i] = this->coffee_arr[i];
    }
    //New coffee item is added to the end of array
    new_coffee_arr[num_coffee] = coffee_to_add;

    //Delete old array to prevent memory leaks
    delete[] coffee_arr;

    //Coffee array is updated with the new version
    this->coffee_arr = new_coffee_arr;

    //Number of coffee items on menu increases
    this->num_coffee++;

    //Updates file with the correct number of items
    ofstream update_file;
    update_file.open("menu.txt");
    update_file << this->num_coffee << endl;
    for (int i = 0; i < num_coffee; i++){
        update_file << this->coffee_arr[i].get_name() << " ";
        update_file << this->coffee_arr[i].get_small_cost() << " ";
        update_file << this->coffee_arr[i].get_medium_cost() << " ";
        update_file << this->coffee_arr[i].get_large_cost() << endl;
    }
    update_file.close();
} 


/**************************************************
 * Name: remove_from_menu()
 * Description: Removes a Coffee item from the menu based on its index.
 * Parameters:
 *   - index_of_coffee_on_menu (int): The index of the Coffee item to be removed.
 * Pre-conditions: The menu must be properly initialized, and the index must be valid.
 * Post-conditions: The specified Coffee item is removed from the menu.
 ***********************************************/
void Menu::remove_from_menu(int index_of_coffee_on_menu) {


    //Decrease array size when new coffee item gets added
    Coffee* new_coffee_arr = new Coffee[num_coffee - 1];


    // copy elements from the old array
    for (int i = 0; i < index_of_coffee_on_menu; i++) {
        // Check if the current coffee item should be removed
        new_coffee_arr[i] = this->coffee_arr[i];
    }

    //Copy elements after a coffee item is removed
    for(int i = index_of_coffee_on_menu + 1; i < num_coffee; i++){
        new_coffee_arr[i - 1] = coffee_arr[i];
    }
    // Clean up memory for the old array
    delete[] coffee_arr;

    // Update the class variables
    this->coffee_arr = new_coffee_arr;

    this->num_coffee--;

    // Update the menu.txt file
    ofstream update_file("menu.txt");
    update_file << this->num_coffee << endl;
    for (int i = 0; i < num_coffee; i++) {
        update_file << this->coffee_arr[i].get_name() << " ";
        update_file << this->coffee_arr[i].get_small_cost() << " ";
        update_file << this->coffee_arr[i].get_medium_cost() << " ";
        update_file << this->coffee_arr[i].get_large_cost() << endl;
    }
    update_file.close();
}


/**************************************************
 * Name: search_coffee_by_price()
 * Description: Searches for Coffee items within the budget and returns a Menu containing those items.
 * Parameters:
 *   - budget (float): The maximum price budget for the search.
 * Pre-conditions: The menu must be properly initialized, and the budget must be a non-negative value.
 * Post-conditions: Returns a Menu containing Coffee items that are within the specified budget.
 ***********************************************/
Menu Menu::search_coffee_by_price(float budget){
	Menu temp;

    bool item = false;
    for (int i = 0; i < num_coffee; i++) {
        float small_cost = coffee_arr[i].get_small_cost();
        float medium_cost = coffee_arr[i].get_medium_cost();
        float large_cost = coffee_arr[i].get_large_cost();

        // Check if any size's cost is within the specified budget
        if (small_cost <= budget || medium_cost <= budget || large_cost <= budget) { 
            cout << "#" << i + 1 << " ";
            coffee_arr[i].print_coffee();
            item = true;
            
        }

    }
    if(!item){
        cout << "sorry, there is no coffee item within your budget!" << endl;
    }

	return temp;
}


/***************************************************
 * Name: get_coffee_at()
 * Description: Returns the Coffee item at the specified index in the Menu.
 * Parameters:
 *   - index (int): The index of the Coffee item to retrieve.
 * Pre-conditions: The Menu must be properly initialized, and the index should be within the valid range.
 * Post-conditions: Returns the Coffee item at the specified index.
 ****************************************************/
Coffee Menu::get_coffee_at(int index) const {
    if (index >= 0 && index < num_coffee) {
        return coffee_arr[index];
    } else {
        // Handle out-of-bounds access, maybe throw an exception or return a default Coffee object
        // For simplicity, I'll return an empty Coffee object
        return Coffee();
    }
}
