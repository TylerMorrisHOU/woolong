#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
    protected:
        int id;
        string firstName;
        string lastName;
        string streetAddress1;
        string streetAddress2;
        string city;
        string state;
        string zipCode;
    public:
        //Constructors
        Person();
        Person(int id, string firstName, string lastName,
        string streetAddress1, string streetAddress2,
        string city, string state, string zipCode);
        virtual string getType() = 0;
        
        //Setters
        void setFirstName(string fn) {
            firstName = fn;
        }
        void setLastName(string ln) {
            lastName = ln;
        }
        void setStreetAddress(string sa1, string sa2 = "") {
            streetAddress1 = sa1;
            if(!sa2.empty()) {
                streetAddress2 = sa2;
            }
        }
        void setCity(string c) {
            city = c;
        }
        void setState(string s) {
            state = s;
        }
        void setZipCode(string zc) {
            zipCode = zc;
        }
        
        //Getters
        int getID() {
            return id;
        }
        string getFirstName() {
            return firstName;
        }
        string getLastName() {
            return lastName;
        }
        string getStreetAddress1() {
            return streetAddress1;
        }
        string getStreetAddress2() {
            return streetAddress2;
        }
        string getCity() {
            return city;
        }
        string getState() {
            return state;
        }
        string getZipCode() {
            return zipCode;
        }

        string getFullName() {
            return firstName + " " + lastName;
        }
        string getFullAddress() {
            string tempAddress = "";
            if(!streetAddress2.empty()) {
                tempAddress = streetAddress2 + "/n";
            }
            return streetAddress1 + "/n" + tempAddress
            + city + ", " + state + " " + zipCode;
        }
        string getShortAddress() {
            return city + ", " + state;
        }
};

#endif