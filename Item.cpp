#include "Item.h"
Item::Item(){
    SKU = -1;
    description = "";
    price = -1;
    UOM = "null";
    quantityOnHand = -1;
    leadTime = -1;
}

Item::Item(int idnum){
    SKU = idnum;
}

Item::Item(int idNum, std::string descp, double cost, std::string unit, int orderTime, int quantity){
    SKU = idNum;
    description = descp;
    price = cost;
    UOM = unit;
    leadTime = orderTime;
    quantityOnHand = quantity;
}

std::string Item::GetPartInfo(){
    return std::to_string(SKU) + " - " + description;
}

double Item::GetPrice(){
    return price;
}

bool Item::InStock(){
    return quantityOnHand > 0;
}

//TODO: make the dates work as intented
bool Item::IsAvailable(int desiredDay){
    if (InStock()){
        return true;
    }
    else {
        return desiredDay <= leadTime;
    }
}


bool Item::operator==(const Item& obj){
    return this->SKU == obj.SKU;
}

bool Item::operator<(const Item& obj){
    return this->SKU < obj.SKU;
}

bool Item::operator>(const Item& obj){
    return this->SKU > obj.SKU;
}

