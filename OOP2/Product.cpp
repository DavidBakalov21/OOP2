#include "Product.h"
IDGenerator Product::idGen;
Product::~Product() {
}

Product::Product(std::string n, int priceProd, int q)
    : productID(idGen.GenerateId()), name(n), price(priceProd), quantityInStock(q) {
}

void Product::SetName(std::string NameNew) {
    name = NameNew;
}

void Product::SetProId(std::string PId) {
    productID = PId;
}

void Product::SetPrice(int newPrice) {
    price = newPrice;
}

void Product::Setquantity(int newQuantity) {
    quantityInStock = newQuantity;
}

std::string Product::getName() const {
    return name;
}

int Product::getPrice() const {
    return price;
}

int Product::getQuantityInStock() const {
    return quantityInStock;
}

std::string Product::getID() const {
    return productID;
}

int Product::totalPrice() const {
    return quantityInStock * price;
}

