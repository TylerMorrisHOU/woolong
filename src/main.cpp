#include "Client.h"
#include "SalesRep.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
    //Client Read In
    vector<Client> clients;
    ifstream clientFile("Clients.csv");
    if(!clientFile.is_open()) throw runtime_error("Could not open clients");

    string line;
    while(getline(clientFile, line)) {
        stringstream ss(line);
        int id;
        string firstName, lastName;
        ss >> id >> firstName >> lastName;

        Client newClient(id, firstName, lastName);
        clients.push_back(newClient);
    }

    clientFile.close();

    for(int i = 0; i < clients.size(); i++) {
        cout << clients.at(i).getType() << endl;
    }

    return 0;
}