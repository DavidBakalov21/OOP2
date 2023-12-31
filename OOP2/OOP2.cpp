﻿#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>
#include <limits>
#include "Product.h"


class Electronics : public Product {
public:
    Electronics(std::string n, int priceProd, int q, std::string b, std::string m, int power): Product(n, priceProd, q), brand(b), model(m), powerConsumption(power) {}
    void setBrand(const std::string& newBrand) {
        brand = newBrand;
    }
    void setModel(const std::string& newModel) {
        model = newModel;
    }
    void setPowerConsumption(int newPower) {
        powerConsumption = newPower;
    }
    std::string getBrand() const {
        return brand;
    }
    std::string getModel()  const{
        return model;
    }
    int getPowerConsumption() const {
        return powerConsumption;
    }

    void DisplayPowerConsumption() {
        std::cout<<"Power consumption is: " << powerConsumption << std::endl;
    }

    virtual void displayDetails() const override {
        std::cout << "Name: " << this->getName() <<", Price: " << this->getPrice()<< ", Quantity:"<< this->getQuantityInStock()<<std::endl;
        std::cout << "Id: " << this->getID() << ", Brand: " << this->getBrand() << ", Model:" << this->getModel() <<", Power:"<<this->getPowerConsumption() <<std::endl;
    }
private:
    std::string brand;
    std::string model;
    int powerConsumption;
};


class Books : public Product {
public:
    Books(std::string n, int priceProd, int q, std::string a, std::string g, std::string IN) : Product(n, priceProd, q), author(a), genre(g), ISBN(IN) {}
  
    std::string getAuthor() const{
        return author;
    }
    std::string getGenre() const{
        return genre;
    }
    std::string getISBN() const{
        return ISBN;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }
    void setGenre(const std::string& newGenre) {
        genre = newGenre;
    }
    void setISBN(std::string newISBN) {
        ISBN = newISBN;
    }

    void DisplayPowerConsumption() {
        std::cout<<"Author is: " << author << std::endl;
    }

    virtual void displayDetails() const override {
        std::cout << "Name: " << this->getName() << ", Price: " << this->getPrice() << ", Quantity:" << this->getQuantityInStock() << std::endl;
        std::cout << "Id: " << this->getID() << ", Author: " << this->getAuthor() << ", Genre:" << this->getGenre() << ", ISBN:" << this->getISBN() << std::endl;
    }
private:
    std::string author;
    std::string genre;
    std::string ISBN;
};


class Clothing : public Product {
public:
    Clothing(std::string n, int priceProd, int q, std::string s, std::string c, std::string m) : Product( n, priceProd, q), size(s), color(c), material(m) {}
  
    std::string getSize() const {
        return size;
    }
    std::string getMaterial() const {
        return material;
    }
    std::string getColor() const {
        return color;
    }

    void setSize(const std::string& newSize) {
        size = newSize;
    }
    void setMaterial(const std::string& newMaterial) {
        material = newMaterial;
    }
    void setColor(const std::string& newColor) {
        color = newColor;
    }

    void DisplayPowerConsumption() {
        std::cout << "The size is: " << size << std::endl;
    }

    virtual void displayDetails() const override {
        std::cout << "Naaaaame: " << this->getName() << ", Price: " << this->getPrice() << ", Quantity:" << this->getQuantityInStock() << std::endl;
        std::cout << "Id: " << this->getID() << ", Size: " << this->getSize() << ", Material:" << this->getMaterial() << ", color:" << this->getColor() << std::endl;
    }
private:
    std::string size;
    std::string color;
    std::string material;
};

class FileConfig {
public:
    FileConfig() = default;

    void ReadReturn(const std::string& name) {
        std::ifstream file(name);
        if (!file.is_open()) {
            std::cout << "Failed to open the file." << std::endl;
            return;
        }

        std::string line;
        while (getline(file, line)) {
            std::vector<std::string> tokens = splitStringByComma(line);

            if (tokens.empty()) {
                return;
            }

            if (tokens[0] == "Electronics") {
                std::shared_ptr<Electronics> electronicProduct = std::make_shared<Electronics>(tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]), tokens[4], tokens[5], std::stoi(tokens[6]));
                ConfigItems.push_back(electronicProduct);
            }
            else if (tokens[0] == "Books") {
                std::shared_ptr<Books> BookProduct = std::make_shared<Books>(tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]), tokens[4], tokens[5], tokens[6]);
                ConfigItems.push_back(BookProduct);
            }
            else if (tokens[0] == "Clothing") {
                std::shared_ptr<Clothing> ClothingProduct = std::make_shared<Clothing>(tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]), tokens[4], tokens[5], tokens[6]);
                ConfigItems.push_back(ClothingProduct);
            }


        }

        file.close();
    }

    std::vector<std::shared_ptr<Product>> GiveInfo() {
        return ConfigItems;
    }

