// makeChange.cpp
// Assist cashiers in giving the correct amount of change,
// online store retailer for customers.
// Jack Margeson

// cout << "\033[2J\033[1;1H";

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// declarations
	char ans; // used for program loop
	char sshopping; // used for "still shopping" loop
	char name[20]; // used to store name
	int choice; // used for store item choice
	int numchoice; // used for quant. of choice.
	float total; // used to keep total owed.
	float nprice; // used to store new price 
	float rpayment; // recieved payment
	float change; // change owed

	// makechange declarations
	const float hundred = 100.00;
	const float fifty = 50.00;
	const float twenty = 20.00;
	const float dollar = 1.00;
	const float quarter = 0.25;
	const float dime = 0.10;
	const float nickel = 0.05;
	const float penny = 0.01;
	// more makechange declarations, count of currency
	int chundred;
	int cfifty;
	int ctwenty;
	int cdollar;
	int cquarter;
	int cdime;
	int cnickel;
	int cpenny;
	// makechange declarations pt. 3, subtraction amounts
	float vhundred;
	float vfifty;
	float vtwenty;
	float vdollar;
	float vquarter;
	float vdime;
	float vnickel;
	float vpenny;

	// main code in do loop
	do {
		cout << "\033[2J\033[1;1H";
		// reset total
		float total = 0;
		// ascii art of chicken
		cout << "             XX\n"
			"            / .|_\n"
			"           /(_)_<\n"
			"          /  (\n"
			" ((____.-'    )\n"
			"  \\\\         /\n"
			"   \\'-.-.-'`/\n"
			" _  \\______/\n"
			"(_)   _|_\\_\n"
			"''''''''''''''''\n";
		cout << "Welcome to Jack's Chicken Shack!\n" << "What is your name for pick-up?: "; // asks users name
		cin.getline(name, 20); // grabs user's name
		do {
			cout << "\033[2J\033[1;1H"; // clear
			cout << "What would you like?\n" << "1) $6.98 - The Box Combo\n" << "2) $9.98 - The Jackiac Combo\n" << "3) $6.38 - The Three Finger Combo\n" << "4) $5.98 - The Sandwich Combo\n" << "5) $4.58 - The Kids Combo\n" << "(1-5): "; // outputs menu options
			cin >> choice; // grabs menu option chosen by user
			cin.ignore();
			cout << "And how many would you like?: "; // asks quantity 
			cin >> numchoice; // grabs quantity from user
			cin.ignore();
			if (choice == 1) { // The Box Combo
				nprice = numchoice * 6.98;
				cout << "\n" << numchoice << " Box Combo(s) have been added to your order. (" << fixed << setprecision(2) << nprice << ").\n";
				total = total + nprice;
			}
			else if (choice == 2) { // The Jackiac Combo
				nprice = numchoice * 9.98;
				cout << "\n" << numchoice << " Jackiac Combo(s) have been added to your order. (" << fixed << setprecision(2) << nprice << ").\n";
				total = total + nprice;
			}
			else if (choice == 3) { // The Three Finger Combo
				nprice = numchoice * 6.38;
				cout << "\n" << numchoice << " Three Finger Combo(s) have been added to your order. (" << fixed << setprecision(2) << nprice << ").\n";
				total = total + nprice;
			}
			else if (choice == 4) { // The Sandwich Combo
				nprice = numchoice * 5.98;
				cout << "\n" << numchoice << " Sandwich Combo(s) have been added to your order. (" << fixed << setprecision(2) << nprice << ").\n";
				total = total + nprice;
			}
			else if (choice == 5) { // The Kids Combo
				nprice = numchoice * 4.58;
				cout << "\n" << numchoice << " Kids Combo(s) have been added to your order. ($" << fixed << setprecision(2) << nprice << ").\n";
				total = total + nprice;
			}
			else { // error handling - outputs invalid menu option if not 5 < int < 1
				cout << "Invalid menu choice. Please try again.\n";
			}
			cout << "Your current total is $" << total << ". "; // outputs total
			cout << "Will that be all for today? (y/n): "; // asks the user if they want to continue shopping, handler for loop
			cin >> sshopping;
			cin.ignore();
		} while (sshopping == 'n' or sshopping == 'n'); // loop conditions
		cout << "\033[2J\033[1;1H";
		cout << "Thank you, " << name << "!\n" << "Your final total is $" << total << ".\n"; // outputs name and final total 
		cout << "Enter total cash recieved: $";
		cin >> rpayment;
		// calculations for change 
		change = rpayment - total;
		//hundred
		chundred = change / hundred;
		vhundred = hundred * chundred;
		change = change - vhundred;
		// fifty
		cfifty = change / fifty;
		vfifty = fifty * cfifty;
		change = change - vfifty;
		// twenty 
		ctwenty = change / twenty;
		vtwenty = twenty * ctwenty;
		change = change - vtwenty;
		// dollar
		cdollar = change / dollar;
		vdollar = dollar * cdollar;
		change = change - vdollar;
		// quarter
		cquarter = change / quarter;
		vquarter = quarter * cquarter;
		change = change - vquarter;
		// dime
		cdime = change / dime;
		vdime = dime * cdime;
		change = change - vdime;
		// nickel
		cnickel = change / nickel;
		vnickel = nickel * cnickel;
		change = change - vnickel;
		// penny 
		cpenny = change / penny;
		vpenny = penny * cpenny;
		change = change - vpenny;
		// total change 
		change = vhundred + vfifty + vtwenty + vdollar + vquarter + vdime + vnickel + vpenny;
		// ascii art of chicken
		cout << "             XX\n"
			"            / .|_\n"
			"           /(_)_<\n"
			"          /  (\n"
			" ((____.-'    )\n"
			"  \\\\         /\n"
			"   \\'-.-.-'`/\n"
			" _  \\______/\n"
			"(_)   _|_\\_\n"
			"''''''''''''''''\n";
		// outputs receipt table for user 
		cout << "\nTotal Owed:" << fixed << setfill(' ') << setw(10) << "$" << right << setfill('.') << setw(7) << setprecision(2) << total;
		cout << "\nPayment Recived:" << fixed << setfill(' ') << setw(5) << "$" << right << setfill('.') << setw(7) << setprecision(2) << rpayment;
		cout << "\nChange Due:" << fixed << setfill(' ') << setw(10) << "$" << right << setfill('.') << setw(7) << setprecision(2) << change;
		cout << "\n" << fixed << setfill('-') << setw(28) << "";
		cout << "\nHundreds:" << fixed << setfill(' ') << setw(9) << chundred << fixed << setfill(' ') << setw(3) << "$" << right << setfill('.') << setw(7) << setprecision(2) << vhundred;
		cout << "\nFifties:" << fixed << setfill(' ') << setw(10) << cfifty << fixed << setfill(' ') << setw(3) << "$" << right << setfill('.') << setw(7) << setprecision(2) << vfifty;
		cout << "\nTwenties:" << fixed << setfill(' ') << setw(9) << ctwenty << fixed << setfill(' ') << setw(3) << "$" << right << setfill('.') << setw(7) << setprecision(2) << vtwenty;
		cout << "\nDollars:" << fixed << setfill(' ') << setw(10) << cdollar << fixed << setfill(' ') << setw(3) << "$" << right << setfill('.') << setw(7) << setprecision(2) << vdollar;
		cout << "\nQuarters:" << fixed << setfill(' ') << setw(9) << cquarter << fixed << setfill(' ') << setw(3) << "$" << right << setfill('.') << setw(7) << setprecision(2) << vquarter;
		cout << "\nDimes:" << fixed << setfill(' ') << setw(12) << cdime << fixed << setfill(' ') << setw(3) << "$" << right << setfill('.') << setw(7) << setprecision(2) << vdime;
		cout << "\nNickels:" << fixed << setfill(' ') << setw(10) << cnickel << fixed << setfill(' ') << setw(3) << "$" << right << setfill('.') << setw(7) << setprecision(2) << vnickel;
		cout << "\nPennies:" << fixed << setfill(' ') << setw(10) << cpenny << fixed << setfill(' ') << setw(3) << "$" << right << setfill('.') << setw(7) << setprecision(2) << vpenny;
		cout << "\n" << fixed << setfill('-') << setw(28) << "";
		cout << "\nChange Total:" << fixed << setfill(' ') << setw(8) << "$" << right << setfill('.') << setw(7) << setprecision(2) << change;
		// asks user if they want to run entire program again, handler for loop
		cout << "\nDo you want to run again? (y/n): ";
		cin >> ans;
		cin.ignore();
	} while (ans == 'y' or ans == 'Y'); // loop conditions
	// system("Pause");
	return 0; // end program
}