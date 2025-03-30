// Include standard headers for printing to the console
#include <iostream>
using std::cout;
using std::endl;

// Note: global variable declarations can clash when multiple source codes are
// combined into one projecct. So, we wrap our global variables in a namespace,
// and then explictly declare which namespace we're talking about
namespace dougs_global_variables
{
	int x = 123;
	float y = 456.789f;
}

int main(void)
{
	// Use our namespaces from above
	cout << dougs_global_variables::x << endl;
	return 0;
}