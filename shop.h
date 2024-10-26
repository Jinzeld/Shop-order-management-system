#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
  private:
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order *order_arr;   //order array
    int num_orders;     //number or orders

  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    Shop();
    Shop(string phone, string address, float revenue, Order *order_arr, int num_orders);

    //CC
    Shop(const Shop &clone);

    //AOO
    Shop& operator=(const Shop &clone);

    //destrutor
    ~Shop();

    //need to use 'const' when appropriate

    //Suggested functions
    void load_data(); //reads from files to correctly populate coffee, menu, etc.
    void view_shop_detail();
    void add_to_menu();
    void remove_from_menu();
    void search_by_name();
    void search_by_price();
    void place_order();
    Shop clone_shop();

    void confirm_order(int coffee_number, char size, int quantity);
    void add_order(const Order& order);
    void read_orders();
    void populate_top_seller();
    void populate_top_drinks();
    void find_top_seller(Order* order_arr, int maxDrinks);
    void find_top_drinks(Order* order_arr, int maxDrinks);
  
  
};

#endif
