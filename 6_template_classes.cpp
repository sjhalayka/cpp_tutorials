#include <iostream>
#include <exception>
#include <vector>
using namespace std;


// We will use a template of type T in our class three_d_array
template<class T>
class three_d_array
{
protected:

	// These are member variables for the three_d_array class
	size_t width, height, length;
	vector<T> vec;

public:

	// These are member functions for the three_d_array class
	three_d_array(void)
	{
		width = height = length = 0;
	}

	three_d_array(size_t src_x, size_t src_y, size_t src_z)
	{
		set_size(src_x, src_y, src_z);
	}

	void set_size(size_t src_x, size_t src_y, size_t src_z)
	{
		width = src_x;
		height = src_y;
		length = src_z;

		vec.clear();
		vec.resize(width * height * length);
	}

	// Here we use abstraction and encapsulation 
	// (2 of the 4 pillars of object oriented programming)
	// to hide the details inside of the class 
	// As far as the user of the class knows, it all boils
	// down to using a triplet of indices, regardless of how
	// it's actually stored in the class
	void set_value(size_t src_x, size_t src_y, size_t src_z, T value)
	{
		if (src_x >= width || src_y >= height || src_z >= length)
			throw out_of_range("Out of bounds");

		// Convert 3D indices to 1D index
		const size_t index = src_z * width * height + src_y * width + src_x;

		vec[index] = value;
	}

	T get_value(size_t src_x, size_t src_y, size_t src_z)
	{
		if (src_x >= width || src_y >= height || src_z >= length)
			throw out_of_range("Out of bounds");

		// Convert 3D indices to 1D index
		const size_t index = src_z * width * height + src_y * width + src_x;

		return vec[index];
	}

	size_t get_width(void)
	{
		return width;
	}

	size_t get_height(void)
	{
		return height;
	}

	size_t get_length(void)
	{
		return length;
	}
};


class dougs_class
{
public:
	size_t a = 0, b = 0;
};


int main(void)
{
	three_d_array<float> t;
	t.set_size(2, 3, 4);

	for (size_t i = 0; i < t.get_width(); i++)
	{
		for (size_t j = 0; j < t.get_height(); j++)
		{
			for (size_t k = 0; k < t.get_length(); k++)
			{
				t.set_value(i, j, k, rand() / float(RAND_MAX));
				cout << t.get_value(i, j, k) << endl;
			}
		}
	}


	three_d_array<dougs_class> t2;
	t2.set_size(1, 3, 5);

	for (size_t i = 0; i < t2.get_width(); i++)
	{
		for (size_t j = 0; j < t2.get_height(); j++)
		{
			for (size_t k = 0; k < t2.get_length(); k++)
			{
				dougs_class d;
				d.a = i;
				d.b = j;

				t2.set_value(i, j, k, d);

				dougs_class d2;
				d2 = t2.get_value(i, j, k);
			}
		}
	}

	// Demonstrate the out of range by manually
	// checking for an exception
	try
	{
		t2.get_value(100, 100, 100);
	}
	catch (exception& e)
	{
		cout << "Caught exception -- " << e.what() << endl;
		return -1;
	}

	return 0;
}
