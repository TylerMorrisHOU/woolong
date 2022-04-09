#include "Client.h"

#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

const string Client::FILENAME = "Clients.csv";
vector<Client> Client::clients;
map<int, int> Client::client_index; //<id, vector_pos>

//Static Functions
vector<Client> Client::GetAll() {
    return clients;
}

Client Client::Get(int id) {
    auto result = client_index.find(id);
    return clients.at(result->second);
}

void Client::AddClient(Client c) {
    int c_pos = clients.size();
    clients.push_back(c);
    client_index.insert(pair<int, int>(c.id, c_pos));
}

void Client::UpdateClient(Client c) {
    //c = Client::Get(c.id);
    int c_pos = client_index.find(c.id)->second;
    clients.at(c_pos) = c;
}

void Client::Save() {
    ofstream clientFile("./" + FILENAME, ios::trunc); //Truncate to Overwrite
}