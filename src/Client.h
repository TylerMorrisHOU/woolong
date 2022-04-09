#include "Person.h"

#include <string>

using namespace std;

class Client: public Person {
    public:
        Client(int id, string firstName, string lastName);
        string getType() {
            return "Client";
        }
};