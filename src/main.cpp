#include "Client.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    cout << "Client Read In" << endl;
    Client::Load();
    //vector<Client> Client::clients;
    
    //Print out Client Information
    vector<Client> clients = Client::GetAll();
    for(int i = 0; i < clients.size(); i++) {
        //cout << clients.at(i).getType() << endl;
        Client c = clients.at(i);
        cout << c.getFullName() << " - " << c.getShortAddress() << endl;
    }

    //Add a new Client
    Client::AddClient("Test", "Man", "123 Test St.", "", "Chicago", "IL", "98765");
    Client::Save();

    cin.get();
    return 0;
}