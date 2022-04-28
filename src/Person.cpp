#include "Person.h"

#include <string>
#include <iostream>

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

void Person::PrintShort() {
    cout << getFullName() << " - " << getShortAddress() << endl;
}

void Person::PrintDetails() {
    cout << "First Name: " << getFirstName() << endl;
    cout << "Last Name: " << getLastName() << endl;
    cout << "Address: " << getStreetAddress1() << endl;
    cout << "       : " << getStreetAddress2() << endl;
    cout << "       : " << getCity() << ", " << getState() << " " << getZipCode() << endl;
}