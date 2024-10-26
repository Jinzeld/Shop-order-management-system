#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;

class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors, copy constructors, assignment operator overload,
    
    //constructor 
    Menu();
    Menu(int num_coffee, Coffee* coffee_arr);

    //desructor
    ~Menu();

    //and destructors where appropriate
    //need to use 'const' when appropriate

    // Suggested functions:
    Coffee search_coffee_by_name(string name); 
    Menu search_coffee_by_price(float budget); 
    void add_to_menu(Coffee& coffee_to_add); //add a coffee object into the Menu
    void remove_from_menu(int index_of_coffee_on_menu); //remove a coffee object from the Menu

    // feel free to add more member functions

    void populate_menu();
    void load_menu();
    int load_item();
    Coffee get_coffee_at(int index) const;
};

#endif