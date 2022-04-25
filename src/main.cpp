#include "Client.h"
#include "SalesRep.h"

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

    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}