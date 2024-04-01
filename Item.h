#pragma once
#include <string>

class Item {
    private:
        int SKU;    //Stock Keeping Number
        std::string description; 
        double price;
        std::string UOM;    //Unit of measurement - how is it sold by
        int quantityOnHand;
        int leadTime;   //Number of days it takes to order if there aren't any on hand
    public:
        Item();
        Item(int idNum);
        Item(int idNum, std::string descp, double cost, std::string unit, int orderTime, int quantity = 0);
        std::string GetPartInfo();
        double GetPrice();
        bool InStock();
        bool IsAvailable(int desiredData);
        bool operator==(const Item& obj);
        bool operator>(const Item& obj);
        bool operator<(const Item& obj);
};