#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
class Product {
    
public:
   
    Product(std::string n, int priceProd, int q) :productID(GenerateId()), name(n), price(priceProd), quantityInStock(q) {}


    void SetName(std::string NameNew) {
        name = NameNew;
    }
    void SetProId(std::string PId) {
        productID = PId;
    }
    void SetPrice(int newPrice) {
        price = newPrice;
    }
    void Setquantity(int newQuantity) {
        quantityInStock =newQuantity;
    }
    std::string getName() {
        return name;
    }
    int getPrice() {
        return price;
    }
    int getQuantityInStock() {
        return quantityInStock;
    }
    std::string getID() {
        return productID;
    }
    int totalPrice() {
        return quantityInStock * price;
    }
private:
    std::string productID;
    std::string name;
    int price;
    int quantityInStock;
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
    std::string getBrand()  {
        return brand;
    }
    std::string getModel()  {
        return model;
    }
    int getPowerConsumption() {
        return powerConsumption;
    }

    void DisplayPowerConsumption() {
        std::cout<<"Power consumption is: " << powerConsumption << std::endl;
    }
private:
    std::string brand;
    std::string model;
    int powerConsumption;
};


class Books : public Product {
public:
    Books(std::string n, int priceProd, int q, std::string a, std::string g, std::string IN) : Product(n, priceProd, q), author(a), genre(g), ISBN(IN) {}
  
    std::string getAuthor() {
        return author;
    }
    std::string getGenre() {
        return genre;
    }
    std::string getISBN() {
        return ISBN;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }
    void setGenre(const std::string& newGenre) {
        genre = newGenre;
    }
    void setISBN(int newISBN) {
        ISBN = newISBN;
    }

    void DisplayPowerConsumption() {
        std::cout<<"Author is: " << author << std::endl;
    }
private:
    std::string author;
    std::string genre;
    std::string ISBN;
};


class Clothing : public Product {
public:
    Clothing(std::string n, int priceProd, int q, std::string s, std::string c, std::string m) : Product( n, priceProd, q), size(s), color(c), material(m) {}
  
    std::string getSize() {
        return size;
    }
    std::string getMaterial() {
        return material;
    }
    std::string getColor() {
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
private:
    std::string size;
    std::string color;
    std::string material;
};

class Inventory {
    Inventory() {}
};
int main()
{
    std::cout << "ff" << std::endl;
}


