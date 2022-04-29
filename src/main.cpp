#include "Client.h"
#include "SalesRep.h"
#include "Product.h"
#include "Sale.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	// ----- LOAD ALL CSVs UPFRONT FOR AVAILABILITY
	//1a) Read client information from a file
	cout << "Reading in Files..." << endl;
	Client::Load();
	//2a) Read Sales Rep information from file
	SalesRep::Load();
	//3a) Read Product Information from a file
	Product::Load();
	//4a) Read Sales History from a file
	Sale::Load();
	cout << "Loading complete. Press any key to continue..." << endl;
	cin.get();
	cout << endl;

	// ----- Client Section -----
	
	//Print out Client Information
	//1b) List all current clients - name, short address, sales to date
	for(int i = 0; i < Client::Get().size(); i++) {
		Client::Get(i)->PrintShort();
	}
	cout << "Press any key to continue..." << endl;
	cin.get();
	cout << endl;

	//1d) Add a new Client
	Client* c = Client::AddNew("Test", "Man", "123 Test St.", "", "Chicago", "IL", "98765");

	//1c) List all information for a specific client
	c->PrintDetails();
	cout << endl;

	//1e) Update a Client
	c->setCity("Miwaukee");
	c->setState("WI");
	Client::Update(c);
	//Print to confirm
	c->PrintDetails();

	//1f) Save client information to the file
	Client::Save();

	cout << "Client functions over. Press any key to continue..." << endl;
	cin.get();
	cout << endl;

	// ----- Sales Rep Section -----
	cout << "Starting Sales Rep functions..." << endl;

	//2b) List all your current salesReps - name, short address, sales to date
	for(int i = 0; i < SalesRep::Get().size(); i++) {
		SalesRep::Get(i)->PrintShort();
	}

	//2d) Add a new salesRep
	SalesRep* r = SalesRep::AddNew("Sales", "Dude", "456 Not My Ave.", "Ste.1", "Houston", "TX", "11234");
	
	//2c) List all information for specific sales rep
	r->PrintDetails();

	//2e) Update Sales Rep Information
	r->setFirstName("Super");
	r->setLastName("Man");
	SalesRep::Update(r);
	//Print to Confirm
	r->PrintDetails();

	//2g) Save updated salesRep information to file
	SalesRep::Save();

	cout << "Sales Rep functions over. Press any key to continue..." << endl;
	cin.get();
	cout << endl;

	// ----- Product Section -----

	

	//3b) List current Products
	//TODO: Including current sales
	for(int i = 0; i < Product::Get().size(); i++) {
		Product::Get(i)->PrintShort();
	}
	cout << endl;

	//3d) Add a new Product
	Product* p = Product::AddNew("A Cookie", "Some kind of yummy pastry maybe", 1.50);

	//3c) List all information for a specific Product
	p->PrintDetails();
	cout << endl;

	//3e) Update a Product
	p->setName("Lots more Cookies");
	Product::Update(p);
	//Print to Test
	p->PrintDetails();

	//3f) Montly Sales Report of a Product
	//TODO

	//3g) Save to a file
	Product::Save();
	cout << "Product functionality over. Press any key to continue..." << endl;
	cin.get();
	cout << endl;

	// ----- Sales Functions -----

	//4c) List all Sales for the year
	cout << "How many Sales? " << Sale::Get().size() << endl;
	for(int i = 0; i < Sale::Get().size(); i++) {
		Sale::Get(i)->Print();
	}
	cout << endl;

	//4b) Purchase a Product, Make a Sale
	cout << "Trying to make a purchase..." << endl;
	Sale* s = Sale::Purchase(c->getID(), r->getID(), p->getID(), 2);
	cout << "Sale successful!" << endl;
	cout << endl;

	//4d) List all Sales for the year, specific client
	vector<Sale*> salesByClient = Sale::GetByClient(c->getID());
	cout << "Sales by this Client? " << salesByClient.size() << endl;

	for(int i = 0; i < salesByClient.size(); i++) {
		salesByClient.at(i)->Print();
	}

	//4e) Update specific Sale -- Double it
	s->setAmountSold(s->getAmountSold() * 2);
	Sale::Update(s);

	//4f) Save Sales File
	Sale::Save();

	cout << "Sales functionality over. Press any key to continue..." << endl;
	cin.get();
	return 0;
}