#include "coffee.h"

using namespace std;


Coffee::Coffee(){
}

Coffee::Coffee(string name, float small_cost, float medium_cost, float large_cost){
    this->name = name;
    this->small_cost = small_cost;
    this->medium_cost = medium_cost;
    this->large_cost = large_cost;
}

// getter
/**************************************************
 * Name: get_name()
 * Description: Retrieves the name of the Coffee object.
 * Parameters: None
 * Pre-conditions: The Coffee object is valid.
 * Post-conditions: The name of the Coffee object is returned.
 ***********************************************/
string Coffee::get_name() const{
    return this->name;
}

/**************************************************
 * Name: get_small_cost()
 * Description: Retrieves the cost of the small-sized Coffee object.
 * Parameters: None
 * Pre-conditions: The Coffee object is valid.
 * Post-conditions: The cost of the small-sized Coffee object is returned.
 ***********************************************/
float Coffee::get_small_cost () const{
    return this->small_cost;
}

/**************************************************
 * Name: get_medium_cost()
 * Description: Retrieves the cost of the medium-sized Coffee object.
 * Parameters: None
 * Pre-conditions: The Coffee object is valid.
 * Post-conditions: The cost of the medium-sized Coffee object is returned.
 ***********************************************/
float Coffee::get_medium_cost () const{
    return this->medium_cost;
}

/**************************************************
 * Name: get_large_cost()
 * Description: Retrieves the cost of the large-sized Coffee object.
 * Parameters: None
 * Pre-conditions: The Coffee object is valid.
 * Post-conditions: The cost of the large-sized Coffee object is returned.
 ***********************************************/
float Coffee::get_large_cost () const{
    return this->large_cost;
}

/**************************************************
 * Name: set_name()
 * Description: Sets the name of the Coffee object.
 * Parameters: 
 *   - name: The new name to be set for the Coffee object.
 * Pre-conditions: The Coffee object is valid.
 * Post-conditions: The name of the Coffee object is updated.
 ***********************************************/
 void Coffee::set_name (const string name) {
    this->name = name;
  }

 /**************************************************
 * Name: set_small_cost()
 * Description: Sets the small size cost of the Coffee object.
 * Parameters: 
 *   - small_price: The new cost for the small size of the Coffee object.
 * Pre-conditions: The Coffee object is valid.
 * Post-conditions: The cost for the small size of the Coffee object is updated.
 ***********************************************/
  void Coffee::set_small_cost(const float small_price) {
    this->small_cost = small_price;
  }

/**************************************************
 * Name: set_medium_cost()
 * Description: Sets the medium size cost of the Coffee object.
 * Parameters: 
 *   - medium_price: The new cost for the medium size of the Coffee object.
 * Pre-conditions: The Coffee object is valid.
 * Post-conditions: The cost for the medium size of the Coffee object is updated.
 ***********************************************/
  void Coffee::set_medium_cost(const float medium_price) {
    this->medium_cost = medium_price;
  }

/**************************************************
 * Name: set_large_cost()
 * Description: Sets the cost of a large-sized coffee.
 * Parameters: 
 *    - const float large_price: The cost of a large-sized coffee.
 * Pre-conditions: None
 * Post-conditions: The cost of a large-sized coffee is updated.
 ***********************************************/
  void Coffee::set_large_cost(const float large_price) {
    this->large_cost = large_price;
  }

/**************************************************
 * Name: populate_coffee()
 * Description: Populates the Coffee object with information from a file.
 * Parameters:
 *    - ifstream& file: Reference to the input file stream.
 * Pre-conditions: The file must be open and contain valid data for a Coffee object.
 * Post-conditions: The Coffee object is populated with information from the file.
 ***********************************************/
void Coffee::populate_coffee(ifstream& file){
    file >> this->name >> this->small_cost >> this->medium_cost >> this->large_cost;
}
 
/**************************************************
 * Name: print_coffee()
 * Description: Prints the details of the Coffee object.
 * Parameters: None
 * Pre-conditions: The Coffee object must be initialized with valid data.
 * Post-conditions: The details of the Coffee object are printed to the console.
 ***********************************************/
void Coffee::print_coffee() const {
    cout << "----------" << endl;
    cout << "  name: " << this->name << endl;
    cout << "  small cost: $" << this->small_cost << endl;
    cout << "  medium cost: $" << this->medium_cost << endl;
    cout << "  large cost: $" << this->large_cost << endl;
  } //print the coffee object

