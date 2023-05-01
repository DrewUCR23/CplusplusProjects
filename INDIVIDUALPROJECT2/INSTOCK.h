#ifndef INSTOCK_H
#define INSTOCK_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <iomanip>
#include "USER.h"
using std::string;
using std::setw;

class Food {
private:
    int count;
    std::string name;
public:


    //constructor

    Food() : count(0), name("") {
    }
    //constructor 2

    Food(int count, const std::string& name) : count(count), name(name) {
    }

    int getCount() const {
        return count;
    }

    const std::string& getName() const {
        return name;
    }
};

struct FOODINVENTORY {
    int apple = 40;
    int orange = 50;
    int banana = 60;
    int soda = 25;
    int ham = 20;
    int turkey = 15;
    int eggs = 10;
    int icecream = 10;
};

struct FOODNAMES {
    std::vector <string> costs = {"$2.00", "$2.25", "$3", "$1.50", "$1.25", "$6.75", "$7.50", "$1.25"};
    std::string apple1 = "Apple";
    std::string orange1 = "Orange";
    std::string banana1 = "Banana";
    std::string soda1 = "Soda";
    std::string ham1 = "Ham";
    std::string turkey1 = "Turkey";
    std::string eggs1 = "Eggs";
    std::string icecream1 = "Icecream";
};

void FOODSTOCK(FOODINVENTORY& world, FOODNAMES& NAMES) {
    std::cout << "These are the foods that we currently have in stock at this time" << std::endl;
    std::map<std::string, int> inventory{
        {NAMES.apple1, world.apple},
        {NAMES.orange1, world.orange},
        {NAMES.banana1, world.banana},
        {NAMES.soda1, world.soda},
        {NAMES.ham1, world.ham},
        {NAMES.turkey1, world.turkey},
        {NAMES.eggs1, world.eggs},
        {NAMES.icecream1, world.icecream}};
    int index = 0;
    for (const auto& item : inventory) {
        std::cout << "Food Names: " << setw(20) << item.first << setw(20) << "Costs:" << setw(20) << NAMES.costs[index] << setw(20) << "Quantities:" << setw(20) << item.second << std::endl;
        std::cout << std::endl;
        ++index;
    }
}

void FOODCHOICE(FOODINVENTORY& world, FOODNAMES& NAMES, string USERCHOICE, int cost, int QUANTITY) {
    std::map<std::string, int> inventory{
        {NAMES.apple1, world.apple},
        {NAMES.orange1, world.orange},
        {NAMES.banana1, world.banana},
        {NAMES.soda1, world.soda},
        {NAMES.ham1, world.ham},
        {NAMES.turkey1, world.turkey},
        {NAMES.eggs1, world.eggs},
        {NAMES.icecream1, world.icecream}};

    for (auto &item : inventory) {
        if (USERCHOICE == item.first) {
            item.second -= QUANTITY;
            std::cout << "The food you have picked is: " << item.first
                    << " for a price of: " << NAMES.costs[cost] << " Quantity: " << QUANTITY << std::endl;
        } else {
            std::cout << "You have picked an invalid value, please try again" << std::endl;
        }
    }
}
// INSTOCK.h
void LOADSHOPPINGCART(FOODINVENTORY& world, FOODNAMES& foodNames, std::map<std::string, int>& user_choices) {
    std::cout << "Items in your cart: " << std::endl;
    for (const auto& item : user_choices) {
        std::string food_name = item.first;
        int quantity = item.second;
        // Create a map to store the prices for each food item
        std::map<std::string, float> foodPrices = {
            {"Apple", 2.00},
            {"Orange", 2.25},
            {"Banana", 3.00},
            {"Soda", 1.50},
            {"Ham", 1.25},
            {"Turkey", 6.75},
            {"Eggs", 7.50},
            {"Icecream", 1.25}
        };
        // Get the price for the current food item
        float price = foodPrices[food_name];

        std::cout << "Food: " << food_name << ", Quantity: " << quantity << ", Price: " << price << std::endl;
    }
}


void RECEIPT(FOODINVENTORY& world, FOODNAMES& NAMES, std::map<std::string, int>& user_choices, float PRICEPAID) {
    const float SALESTAX = 1.0375f;
    float total_cost = 0.0f;
    float LEFTOVER = 0.0f;

    std::map<std::string, float> prices{
        {NAMES.apple1, 2.00},
        {NAMES.orange1, 2.25},
        {NAMES.banana1, 3.00},
        {NAMES.soda1, 1.50},
        {NAMES.ham1, 1.25},
        {NAMES.turkey1, 6.75},
        {NAMES.eggs1, 7.50},
        {NAMES.icecream1, 1.25},};

    std::cout << std::setw(20) << "Item"
            << std::setw(10) << "Price"
            << std::setw(10) << "Quantity"
            << std::setw(10) << "Cost" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (const auto& item : user_choices) {
        float item_price = prices[item.first];
        int item_quantity = item.second;
        float item_cost = item_price * item_quantity;
        total_cost += item_cost;

        std::cout << std::setw(20) << item.first
                << std::setw(10) << item_price
                << std::setw(10) << item_quantity
                << std::setw(10) << item_cost << std::endl;
    }

    total_cost *= SALESTAX;
    LEFTOVER = PRICEPAID - total_cost;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::setw(20) << "Total Cost" << std::setw(30) << total_cost << std::endl;
    std::cout << std::setw(20) << "Total Paid" << std::setw(30) << PRICEPAID << std::endl;
    std::cout << std::setw(20) << "Change" << std::setw(30) << LEFTOVER << std::endl;

    if (LEFTOVER >= 0) {
        std::cout << "Your Change is: " << LEFTOVER << std::endl;
    } else {
        std::cout << "You do not have enough money to pay for these items" << std::endl;
    }
}

void STOREPURCHASES(FOODNAMES& NAMES, std::map<std::string, int>& user_choices, float TOTALPRICE, float LEFTOVER, int PRICEPAID) {
    std::ofstream purchase_file("purchase_records.bin", std::ios::binary | std::ios::app);
    int counter = 0;

    if (purchase_file.is_open()) {
        for (const auto& item : user_choices) {
            purchase_file.write(reinterpret_cast<const char*> (item.first.c_str()), item.first.size());
            purchase_file.write(reinterpret_cast<char*> (&NAMES.costs[counter]), sizeof (NAMES.costs[counter]));
            purchase_file.write(reinterpret_cast<const char*> (&item.second), sizeof (item.second));
            ++counter;
        }
        purchase_file.write(reinterpret_cast<char*> (&TOTALPRICE), sizeof (TOTALPRICE));
        purchase_file.write(reinterpret_cast<char*> (&PRICEPAID), sizeof (PRICEPAID));
        purchase_file.write(reinterpret_cast<char*> (&LEFTOVER), sizeof (LEFTOVER));
        purchase_file.close();
    } else {
        std::cout << "Unable to open the purchase records file" << std::endl;
    }
}


#endif // INSTOCK_H


