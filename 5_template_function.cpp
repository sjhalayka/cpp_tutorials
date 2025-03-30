#include <iostream>
using namespace std;

// Template functions let you re-use a function name, as long as the
// parameter types are different. We do this instead of creating a
// function for every possible type

// Here we can use any class (or plain-old data type) as the template parameter
template<class T>
void func(T x)
{
	cout << typeid(T).name() << ": " << x << endl;
}

int main(void)
{
	// Implicit type specification
	func(123.456f);
	func(10);

	// Explicit type specification
	func<float>(123.456f);
	func<double>(10); // force conversion from int to double

	return 0;
}