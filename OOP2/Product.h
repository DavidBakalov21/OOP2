#pragma once

#include <string>

#include <random>
#include <chrono>

class IDGenerator {
private:
    std::mt19937 rng;
public:
    std::string GenerateId() {
        rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
        std::string result = "";
        std::uniform_int_distribution<int> dist(1, 9);
        for (int i = 0; i < 27; i++) {
            int iRand = dist(rng);
            result += std::to_string(iRand);
        }
        return result;
    }
};
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
    static IDGenerator idGen;
};