private:
    std::vector<std::string> splitStringByComma(const std::string& str) {
        std::vector<std::string> result;
        std::istringstream ss(str);
        std::string token;

        while (std::getline(ss, token, ',')) {
            result.push_back(token);
        }

        return result;
    }
    std::vector<std::shared_ptr<Product>> ConfigItems;


};
class Inventory {
public:
    Inventory() {}
    void AddItem(const std::shared_ptr<Product>& Product) {
        products.push_back(Product);
    }
 
    void UpdateQuantuty(const std::string& productName, const int newQuantity) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i]->getName() == productName) {
                products[i]->Setquantity(newQuantity);
                std::cout << products[i]->getQuantityInStock() << " left" << std::endl;
                std::cout << "quantity set" << std::endl;
                break;
            }
        }
    }
    void AlertQuantuty() {
        LowStock.clear();
        for (int i = 0; i < products.size(); i++) {
            if (products[i]->getQuantityInStock() < 10) {
                std::cout << products[i]->getName() << " low amount" << std::endl;
                LowStock.push_back(products[i]);
            }

        }
    }
    int ShowQuantity(const std::string& productName) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i]->getName() == productName) {

                std::cout << products[i]->getQuantityInStock() << std::endl;
                return products[i]->getQuantityInStock();
            }
        }
    }
    void Delete(const std::string& productName) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i]->getName() == productName) {
            
                std::cout << "Deleted " <<productName << std::endl;
                products.erase(products.begin() + i);
            }
        
        }
    }



private:
    std::vector<std::shared_ptr<Product>> products;

    std::vector<std::shared_ptr<Product>> LowStock;
};
class Order {
public:
    Order(std::string& cust) : customer(cust), orderID(GenerateId()){}
    void addProduct(const std::shared_ptr<Product>& newProduct) {
        products.push_back(newProduct);
    }

    void setTotalCost() {
        
        for (int i = 0; i < products.size(); i++) {
            totalCost+= products[i]->getPrice();
        }
    }
    void changeStatus(std::string& newStatus) {
        orderStatus = newStatus;
    }

    int getTotalCost() {
        return totalCost;
    }
    void shipProduct(Inventory& inventory, const std::string& productName) {
        int quantity = inventory.ShowQuantity(productName);
        if (quantity > 0) {
            inventory.UpdateQuantuty(productName, quantity - 1);
            std::string status = "Shipped";
            this->changeStatus(status);
            std::cout << "Product shipped: " << productName <<" for " <<customer <<std::endl;
           
        }
        else {
            std::cout << "No product: " << productName << std::endl;
            
        }
    }
private:
    std::string orderID; 
    std::string customer;
    std::vector<std::shared_ptr<Product>> products;
    int totalCost;
    std::string orderStatus;
    std::mt19937 rng;
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

class ProductCatalog {
public:
    ProductCatalog(){}
    void AddProduct(const std::shared_ptr<Product>& Product) {
        products.push_back(Product);
    }


    void UpdateElectronicProduct(const std::string& productName, const std::string& newBrand, const std::string& newModel, int newPowerConsumption, const std::string& newName, int newPrice) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i]->getName() == productName) {
                //converting base class to derived one (electronics)
                std::shared_ptr<Electronics> electronicPtr = std::dynamic_pointer_cast<Electronics>(products[i]);
                    electronicPtr->setBrand(newBrand);
                    electronicPtr->setModel(newModel);
                    electronicPtr->setPowerConsumption(newPowerConsumption);
                    products[i]->SetName(newName);
                    products[i]->SetPrice(newPrice);
            }
        }
    }


    void UpdateBookProduct(const std::string& productName, const std::string& newAuthor, const std::string& newGenre, const std::string& newISBN, const std::string& newName, int newPrice) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i]->getName() == productName) {
                std::shared_ptr<Books> BookPtr = std::dynamic_pointer_cast<Books>(products[i]);
                BookPtr->setAuthor(newAuthor);
                BookPtr->setGenre(newGenre);
                BookPtr->setISBN(newISBN);
                products[i]->SetName(newName);
                products[i]->SetPrice(newPrice);
            }
        }
    }

    void UpdateClothongProduct(const std::string& productName, const std::string& newSize, const std::string& newColor, const std::string& newMaterial, const std::string& newName, int newPrice) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i]->getName() == productName) {
                std::shared_ptr<Clothing> ClothPtr = std::dynamic_pointer_cast<Clothing>(products[i]);
                ClothPtr->setColor(newColor);
                ClothPtr->setSize(newSize);
                ClothPtr->setMaterial(newMaterial);
                products[i]->SetName(newName);
                products[i]->SetPrice(newPrice);
            }
        }
    }

    void RemoveProduct(const std::string& productName) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i]->getName() == productName) {
            products.erase(products.begin() + i);
            break; 
        }
    }
}

    void ViewList() {
        for (int i = 0; i < products.size(); i++) {
            std::string ProductEl=products[i]->getName();
            std::cout << ProductEl << ", Price:" << products[i]->getPrice() <<"Quantity:" << products[i]->getQuantityInStock() <<" Id:" << products[i]->getID() <<std::endl;
        }
    }
