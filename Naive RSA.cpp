/**
* @file         Assignment Task 4
* @Author       Ojasvi DSilva
* @date         November 13, 2023
* @brief 		The program performs naive rsa
*/

#include <iostream> // for input and output
#include <cstdlib> // for generating random numbers
using namespace std;

// exponentiation to find boundaries for the integer size
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
	
	unsigned long long result = 1;

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
//Fermats Theorem to see if a number is prime
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
// Function to find two prime numbers by calling Fermats Theorem
unsigned long long findingPrime(unsigned long long n, unsigned long long k)
{

	// setting bit limit, prime number is between 2^n-1 <= p < 2^n
	unsigned long long x = smartExp(2, n - 1);
	unsigned long long y = smartExp(2, n);
	// checking for prime within range
	for (unsigned long long i = x; i < y; i++)
	{
		
		// Using fermats theorem to check if number is a prime with k - 100.
		if (isPrime(i, 100) == true && i != k)
		{
			return i;
		}

	}


}
// Extended Eucledian Theorem. Used to find e and d.
long long gcdExt(long long a, long long b, long long* x, long long* y)
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
	// when r=0 then g = r', x= s', y = t'
	long long g = r1;
	*x = s1;
	*y = t1;
	return g;

}

int main()
{
	// Requesting user input for Nu
	int nu;
	cout << "Please enter the security parameter `nu': ";
	cin >> nu;
	// Generating 2 Nu/2-bit primes p and q. then computing n = pq
	unsigned long long n, p, q;
	p = findingPrime(nu / 2, 3);
	q = findingPrime(nu / 2, p);
	n = p * q;
	//Printing intial set up values
	cout << "Setup: " << endl;
	cout << "The first prime generated by the Setup algorithm is p = " << p << endl;
	cout << "The second prime generated by the Setup algorithm is q = " << q << endl;
	cout << "The integer n = pq = " << n << endl;
	// Calculating M = Phi(n) =(p-1)(q-1)
	unsigned long long M, e = 1;
	M = (p - 1) * (q - 1);
	long long d = 1;
	long long y;
	long long z;
	// Finding an e such that gcd(e,M) = 1
	for (int i = 2; i <= M; i++)
	{
		unsigned long long x = rand() % (M - 1) + 1;

		if (gcdExt(x, M, &y, &z) == 1)
		{

			e = x;
			break;
		}
	}
	// Finding the modular inverse d. such that d*e = 1 mod M
	//
	d = (M + y) % M;
	cout << "The encryption exponent is e = " << e << endl;
	cout << "The decryption exponent is d = " << d << endl;
	// Checking if decryption or encryption
	int Check;

	do
	{
		unsigned long long message, cipher;

		cout << "Please enter an option: " << endl;
		cout << "1 to Encrypt " << endl;
		cout << "2 to Decrypt " << endl;
		cout << "Other number to quit" << endl;
		cout << "Your Option: ";
		cin >> Check;
		// Encryption c = m^e mod N
		if (Check == 1)
		{
			cout << "Encryption: " << endl;
			// Requesting message in set {Z/NZ}
			cout << "Your message space is the set{Z/NZ} = {0,1,..." << (n - 1) << "}" << endl;
			cout << "Please enter a number from this set: ";
			cin >> message;
			cipher = modExp(message, e, n);
			cout << "The ciphertext for your message " << message << " is " << cipher << endl;

		}
		// Deccryption m' = c^d mod N
		else if (Check == 2)
		{
			cout << "Decryption: " << endl;
			//Requesting cipher in set{Z/NZ}
			cout << "Your ciphertext space is the set{Z/NZ} = {0,1,..." << (n - 1) << "}" << endl;
			cout << "Please enter a number from this set: ";
			cin >> cipher;
			message = modExp(cipher, d, n);
			cout << "The plaintext for your ciphertext  " << cipher << " is " << message << endl;
		}
		else
			return 0;
	} while (Check == 1 || Check == 2);



	return 0;
}