#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

class Client: public Person {
    private:
        static const string FILENAME;
        static vector<Client> clients;
        static map<int, int> client_index;
        static int auto_increment;
    public:
        Client(int id, string firstName, string lastName,
        string streetAddress1, string streetAddress2,
        string city, string state, string zipCode)
            : Person{id, firstName, lastName, streetAddress1,
            streetAddress2, city, state, zipCode}
            {
            }
        string getType() {
            return "Client";
        }
        string GetDetails() {
            return getFullName() + "/n" +
                getFullAddress() + "/n";
        }

        //Public Static Members
        static vector<Client> GetAll();
        static Client Get(int id);
        static void AddClient(string fn, string ln, string sa1, string sa2, string cty, string st, string zc);
        static void UpdateClient(Client);

        //Data Interaction
        static void Load();
        static void Save();
};

#endif