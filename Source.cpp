//Samuel Blair
#include<iostream>

using std::cout;
using std::endl;

int moveOP(int &a, int b);
int copyOP(int a, int b);

int main()
{
	int a(5), b(0), c(4), d(0);
	cout << "The numbers in a, b, c, d are " << a << ", " << b << ", " << c << ", " << d << " (respectivly) " << endl;
	cout << "Using the move operator b is now " << moveOP(b, a) << endl;
	cout << "Using the copy operator d is now " << moveOP(d, c) << endl;
}

int moveOP(int &a, int b)
{
	a = b;
	return a;
}
int copyOP(int a, int b)
{
	int c = b;
	a = c;
	return a;
}