#include "Client.h"
#include "SalesRep.h"
#include "Product.h"
#include "Sale.h"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip> // Learned from ZyBooks!
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
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
	cout << "----- Client Functions -----" << endl;
	cout << endl;

	//Print out Client Information
	cout << "----- Listing out current clients..." << endl;
	//1b) List all current clients - name, short address, sales to date
	for(int i = 0; i < Client::Get().size(); i++) {
		Client::Get().at(i)->PrintShort();
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
	c->setFirstName(c->getFirstName() + " #" + to_string(Client::Get().size()));
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
		SalesRep::Get().at(i)->PrintShort();
	}

	//2d) Add a new salesRep
	SalesRep* r = SalesRep::AddNew("Sales", "Dude", "456 Not My Ave.", "Ste.1", "Houston", "TX", "11234");
	
	//2c) List all information for specific sales rep
	r->PrintDetails();

	//2e) Update Sales Rep Information
	r->setFirstName("Super");
	r->setLastName("Man #" + to_string(SalesRep::Get().size()));
	SalesRep::Update(r);
	//Print to Confirm
	r->PrintDetails();

	//2g) Save updated salesRep information to file
	SalesRep::Save();

	cout << "Sales Rep functions over. Press any key to continue..." << endl;
	cin.get();
	cout << endl;

	// ----- Product Section -----
	cout << "----- Product Functions -----" << endl;
	cout << endl;

	//3b) List current Products
	cout << "----- Listing out current products..." << endl;
	//Including current sales
	for(int i = 0; i < Product::Get().size(); i++) {
		Product::Get().at(i)->PrintShort();
	}
	cout << endl;

	//3d) Add a new Product
	Product* p = Product::AddNew("A Cookie", "Some kind of yummy pastry maybe", 1.50);

	//3c) List all information for a specific Product
	p->PrintDetails();
	cout << endl;

	//3e) Update a Product
	p->setName("Cookie #" + to_string(Product::Get().size()));
	Product::Update(p);
	//Print to Test
	p->PrintDetails();

	//3g) Save to a file
	Product::Save();
	cout << "Product functionality over. Press any key to continue..." << endl;
	cin.get();
	cout << endl;

	// ----- Sales Functions -----

	//4c) List all Sales for the year
	cout << "How many Sales? -- " << Sale::Get().size() << endl;
	for(int i = 0; i < Sale::Get().size(); i++) {
		Sale::Get().at(i)->Print();
	}
	cout << endl;

	//4b) Purchase a Product, Make a Sale
	cout << "Trying to make 3 purchases..." << endl;
	// Sale* s;

	for(int i = 0; i < 3; i++) {
		int amountSold = (rand() % 20) + 1;
		int monthSold = (rand() % 12) + 1;
		Sale::Purchase(c->getID(), r->getID(), p->getID(), amountSold, monthSold);
		cout << "Sale successful!" << endl;
		cout << endl;
	}

	//4d) List all Sales for the year, specific client
	vector<Sale*> salesByClient = Sale::GetByClient(c->getID());
	cout << "Sales by this Client? " << salesByClient.size() << endl;

	for(int i = 0; i < salesByClient.size(); i++) {
		salesByClient.at(i)->Print();
	}

	//4e) Update random Sale -- Double it
	Sale* s = Sale::Get().at((rand() % Sale::Get().size()));
	s->setAmountSold(s->getAmountSold() * 2);
	Sale::Update(s);
	cout << endl;

	//Monthly Sales Report
	vector<float> monthlySalesNumbers;
	for(int i = 1; i <= 12; i++) {
		vector<Sale*> monthlySales = Sale::GetByMonth(i);
		float totalMonthlySales = 0.0;

		for(auto it = monthlySales.begin(); it != monthlySales.end(); ++it)
			totalMonthlySales += (*it)->getSaleTotal();

		monthlySalesNumbers.push_back(totalMonthlySales);
	}

	cout << "---------- Monthly Sales Report ----------" << endl;
	cout.precision(2);
	cout << right << setw(20) << setfill(' ') << "January" << " | $" << left << fixed << monthlySalesNumbers.at(0) << endl;
	cout << right << setw(20) << setfill(' ') << "Februrary" << " | $" << left << fixed << monthlySalesNumbers.at(1) << endl;
	cout << right << setw(20) << setfill(' ') << "March" << " | $" << left << fixed << monthlySalesNumbers.at(2) << endl;
	cout << right << setw(20) << setfill(' ') << "April" << " | $" << left << fixed << monthlySalesNumbers.at(3) << endl;
	cout << right << setw(20) << setfill(' ') << "May" << " | $" << left << fixed << monthlySalesNumbers.at(4) << endl;
	cout << right << setw(20) << setfill(' ') << "June" << " | $" << left << fixed << monthlySalesNumbers.at(5) << endl;
	cout << right << setw(20) << setfill(' ') << "July" << " | $" << left << fixed << monthlySalesNumbers.at(6) << endl;
	cout << right << setw(20) << setfill(' ') << "August" << " | $" << left << fixed << monthlySalesNumbers.at(7) << endl;
	cout << right << setw(20) << setfill(' ') << "September" << " | $" << left << fixed << monthlySalesNumbers.at(8) << endl;
	cout << right << setw(20) << setfill(' ') << "October" << " | $" << left << fixed << monthlySalesNumbers.at(9) << endl;
	cout << right << setw(20) << setfill(' ') << "November" << " | $" << left << fixed << monthlySalesNumbers.at(10) << endl;
	cout << right << setw(20) << setfill(' ') << "December" << " | $" << left << fixed << monthlySalesNumbers.at(11) << endl;

	//4f) Save Sales File
	Sale::Save();

	cout << "Sales functionality over. Press any key to continue..." << endl;
	cin.get();
	return 0;
}