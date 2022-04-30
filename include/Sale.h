#ifndef SALES_H
#define SALES_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Sale {
    private:
        int id;
        int clientId;
        int salesRepId;
        int productId;
        int amountSold;
        //float costPerUnit;
        float saleTotal;
        //Static
        static const string SALES_FILE;
        static vector<Sale*> sales;
        static map<int, int> sales_index;
        static int auto_increment;
    public:
        //Constructors
        Sale();
        Sale(int id, int clientId, int repId, int productId,
            int amountSold, float saleTotal);

        //Setters
        void setClientId(int id) {
            clientId = id;
        }
        void setSalesRepId(int id) {
            salesRepId = id;
        }
        void setProductId(int id) {
            productId = id;
        }
        void setAmountSold(int amount) {
            amountSold = amount;
        }
        void setSaleTotal(float total) {
            saleTotal = total;
        }

        //Getters
        int getID() {
            return id;
        }
        int getClientId() {
            return clientId;
        }
        int getSalesRepId() {
            return salesRepId;
        }
        int getProductId() {
            return productId;
        }
        int getAmountSold() {
            return amountSold;
        }
        float getSaleTotal() {
            return saleTotal;
        }

        void Print();

        //Static Functions
        static vector<Sale*> Get();
        static vector<Sale*> GetByClient(int clientId);
        static Sale* Get(int id);
        static Sale* Purchase(int clientId, int salesRepId, int productId, int amountSold);
        static void Update(Sale* s);

        static void Load();
        static void Save();
};

#endif