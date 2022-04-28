#include "Client.h"
#include "SalesRep.h"
#include "Product.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    // ----- Client Section -----

    //1a) Read client information from a file
    cout << "Reading in Client file..." << endl;
    Client::Load();
    
    //Print out Client Information
    //1b) List all current clients - name, short address, sales to date
    for(int i = 0; i < Client::Get().size(); i++) {
        Client* c = Client::Get(i);
        c->PrintShort();
    }

    //1d) Add a new Client
    Client* newClient = Client::AddNew("Test", "Man", "123 Test St.", "", "Chicago", "IL", "98765");

    //1c) List all information for a specific client
    newClient->PrintDetails();

    //1e) Update a Client
    newClient->setCity("Miwaukee");
    newClient->setState("WI");
    Client::Update(newClient);
    //Print to confirm
    newClient->PrintDetails();

    //1f) Save client information to the file
    Client::Save();

    cout << "Client functions over. Press any key to continue..." << endl;
    cin.get();
    cout << endl;

    // ----- Sales Rep Section -----
    cout << "Starting Sales Rep functions..." << endl;

    //2a) Read Sales Rep information from file
    SalesRep::Load();

    //2b) List all your current salesReps - name, short address, sales to date
    for(int i = 0; i < SalesRep::Get().size(); i++) {
        SalesRep* s = SalesRep::Get(i);
        s->PrintShort();
    }

    //2d) Add a new salesRep
    SalesRep* newRep = SalesRep::AddNew("Sales", "Dude", "456 Not My Ave.", "Ste.1", "Houston", "TX", "11234");
    
    //2c) List all information for specific sales rep
    newRep->PrintDetails();

    //2e) Update Sales Rep Information
    newRep->setFirstName("Super");
    newRep->setLastName("Man");
    SalesRep::Update(newRep);
    //Print to Confirm
    newRep->PrintDetails();

    //2g) Save updated salesRep information to file
    SalesRep::Save();

    cout << "Sales Rep functions over. Press any key to continue..." << endl;
    cin.get();
    cout << endl;

    // ----- Product Section -----

    //3a) Read Product Information from a file
    Product::Load();

    //3b) List current Products
    //TODO: Including current sales
    for(int i = 0; i < Product::Get().size(); i++) {
        Product* p = Product::Get(i);
        p->PrintShort();
    }

    //3d) Add a new Product
    Product* p = Product::AddNew("A Cookie", "Some kind of yummy pastry maybe", 1.50, 10);

    //3c) List all information for a specific Product
    p->PrintDetails();

    //3e) Update a Product
    p->setName("Lots more Cookies");
    p->setInventory(100);
    Product::Update(p);
    //Print to Test
    p->PrintDetails();

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