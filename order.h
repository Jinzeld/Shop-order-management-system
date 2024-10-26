#ifndef ORDER_H
#define ORDER_H 

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:

	Order();
	Order(int id, string coffee_name, char coffee_size, int quantity);
	//need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

	// Getter methods
    int get_id() const;
    string get_coffee_name() const;
    char get_coffee_size() const;
    int get_quantity() const;

	void set_id(const int);
	void set_coffee_name(const string);
	void set_coffee_size(const char);
	void set_quantity(const int);

	
	void print_order() const;
	void populate_order(ifstream& file);
};
#endif