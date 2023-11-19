#include "Product.h"

Product::~Product() {
}

Product::Product(std::string n, int priceProd, int q)
    : productID(GenerateId()), name(n), price(priceProd), quantityInStock(q) {
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

std::string Product::GenerateId() {
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::string result = "";
    std::uniform_int_distribution<int> dist(1, 9);
    for (int i = 0; i < 27; i++) {
        int iRand = dist(rng);
        result += std::to_string(iRand);
    }
    return result;
}