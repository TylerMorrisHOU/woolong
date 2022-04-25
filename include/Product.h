#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Product {
    private:
        int id;
        string name;
        string description;
        int inventory;

        //Static
        static const string PRODUCT_FILE;
        static vector<Product*> products;
        static map<int, int> product_index;
        static int auto_increment;

    public:
        Product();
        Product(int id, string name, string description, int inventory);

        //Getters
        int getID() {
            return id;
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return description;
        }

        int getInventory() {
            return inventory;
        }

        void PrintShort();
        void PrintDetails();

        //Setters
        void setName(string n) {
            name = n;
        }

        void setDescription(string d) {
            description = d;
        }

        void setInventory(int i) {
            inventory = i;
        }

        //Public Static
        static vector<Product*> Get();
        static Product* Get(int id);
        static Product* AddNew(string n, string d, int i);
        static void Update(Product* p);

        static void Load();
        static void Save();

};

#endif