#include "Person.h"

#include <string>

using namespace std;

Person::Person(int id, string firstName, string lastName) {
    ID = id;
    this->firstName = firstName;
    this->lastName = lastName;
}