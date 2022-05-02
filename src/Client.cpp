#include "Client.h"
#include "Sale.h"

#include <string>
#include <vector>
#include <map>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

const string Client::CLIENT_FILE = "db/Clients.csv";
vector<Client*> Client::clients;
map<int, int> Client::client_index; //<id, vector_pos>
int Client::auto_increment = 1; //next highest id

// static vector<Client*> client_vec;

//Static Functions
vector<Client*> Client::Get() {
    // static vector<Client*> client_vec;
    return clients;
}

Client* Client::Get(int id) {
    auto result = client_index.find(id);
    return clients.at(result->second);
}

Client* Client::AddNew(string fn, string ln, string sa1, string sa2, string cty, string st, string zc) {
    int c_pos = clients.size();

    //Make Client
    Client* c = new Client(auto_increment, fn, ln, sa1, sa2, cty, st, zc);
    clients.push_back(c);

    //Auto Increment the Id
    auto_increment++;

    client_index.insert(pair<int, int>(c->getID(), c_pos));

    return c;
}

void Client::Update(Client* c) {
    //c = Client::Get(c.id);
    auto c_pos = client_index.find(c->getID())->second;
    clients.at(c_pos) = c;
}

void Client::PrintShort() {
    float totalClientSales = 0.0;
    vector<Sale*> clientSales = Sale::GetByClient(getID());

    for(auto it = clientSales.begin(); it != clientSales.end(); ++it)
        totalClientSales += (*it)->getSaleTotal();

    cout.precision(2);
    cout <<"(" << getID() << "): " << getFullName() << " - " << getShortAddress() << " - $" << fixed << totalClientSales << " in total sales" << endl;
}

void Client::Load() {
    try
    {
        ifstream clientFile;
        clientFile.open("./" + CLIENT_FILE); //Relative to Project Root
        if(clientFile.is_open()) {
            cout << "Client file is open for Load..." << endl;
            string line;
            int count = 0;
            while(getline(clientFile, line)) { //Comma-delimited file
                //cout << line << endl;
                stringstream ss(line);
                string word;
                vector<string> words;

                while(getline(ss, word, ',')) {
                    //cout << word << endl;
                    words.push_back(word);
                }

                // ss << words.at(0);
                int id;
                // ss >> id;
                id = stoi(words.at(0));
                //cout << "Loading Client Id " << id << "..." << endl;
                //string firstName = words.at(1);
                //string lastName = words.at(2);
                //streetAddress1, streetAddress2, city, state, zipCode;
                //ss >> id >> firstName >> lastName >> streetAddress1 >> streetAddress2 >> city >> state >> zipCode;

                Client* c = new Client(id, words.at(1), words.at(2), words.at(3), words.at(4), words.at(5), words.at(6), words.at(7));
                clients.push_back(c);
                client_index.insert(pair<int, int>(id, count));
                count++;

                //Insure that auto increment counter starts higher than anything in the CSV file
                //id = c->getID();
                if(id >= auto_increment)
                    auto_increment = id + 1;

                words.clear();
            }
            cout << "Client file successfully loaded, close file..." << endl;
            clientFile.close();
        } else {
            cout << "Could not open clients" << endl;
        }//throw runtime_error("Could not open clients");
    } catch (char const *ex) {
        cout << ex << endl;
    }
}

void Client::Save() {
    try
    {
        ofstream clientFile;
        clientFile.open("./" + CLIENT_FILE, ios::trunc); //Truncate to Overwrite

        if(clientFile.is_open()) {
            for(int i = 0; i < clients.size(); i++) {
                //Write each client
                Client* c = clients.at(i);

                //Columns
                clientFile << c->getID() << "," << c->getFirstName() << ","
                    << c->getLastName() << ","
                    << c->getStreetAddress1() << "," << c->getStreetAddress2() << ","
                    << c->getCity() << "," << c->getState() << ","
                    << c->getZipCode() << endl;
            }

            clientFile.close();
        } else {
            cout << "Could not write to Clients" << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
}
