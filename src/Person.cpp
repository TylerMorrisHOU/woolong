#include "Person.h"

#include <string>

using namespace std;

//Default Constructor
Person::Person() {
    this->id = 0;
    this->firstName = "";
    this->lastName = "";
    this->streetAddress1 = "";
    this->streetAddress2 = "";
    this->city = "";
    this->state = "";
    this->zipCode = "";
}

Person::Person(int id, string firstName, string lastName,
string streetAddress1, string streetAddress2,
string city, string state, string zipCode){
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->streetAddress1 = streetAddress1;
    this->streetAddress2 = streetAddress2;
    this->city = city;
    this->state = state;
    this->zipCode = zipCode;
}