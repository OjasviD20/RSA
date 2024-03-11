/**
* @file         Assignment Task 6
* @Author       Ojasvi DSilva
* @date         November 13, 2023
* @brief 		The program demonstrates Naive RSA is insecure with respet to an IND-CCA adversary
*/

#include <iostream> // for input and output
#include <cstdlib> // for generating random numbers
using namespace std;

// Modular exponentiation for Fermats Theorem
long long modExp(unsigned long long m, long long e, long long N)
{
	
	long long result = 1;
	while (e > 0) {
		if (e % 2 == 1) 
		{
			result = (result * m) % N;

		}
		e = e / 2;
		m = (m * m) % N;


	}
	// returning final result.
	return (result % N);
}
// modified Extended Eculedean algorithm to find return s' instead of r'
long long gcdExt(long long a, long long b)
{
	//initialisation of vales of r',r,s',s,t',t
	long long r1 = a;
	long long r = b;
	long long s1 = 1;
	long long s = 0;
	long long t1 = 0;
	long long t = 1;
	while (r != 0)
	{

		long long q = r1 / r; // value of q
		long long temp = r1; // temporary storing old r' value before changing
		r1 = r; // new r'
		r = temp - (q * r); // new r

		temp = s1;
		s1 = s;// new s'
		s = temp - (q * s); // new s

		temp = t1;
		t1 = t;
		t = temp - (q * t);
	}
	// Returning g = s' instead for r' so we can calculate the inverse.
	long long g = s1;
	return g;

}
int main()
{
	string Con;
	do {
		unsigned long long m1, invA, mb, N, e, c;
		// User input for N, e and C taken from task 4
		cout << "Please enter the public parameter N:";
		cin >> N;
		cout << "Please enter the encryption exponent e:";
		cin >> e;
		cout << "Please enter the ciphertext c:";
		cin >> c;

		unsigned long long c1;
		//c' - 2^e * c mod N = ((2^e modN)*(c mod N)) mod N
		c1 = (modExp(2, e, N) * (c % N)) % N;
		cout << "The modified ciphertext c' is = " << c1 << endl;
		//Find inverse of 2 mod N using EEA.
		invA = (N + gcdExt(2, N)) % N;
		cout << "The inverse of 2 mod " << N << " is: " << invA << endl;
		// Using Task 4 to decrypt C' to get m'
		cout << "Please decrypt the modified ciphertext c' using your program from Task 4." << endl;
		cout << "Please input the plaintext m' decrypted from c': ";
		cin >> m1;
		// m' = (2*mb)modN. mb = (2^-1 * m') mod N
		mb = (m1 * invA) % N;
		cout << "The original plaintext message m computed from m' is: " << mb;
		return 0;
	} while (Con == "Y" || Con == "y");

}