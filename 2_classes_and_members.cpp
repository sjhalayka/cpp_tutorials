#include <iostream>
using std::cout;
using std::endl;

// Classes are like structs in C, except that there are member functions.
// One thing about classes is that they encapsulate their member variables,
// making them accessible only to the other members in the class by using
// getter and setter functions
class dougs_class
{
// Member variables that are *not* directly accessible from outside of the class
// I could have also used the protected keyword instead of the private keyword
private:

	int x = 0;
	float y = 0;

// Member functions that are directly accessible from anywhere
public:
	// Default constructor that is called whenever an instance of
	// dougs_class is created
	dougs_class(void)
	{
		cout << "Calling constructor" << endl;
		x = 123;
	}

	// Default destructor that is called whenever an instance of
	// dougs_class is destroyed
	~dougs_class(void)
	{
		// We don't really need to do anything here
		cout << "Calling destructor" << endl;
	}

	// Include a 'getter' member function 
	int get_x(void)
	{
		return x;
	}

	// Include a 'setter'
	void set_x(int src_x)
	{
		x = src_x;
	}
};

int main(void)
{
	dougs_class d;
	cout << d.get_x() << endl;

	d.set_x(1000);
	cout << d.get_x() << endl;

	return 0;
}