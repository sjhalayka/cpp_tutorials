#include <iostream>
#include <vector>
#include <string>
using namespace std;

class dougs_class
{
private:
	string z = "";

public:
	dougs_class(void)
	{
		cout << "Calling constructor" << endl;
	}

	~dougs_class(void)
	{
		cout << "Calling destructor" << endl;
	}

	string get_string(void)
	{
		return z;
	}

	void set_string(const string &src_z)
	{
		z = src_z;
	}
};

// C-style function
// Yws! you can use the new C++ vector class with
// legacy C code
// Note: size_t is generally a 64-bit integer
void dougs_class_func(dougs_class* d, size_t count)
{
	// Use -> to dereference the pointer
	cout << d->get_string() << endl;
}

// C-style function
// Yws! you can use the new C++ string class with
// legacy C code
void dougs_c_string_func(const char *d)
{
	size_t index = 0;

	while (d[index] != '\0')
	{
		cout << d[index];
		index++;
	}

	cout << endl;
}

int main(void)
{
	// A vector is effectively an array that
	// automatically cleans up after itself
	// upon destruction
	vector<dougs_class> d_vec(10);
	dougs_class_func(d_vec.data(), d_vec.size());

	// A string is effectively an array that
	// automatically cleans up after itself
	// upon destruction
	string s = "Test";

	// .c_str() returns a C-style string (terminated with a '\0')
	dougs_c_string_func(s.c_str());

	return 0;
}