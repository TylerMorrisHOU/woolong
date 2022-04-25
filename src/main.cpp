#include "Client.h"
#include "SalesRep.h"
#include "Product.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    // cout << "Hello World" << endl;
    cout << "Reading in Client file..." << endl;
    Client::Load();
    // vector<Client> Client::clients;
    
    //Print out Client Information
    //vector<Client> clients = Client::GetClients();
    for(int i = 0; i < Client::Get().size(); i++) {
        Client* c = Client::Get(i);
        // cout << c->getType() << endl;
        // Client c = clients.at(i);
        cout << c->getFullName() << " - " << c->getShortAddress() << endl;
    }

    //Add a new Client
    Client::AddNew("Test", "Man", "123 Test St.", "", "Chicago", "IL", "98765");
    Client::Save();

    cout << "Client functions over." << endl;
    cout << endl;

    // ----- Sales Rep Section -----
    cout << "Starting Sales Rep functions..." << endl;
    SalesRep::Load();

    //2b) List all your current salesReps - name, short address, sales to date
    for(int i = 0; i < SalesRep::Get().size(); i++) {
        SalesRep* s = SalesRep::Get(i);
        s->PrintShort();
    }

    //2d) Add a new salesRep
    SalesRep::AddNew("Sales", "Dude", "456 Not My Ave.", "Ste.1", "Houston", "TX", "11234");
    

    //2g) Save updated salesRep information to file
    SalesRep::Save();

    cout << "Sales Rep functions over." << endl;
    cout << endl;

    // ----- -----
    // Product Functionality
    // ---- -----

    //3a) Read Sales History from a file
    Product::Load();

    //3b) List current Products
    //TODO: Including current sales
    for(int i = 0; i < Product::Get().size(); i++) {
        Product* p = Product::Get(i);
        p->PrintShort();
    }

    //3c) List all information for a specific Product
    //TODO: p->PrintDetails()

    //3d) Add a new Product
    Product::AddNew("A Cookie", "Some kind of yummy pastry maybe", 10);

    //3e) Update a Product
    //TODO

    //3f) Montly Sales Report of a Product
    //TODO

    //3g) Save to a file
    Product::Save();
    cout << "Product functionality over." << endl;
    cout << endl;

    // ----- Sales Functions -----

    //4a) Read Sales History from a file
    //TODO

    //4b) Purchase a Product (Client->Product)
    //TODO

    //4c) List all Sales for the year
    //TODO

    //4d) List all Sales for the year, specific client (Client->Sales)
    //TODO

    //4e) Update specific Sale
    //TODO

    //4f) Save Sales File
    //TODO

    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}