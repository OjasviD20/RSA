/**
* @file         Assignment Task 1
* @Author       Ojasvi DSilva
* @date         November 13th, 2023
* @brief 		The program takes in positive integers m, e and N. And provide output m^e mod N.
*/

#include <iostream>// Library for input and output
using namespace std;

//Function to calculate the exponentiation m^e mod N.  
unsigned long long smartExp(unsigned long long m, unsigned long long e, unsigned long long N)
{
	//Takes in 3 integers m, e, N, initializes int result
	unsigned long long result = 1;
	// While loop while e is larger than 0. Performing binary exponentiation.
	while (e > 0) {
		if (e % 2 == 1) // Checking if number is odd
		{
			result = (result * m) % N;// Multiplication mod n for each loop

		}
		e = e / 2;// Moving to next bit by dividing by 2
		m = (m * m) % N;// Multiplication  mod n for each loop


	}
	// returning final result.
	return (result % N);
}


int main()
{
	// Do while loop for user program as long as user keeps inputting y
	string Con; 
	do {

		// integers for user to input
		unsigned long long m;
		unsigned long long e;
		unsigned long long N;


		// requesting user input.

		cout << "Please Enter m: ";
		cin >> m;
		cout << "Please Enter e: ";
		cin >> e;
		cout << "Please Enter N: ";
		cin >> N;

		// Calling Exponentiation function to calculate m^e % N
		unsigned long long i = smartExp(m, e, N);
		cout << "The value of m ^ e mod n is: " << i << endl;
		cout << "Would you like to try again 'Y' or 'N' " << endl;
		cin >> Con;
	} while (Con == "Y" || Con == "y");


	return 0;
}