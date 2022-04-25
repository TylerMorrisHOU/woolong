#include "SalesRep.h"

#include <string>
#include <vector>
#include <map>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

const string SalesRep::REP_FILE = "db/SalesReps.csv";
vector<SalesRep*> SalesRep::salesReps;
map<int, int> SalesRep::salesRep_index;
int SalesRep::auto_increment = 1;

vector<SalesRep*> SalesRep::Get() {
    return salesReps;
}

SalesRep* SalesRep::Get(int id) {
    auto result = salesRep_index.find(id);
    return salesReps.at(result->second);
}

SalesRep* SalesRep::AddNew(string fn, string ln, string sa1,
string sa2, string cty, string st, string zc) {
    int s_pos = salesReps.size();

    SalesRep* s = new SalesRep(auto_increment, fn, ln, sa1, sa2, cty, st, zc);
    salesReps.push_back(s);

    auto_increment++;

    salesRep_index.insert(pair<int, int>(s->getID(), s_pos));

    return s;
}

void SalesRep::Update(SalesRep* s) {
    int s_pos = salesRep_index.find(s->getID())->second;
    salesReps.at(s_pos) = s;
}

void SalesRep::PrintShort() {
    cout << this->getFullName() << " - " << this->getShortAddress() << endl;
    //TODO: Sales To Date
}

void SalesRep::PrintDetails() {
    cout << this->getFullName() << endl;
    //TODO: Finish detailss
}

void SalesRep::Load() {
    try {
        ifstream salesRepFile;
        salesRepFile.open("./" + REP_FILE);
        if(salesRepFile.is_open()) {
            cout << "Sales Rep file is open for Load..." << endl;

            string line;
            while(getline(salesRepFile, line)) {
                stringstream ss(line);
                string word;
                vector<string> words;

                //Comma-delimited parsing
                while(getline(ss, word, ',')) {
                    words.push_back(word);
                }

                //String->Int conversion
                ss << words.at(0);
                int id;
                ss >> id;

                SalesRep* s = new SalesRep(id, words.at(1), words.at(2), words.at(3), words.at(4), words.at(5), words.at(6), words.at(7));
                salesReps.push_back(s);

                //Set auto increment
                if(id >= auto_increment)
                    auto_increment = id + 1;
            }

            cout << "Sales Rep file successfully loaded, closing file..." << endl;
            salesRepFile.close();
        } else {
            cout << "Could not open sales reps file!" << endl;
        }
    } catch (char const* ex) {
        cout << ex << endl;
    }
}

void SalesRep::Save() {
    try {
        ofstream salesRepFile;
        salesRepFile.open("./" + REP_FILE, ios::trunc);

        if(salesRepFile.is_open()) {
            for(int i = 0; i < salesReps.size(); i++) {
                SalesRep* s = salesReps.at(i);

                //Write Sales Rep Columns
                salesRepFile << s->getID() << ","
                    << s->getFirstName() << ","
                    << s->getLastName() << ","
                    << s->getStreetAddress1() << ","
                    << s->getStreetAddress2() << ","
                    << s->getCity() << ","
                    << s->getState() << ","
                    << s->getZipCode() << endl;
            }

            salesRepFile.close();
        } else {
            cout << "Could not write to Sales Rep File!" << endl;
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}