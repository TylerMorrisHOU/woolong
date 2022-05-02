#include "Sale.h"
#include "Client.h"
#include "SalesRep.h"
#include "Product.h"

#include <string>
// #include <ctime>

#include <vector>
#include <map>
#include <algorithm>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

const string Sale::SALES_FILE = "db/Sales.csv";
vector <Sale*> Sale::sales;
map<int, int> Sale::sales_index;
int Sale::auto_increment = 1;

Sale::Sale() {
    this->id = 0;
    this->clientId = 0;
    this->salesRepId = 0;
    this->productId = 0;
    this->amountSold = 0;
    this->saleTotal = 0.0;
    this->monthSold = (rand() % 12) + 1;
}

Sale::Sale(int id, int clientId, int salesRepId, int productId, int amountSold, float saleTotal, int monthSold) {
    this->id = id;
    this->clientId = clientId;
    this->salesRepId = salesRepId;
    this->productId = productId;
    this->amountSold = amountSold;
    this->saleTotal = saleTotal;
    this->monthSold = monthSold;    
}

void Sale::Print() {
    Client* client = Client::Get(clientId);
    std::cout << "Client Name: " << client->getFullName() << endl;

    SalesRep* salesRep = SalesRep::Get(salesRepId);
    std::cout << "Sales Rep Name: " << salesRep->getFullName() << endl;

    Product* product = Product::Get(productId);
    std::cout << "Product Sold: " << product->getName() << endl;

    std::cout << "Number Sold: " << amountSold << endl;
    cout.precision(2);
    std::cout << "Price per Unit: " << fixed << product->getCost() << endl;

    std::cout << "Total Sale (in dollars): " << fixed << saleTotal << endl;

    cout << endl;
}

//Static Implementation
vector<Sale*> Sale::Get() {
    return sales;
}

vector<Sale*> Sale::GetByClient(int clientId) {
    vector<Sale*> clientSales;
    copy_if(sales.begin(), sales.end(), back_inserter(clientSales), [clientId](Sale* s) {
        return s->getClientId() == clientId;
    });
    return clientSales;
}

vector<Sale*> Sale::GetByProduct(int productId) {
    vector<Sale*> productSales;
    copy_if(sales.begin(), sales.end(), back_inserter(productSales), [productId](Sale* s) {
        return s->getProductId() == productId;
    });

    return productSales;
}

vector<Sale*> Sale::GetBySalesRep(int salesRepId) {
    vector<Sale*> repSales;
    copy_if(sales.begin(), sales.end(), back_inserter(repSales), [salesRepId](Sale* s) {
        return s->getSalesRepId() == salesRepId;
    });

    return repSales;
}

vector<Sale*> Sale::GetByMonth(int month) {
    vector<Sale*> monthlySales;
    copy_if(sales.begin(), sales.end(), back_inserter(monthlySales), [month](Sale* s) {
        return s->getMonthSold() == month;
    });

    return monthlySales;
}

Sale* Sale::Get(int id) {
    auto result = sales_index.find(id);
    return sales.at(result->second);
}

Sale* Sale::Purchase(int clientId, int salesRepId, int productId, int amountSold, int monthSold) {
    int s_pos = sales.size();

    //Get Cost per Unit (from Product)
    float costPerUnit = Product::Get(productId)->getCost();
    //Get Total Cost
    float total = costPerUnit * amountSold;
    //Make Sale
    Sale* s = new Sale(auto_increment, clientId, salesRepId, productId, amountSold, total, monthSold);
    sales.push_back(s);

    auto_increment++;

    sales_index.insert(pair<int, int>(s->getID(), s_pos));
    return s;
}

void Sale::Update(Sale* s) {
    int s_pos = sales_index.find(s->getID())->second;
    sales.at(s_pos) = s;
}

void Sale::Load() {
    try {
        ifstream salesFile;
        salesFile.open("./" + SALES_FILE);

        if(salesFile.is_open()) {
            std::cout << "Sales file is open for Loading..." << endl;

            string line;
            int count = 0;

            while(getline(salesFile, line)) {
                stringstream ss(line);
                string word;
                vector<string> words;

                while(getline(ss, word, ',')) {
                    words.push_back(word);
                }

                //id,clientId,salesRepId,productId,amountSold,saleTotal
                // ss << words.at(0);
                int id;
                // ss >> id;
                id = stoi(words.at(0));

                // ss << words.at(1);
                int clientId;
                // ss >> clientId;
                clientId = stoi(words.at(1));

                // ss << words.at(2);
                int salesRepId;
                // ss >> salesRepId;
                salesRepId = stoi(words.at(2));

                // ss << words.at(3);
                int productId;
                // ss >> productId;
                productId = stoi(words.at(3));

                // ss << words.at(4);
                int amountSold;
                // ss >> amountSold;
                amountSold = stoi(words.at(4));

                // ss << words.at(5);
                float saleTotal;
                // ss >> saleTotal;
                saleTotal = stof(words.at(5));

                int monthSold;
                monthSold = stoi(words.at(6));

                Sale* s = new Sale(id, clientId, salesRepId, productId, amountSold, saleTotal, monthSold);
                sales.push_back(s);
                sales_index.insert(pair<int, int>(id, count));
                count++;

                if(id >= auto_increment)
                    auto_increment = id + 1;
            }

            std::cout << "Sales File successfully loaded. Closing file..." << endl;
            salesFile.close();
        } else {
            std::cout << "Could not open sales!" << endl;
        }
    } catch(char const *ex) {
        cerr << ex << endl;
    }
}

void Sale::Save() {
    try {
        ofstream salesFile;
        salesFile.open("./" + SALES_FILE, ios::trunc);

        if(salesFile.is_open()) {
            for(int i = 0; i < sales.size(); i++) {
                Sale* s = sales.at(i);

                salesFile << s->getID() << ","
                    << s->getClientId() << ","
                    << s->getSalesRepId() << ","
                    << s->getProductId() << ","
                    << s->getAmountSold() << ","
                    << s->getSaleTotal() << ","
                    << s->getMonthSold() << endl;
            }

            salesFile.close();
        } else {
            cout << "Could not write to Sales.csv!" << endl;
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}