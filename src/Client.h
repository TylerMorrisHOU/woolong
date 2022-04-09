#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

class Client: public Person {
    private:
        static vector<Client> clients;
        static map<int, int> client_index;
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
        //Public Static Members
        static vector<Client> GetAll();
        static Client Get(int id);
        static void AddClient(Client);
        static void UpdateClient(Client);
        // static string GetDetails(int id);
        string GetDetails();
        
};

#endif