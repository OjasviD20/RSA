/**
* @file         Assignment Task 2
* @Author       Ojasvi DSilva
* @date         November 13th, 2023
* @brief 		The program takes in positive integers a and b, then outs g,x and y
                such that gcd(a,b) = g = x*a + y*b
*/

#include <iostream> // Library for input and output
using namespace std;

// Function for extended Euclidean Algorithm .
// Takes in intgers a, b and outputs r, s and t for each loop. and returns g, x and y

long long gcdExt(long long a, long long b, long long* x, long long* y)
{
    //initialisation of vales of r',r,s',s,t',t
    long long r1 = a;
    long long r = b;
    long long s1 = 1;
    long long s = 0;
    long long t1 = 0;
    long long t = 1;
    // Printing initial r, s and t
    cout << "r = " << r << ", s = " << s << ", t = " << t << endl;

    while (r != 0)
    {

        long long q = r1 / r; // value of q = r'/r
        long long temp = r1; // temporary storing old r' value before changing
        r1 = r; // new r' = r
        r = temp - (q * r); // new r = r'-qr

        temp = s1;
        s1 = s;// new s' = s
        s = temp - (q * s); // new s = s'-qs

        temp = t1; // new t'=t
        t1 = t; // new t = t'-qt
        t = temp - (q * t);
        // Printing r, s and t for each loop
        cout << "r = " << r << ", s = " << s << ", t = " << t << endl;
    }
    // when r=0 then g = r', x= s', y = t'
    long long g = r1;
    *x = s1;
    *y = t1;
    return g;

}


int main()
{
    // Do while loop for user program as long as user keeps saying yes
    string Con; 
    
    do {

        //integers a and b to be take as input from user
        long long a, b;
        //integers g, x and y to be outputted
        long long g, x, y;

        //Requesting input
        cout << "Please Enter a:";
        cin >> a;
        cout << "Please Enter b:";
        cin >> b;

        // Calling GCD Function
        g = gcdExt(a, b, &x, &y);
        // outputting values
        cout << "\nThe Final values for g, x and y are: " << endl;
        cout << "\g = " << g << ", x = " << x << ", y = " << y << endl;
        cout << "Would you like to try again 'Y' or 'N' " << endl;
        cin >> Con;
    } while (Con == "Y" || Con == "y");


    return 0;
}