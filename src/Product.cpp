#include "Product.h"

#include <string>
#include <vector>
#include <map>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

const string Product::PRODUCT_FILE = "db/Products.csv";
vector<Product*> Product::products;
map<int, int> Product::product_index;
int Product::auto_increment = 1;

Product::Product() {
    this->id = 0;
    this->name = "";
    this->description = "";
    this->inventory = 0;
}

Product::Product(int id, string name, string description, int inventory) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->inventory = inventory;
}

void Product::PrintShort() {

}

void Product::PrintDetails() {

}

vector<Product*> Product::Get() {
    return products;
}

Product* Product::Get(int id) {
    auto result = product_index.find(id);
    return products.at(result->second);
}


Product* Product::AddNew(string n, string d, int i) {
    int p_pos = products.size();

    //Make Product
    Product* p = new Product(auto_increment, n, d, i);
    products.push_back(p);

    //Auto Increment
    auto_increment++;

    product_index.insert(pair<int, int>(p->getID(), p_pos));
    return p;
}

void Product::Update(Product* p) {
    int p_pos = product_index.find(p->getID())->second;
    products.at(p_pos) = p;
}

void Product::Load() {
    try {
        ifstream productFile;
        productFile.open("./" + PRODUCT_FILE);

        if(productFile.is_open()) {
            cout << "Proudct file is open for Load..." << endl;

            string line;
            while(getline(productFile, line)) {
                stringstream ss(line);
                string word;
                vector<string> words;

                while(getline(ss, word, ',')) {
                    words.push_back(word);
                }

                ss << words.at(0);
                int id;
                ss >> id;

                ss << words.at(3);
                int inventory;
                ss >> inventory;

                Product* p = new Product(id, words.at(1), words.at(2),
                    inventory);
                products.push_back(p);

                if(id >= auto_increment)
                    auto_increment = id + 1;
            }

            cout << "ProductFiel successfully loaded. Closing file..." << endl;
            productFile.close();
        } else {
            cout << "Could not open products!" << endl;
        }
    } catch( char const *ex) {
        cerr << ex << endl;
    }
}

void Product::Save() {
    try {
        ofstream productFile;
        productFile.open("./" + PRODUCT_FILE, ios::trunc);

        if(productFile.is_open()) {
            for(int i = 0; i < products.size(); i++) {
                Product* p = products.at(i);

                productFile <<p->getID() << ","
                    << p->getName() << ","
                    << p->getDescription() << ","
                    << p->getInventory() << endl;
            }

            productFile.close();
        } else {
            cout << "Could not write to Products.csv!" << endl;
        }
    } catch(const exception& e) {
        cerr << e.what() << endl;
    }
}