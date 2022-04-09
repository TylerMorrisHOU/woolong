#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
    protected:
        int ID;
        string firstName;
        string lastName;
    public:
        Person(int id, string firstName, string lastName);
        string streetAddress1;
        string streetAddress2;
        string city;
        string state;
        string zipCode;
        virtual string getType() = 0;
};

#endif