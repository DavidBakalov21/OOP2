#ifndef PRODUCT_H
#define PRODUCT_H


#include <string>

#include <random>
#include <chrono>
class Product {
public:
    virtual ~Product();
    Product(std::string n, int priceProd, int q);
    virtual void displayDetails() const = 0;
    void SetName(std::string NameNew);
    void SetProId(std::string PId);
    void SetPrice(int newPrice);
    void Setquantity(int newQuantity);
    std::string getName() const;
    int getPrice() const;
    int getQuantityInStock() const;
    std::string getID() const;
    int totalPrice() const;

private:
    std::string productID;
    std::string name;
    int price;
    int quantityInStock;
    std::mt19937 rng;
    std::string GenerateId();
};

#endif