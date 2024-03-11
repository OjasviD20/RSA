/**
* @file         Assignment Task3
* @Author       Ojasvi DSilva
* @date         November 13, 2023
* @brief 		The program takes integer N and outputs an N-bit prime number
*/

#include <iostream> // for input and output
#include <cstdlib> // for generating random numbers
using namespace std;

// Binary Exponentiation to find boundaries for the integer size
unsigned long long smartExp(unsigned long long n, unsigned long long e)
{
	unsigned long long result = 1;
	while (e > 0) {
		if (e % 2 == 1) // if y is odd
		{
			result *= n;
		}
		e = e / 2;
		n = n * n;

	}
	return result;
}

// Modular exponentiation for Fermats Theorem
unsigned long long modExp(unsigned long long m, unsigned long long e, unsigned long long N)
{
	//
	unsigned long long result = 1;
	// While loop while e is larger than 0. 
	while (e > 0) {
		if (e % 2 == 1) // Checking if number is odd
		{
			result = (result * m) % N;// multiplication mod N

		}
		e = e / 2;// Moving to next bit by dividing by 2
		m = (m * m) % N;// multiplication mod N


	}
	// returning final result.
	return (result % N);
}
//Fermats Theorem to find prime.
bool isPrime(unsigned long long n, unsigned long long k)
{

	for (unsigned long long i = 0; i < k; i++) // running test for k iterations
	{
		unsigned long long x = rand() % (n - 1) + 1; // checking random numbers in range between 1 to n-1
		if (modExp(x, n - 1, n) != 1) // if x^n-1 mod != 1 then it is not prime. Otherwise number is prime.
		{
			return false;
		}
	}
	return true;
}
// Function that will find n-bit prim
unsigned long long findingPrime(unsigned long long n)
{

	// setting bit limit, prime number is between 2^n-1 <= p < 2^n
	unsigned long long x = smartExp(2, n - 1);
	unsigned long long y = smartExp(2, n);
	// checking for prime within range
	for (unsigned long long i = x; i < y; i++)
	{
		// Using fermats theorem to check if number is a prime with k = 100.
		if (isPrime(i, 100) == true)
		{
			// returning which ever number is found as prime.
			return i;
		}

	}


}


int main()
{
	// Do while loop for user program as long as user keeps saying yes
	string Con; 
	do {
		// User input for n
		unsigned long long n;
		cout << "Enter an integer n to find an n bit prime: ";
		cin >> n;
		// calling function to find n-bit prime.
		unsigned long long i = findingPrime(n);
		cout << "The n-bit prime is: " << i << endl;

		cout << "Would you like to continue 'Y' or 'N' " << endl;
		cin >> Con;
	} while (Con == "Y" || Con == "y");
	return 0;
}