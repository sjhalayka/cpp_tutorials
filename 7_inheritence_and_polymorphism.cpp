#include <iostream>
#include <string>
using namespace std;


class animal
{
public:
	animal(void)
	{
		spoken_word = "";
		type = "";
	}

	// Virtual functions are generally meant to be 
	// overriden by inheriting classes
	virtual void speak(void)
	{
		// Base animal makes no sound
	}

protected:
	string type;
	string spoken_word;
};


// Here we inherit all of the protected and public member
// variables and functions from the animal class.
// Inheritence is the 3rd pillar of the 4 pillars of
// object-oriented programming (OOP)
class cat : public animal
{
public:
	cat(void)
	{
		spoken_word = "Meow";
		type = "Feline";
	}

	void speak(void)
	{
		cout << "Cats go " << spoken_word << endl;
	}
};


// Here we again inherit all of the protected and public member
// variables and functions from the animal class.
// Inheritence is the 3rd pillar of the 4 pillars of
// object-oriented programming
class dog : public animal
{
public:
	dog(void)
	{
		spoken_word = "Woof";
		type = "Canine";
	}

	void speak(void)
	{
		cout << "Dogs go " << spoken_word << endl;
	}
};


int main(void)
{
	// Here we use polymorphism, the 4th pillar of the 
	// 4 pillars of object-oriented programing (OOP)
	animal *animal_ptr = nullptr;
	cat c;
	dog d;

	// The animal pointer behaves as a cat
	// & is the address-of operator
	// -> is the pointer dereference operator
	animal_ptr = &c;
	animal_ptr->speak();

	// The animal pointer behaves as a dog
	animal_ptr = &d;
	animal_ptr->speak();

	// As you can see, pointers can be very useful, 
	// adapting to the type being pointed to

	return 0;
}