private:
    std::vector<std::shared_ptr<Product>> products;
    
};

class Command {

public:
    Command() {
        fileConfig.ReadReturn("C:/Users/Давід/source/repos/OOP2/OOP2/config.txt");
        std::vector<std::shared_ptr<Product>> configProducts = fileConfig.GiveInfo();
        for (int i = 0; i < configProducts.size(); i++) {
            std::shared_ptr<Books> book = std::dynamic_pointer_cast<Books>(configProducts[i]);
            std::shared_ptr<Electronics> elec = std::dynamic_pointer_cast<Electronics>(configProducts[i]);
            if (book) {
                book->setISBN("ggvvvvsdgg");
            }
            if (elec)
            {
                elec->setPowerConsumption(11);
            }

            configProducts[i]->displayDetails();
            std::cout << "-------" << std::endl;
            catalog.AddProduct(configProducts[i]);
            inventory.AddItem(configProducts[i]);



        }

    }
    void CommandINput() {
        std::cout << "1-View Products, 2-Delete Product, 3-Update Quantity, 4-Update Product, 5-buy some\n";


        while (true) {
            int choice;
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1: {
                catalog.ViewList();
                break;
            }
            case 2: {
                std::string name;
                std::cin >> name;
                catalog.RemoveProduct(name);
                inventory.Delete(name);
                break;
            }
            case 3: {
                std::string name;
                std::cin >> name;
                int nQuantiy;
                std::cin >> nQuantiy;
                inventory.UpdateQuantuty(name, nQuantiy);
                break;
            }
            case 4: {
                std::string Choice;
                std::cin >> Choice;
                if (Choice == "el")
                {
                    std::string name;
                    std::string Brand;
                    std::string Model;
                    int Power;
                    std::string NewName;
                    int newPrice;

                    std::cin >> name;
                    std::cin >> Brand;
                    std::cin >> Model;
                    std::cin >> Power;
                    std::cin >> NewName;
                    std::cin >> newPrice;
                    catalog.UpdateElectronicProduct(name, Brand, Model, Power, NewName, newPrice);
                }
                else if (Choice == "bo") {

                    std::string name;
                    std::string newAuthor;
                    std::string newGenre;
                    std::string ISBN;
                    std::string NewName;
                    int newPrice;

                    std::cin >> name;
                    std::cin >> newAuthor;
                    std::cin >> newGenre;
                    std::cin >> ISBN;
                    std::cin >> NewName;
                    std::cin >> newPrice;
                    catalog.UpdateBookProduct(name, newAuthor, newGenre, ISBN, NewName, newPrice);
                }
                else if (Choice == "cl") {

                    std::string name;
                    std::string newSize;
                    std::string newColor;
                    std::string newMaterial;
                    std::string NewName;
                    int newPrice;

                    std::cin >> name;
                    std::cin >> newSize;
                    std::cin >> newColor;
                    std::cin >> newMaterial;
                    std::cin >> NewName;
                    std::cin >> newPrice;
                    catalog.UpdateClothongProduct(name, newSize, newColor, newMaterial, NewName, newPrice);

                }
                break;
            }
            case 5: {
                std::string nema = "For Me";
                std::string desired;
                std::cin >> desired;
                Order order(nema);
                order.shipProduct(inventory, desired);
                break;
            }
            default:
                std::cout << "Wrong number\n";
                break;
            }
        }
    }
private:
    FileConfig fileConfig;
    ProductCatalog catalog;
    Inventory inventory;
};

int main()
{
    
    Command Programm;
    Programm.CommandINput();
    

    
}


