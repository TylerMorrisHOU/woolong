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
        float cost;

        //Static
        static const string PRODUCT_FILE;
        static vector<Product*> products;
        static map<int, int> product_index;
        static int auto_increment;

    public:
        Product();
        Product(int id, string name, string description, float cost);

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

        float getCost() {
            return cost;
        }

        void PrintShort();
        void PrintDetails();
        void PrintSalesReport();

        //Setters
        void setName(string n) {
            name = n;
        }

        void setDescription(string d) {
            description = d;
        }

        void setCost(float c) {
            cost = c;
        }

        //Public Static
        static vector<Product*> Get();
        static Product* Get(int id);
        static Product* AddNew(string n, string d, float c);
        static void Update(Product* p);

        static void Load();
        static void Save();

};

#endif