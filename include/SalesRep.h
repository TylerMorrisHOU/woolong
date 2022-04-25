#ifndef SALES_REP_H
#define SALES_REP_H

#include "Person.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

class SalesRep: public Person {
    private:
        static const string REP_FILE;
        static vector<SalesRep*> salesReps;
        static map<int, int> salesRep_index;
        static int auto_increment;
    public:
        //Constructors
        SalesRep() : Person(){}
        SalesRep(int id, string firstName, string lastName,
            string streetAddress1, string streetAddress2,
            string city, string state, string zipCode)
            : Person(id, firstName, lastName, streetAddress1,
            streetAddress2, city, state, zipCode)
            {}
        string getType() {
            return "SalesRep";
        }
        string GetDetails() {
            return getFullName() + "/n" +
                getFullAddress() + "/n";
                //TODO: Sales To Date
        }
        void PrintShort();
        void PrintDetails();

        static vector<SalesRep*> Get();
        static SalesRep* Get(int id);
        static SalesRep* AddNew(string fn, string ln, string sa1,
            string sa2, string cty, string st, string zc);
        static void Update(SalesRep* s);

        static void Load();
        static void Save();
};

#endif
