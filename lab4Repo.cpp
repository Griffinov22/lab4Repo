// lab4Repo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


// Print out the menu of choices for the user to select from
void printMenu() {
	cout << "Please Select which operation to perform:" << endl;
	cout << "\t1. Factorial" << endl;
	cout << "\t2. Arithmetic Series" << endl;
	cout << "\t3. Geometric Series" << endl;
	cout << "\t4. Exit" << endl;
	cout << "Your Selection: ";
}
void factorial() {
	int factNum;
	int factSum;

	cout << "Enter number you would like to get the factorial of: ";
	cin >> factNum;

	//A factorial must be a positive integer
	while (factNum <= 0 && typeid(factNum).name() != "i") {
		cout << "\nYour input must be of type int and be a positive number.\n";
		cout << "Enter a POSITIVE number to find the factorial of: ";
		cin >> factNum;
	}

	factSum = factNum;
	for (int i = factNum - 1; i > 0; i--) {
		factSum *= i;
	}
	cout << "The factorial, " << factNum << "! = " << factSum << endl;
}
void arithmetic() {
	int difference;
	int startingNum;
	int numInSeries;
	int total;
	cout << "Arithmetic Series:\n";
	cout << "Enter the starting number: ";
	cin >> startingNum;
	total = startingNum;
	cout << "Enter a number to add each time: ";
	cin >> difference;
	cout << "Enter the number of elements in the series: ";
	cin >> numInSeries;
	
	//validation
	while (!(numInSeries > 0)) {
		cout << "The number of elemnts must be positive.\n";
		cout << "Enter the number of elements in the series: ";
		cin >> numInSeries;
	}

	cout << startingNum;
	for (int i=numInSeries-1; i > 0; i--) {
		cout << " + " << startingNum + difference;
		startingNum += difference;
		total += startingNum;
	}
	cout << " = " << total << endl;

}
void geometric() {
	int temp;
	int multNum;
	int numInSeries;
	int total;
	cout << "Geometric Series: \n";
	cout << "Enter a number to start at: ";
	cin >> temp;

	//initializing total to the first value
	total = temp;
	
	cout << "Enter a number to multiply by each time: ";
	cin >> multNum;
	cout << "Enter the number of elements in the series: ";
	cin >> numInSeries;
	
	//validation
	while (!(numInSeries > 0)) {
		cout << "\nPlease enter a positive number for the number of elements in the series.\n";
		cout << "Enter the number of elements in the series: ";
		cin >> numInSeries;
	}
	
	cout << temp;
	for (int i = numInSeries-1; i > 0; i--) {
		cout << " + " << temp * multNum;
		temp *= multNum;
		total += temp;
	}
	cout << " = " << total << endl;
}
int main() {
	int choice;
	char again;
	do {
		printMenu();
		cin >> choice;
		// Quit if user chooses to exit (or any invalid choice)
		if (choice > 3 || choice < 1) {
			return 0;
		}
		else if (choice == 1) {
			factorial();
		}
		else if (choice == 2) {
			arithmetic();
		}
		else if (choice == 3) {
			geometric();
		}
		cout << "Go Again? [Y/N] ";
		cin >> again;
	} while (again == 'y' || again == 'Y');
}