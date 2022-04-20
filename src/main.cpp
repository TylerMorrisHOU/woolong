#include "Client.h"

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

    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}