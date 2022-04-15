#include "Person.h"

#include <string>

using namespace std;

class SalesRep: public Person {
    public:
        string getType() {
            return "SalesRep";
        }
};