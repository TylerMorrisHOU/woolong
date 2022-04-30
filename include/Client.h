#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

class Client: public Person {
    private:
        static const string CLIENT_FILE;
        static vector<Client*> clients;
        static map<int, int> client_index;
        static int auto_increment;
    public:
        //Constructors
        Client():Person(){};
        Client(int id, string firstName, string lastName,
        string streetAddress1, string streetAddress2,
        string city, string state, string zipCode)
            : Person(id, firstName, lastName, streetAddress1,
            streetAddress2, city, state, zipCode){}

        string getType() {
            return "Client";
        }

        void PrintShort();
        //void PrintDetails();

        //Public Static Members
        static vector<Client*> Get();
        static Client* Get(int id);
        static Client* AddNew(string fn, string ln, string sa1, string sa2, string cty, string st, string zc);
        static void Update(Client* c);

        //Data Interaction
        static void Load();
        static void Save();
};

#endif