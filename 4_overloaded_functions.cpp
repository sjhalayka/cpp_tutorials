#include <iostream>
using namespace std;


// Overloaded functions let you re-use a function name, as long as the
// parameter types are different. For instance:
void func(float x)
{
	cout << "float: " << x << endl;
}

void func(int x)
{
	cout << "int: " << x << endl;
}

int main(void)
{
	func(123.456f);
	func(10);

	return 0;
}