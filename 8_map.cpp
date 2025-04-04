#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


class dougs_class
{
public:
    int x = 0, y = 0;

    // Overloaded less than operator
    // This is required for using the class
    // in a std::map
    inline bool operator<(const dougs_class& right) const
    {
        if (right.x > x)
            return true;
        else if (right.x < x)
            return false;

        if (right.y > y)
            return true;
        else if (right.y < y)
            return false;

        return false;
    }

    // We must use a friend of the class to overload the << (stream) operator
    // This is needed to print the class contents to the console
    friend ostream& operator<<(ostream& os, const dougs_class& d);
};

// Here we define said friend function
ostream& operator<<(ostream& os, const dougs_class& d)
{
    os << d.x << " " << d.y;
    return os;
}


template<class T>
double calc_entropy(const vector<T>&input)
{
    double entropy = 0.0;

    if (input.size() > 0)
    {
        // Make a dictionary
        map<T, size_t> input_map;

        // For each element in the input, 
        // automatically add to the dictionary if not already added in,
        // and then increment by 1
        for (size_t i = 0; i < input.size(); i++)
            input_map[input[i]]++;

        // For each element in the dictionary
        for (typename map<T, size_t>::const_iterator ci = input_map.begin(); ci != input_map.end(); ci++)
        {
            // Calculate this element's contribution to the entropy
            double probability = ci->second / static_cast<double>(input.size());
            entropy += probability * log(probability);

            cout << "Element: \'" << ci->first << "\', Count: " << ci->second << ", Probability: " << probability << endl;
        }

        entropy = -entropy;
    }

    return entropy;
}


int main(void)
{
    // Get entropy of 8 distinct variables
    // The binary entropy should be 3.0
    const string input_string = "abcdefgh";
    const vector<char> input_vec(input_string.begin(), input_string.end());
    double entropy = calc_entropy<char>(input_vec);

    // Convert to binary entropy and output to console
    cout << entropy / log(2.0) << endl << endl;


    // Get entropy of 4 distinct variables
    // The binary entropy should be 2.0
    vector<dougs_class> input_vec2;

    dougs_class tempd;
    tempd.x = rand();
    tempd.y = rand();
    input_vec2.push_back(tempd);

    tempd.x = rand();
    tempd.y = rand();
    input_vec2.push_back(tempd);

    tempd.x = rand();
    tempd.y = rand();
    input_vec2.push_back(tempd);

    tempd.x = rand();
    tempd.y = rand();
    input_vec2.push_back(tempd);

    entropy = calc_entropy<dougs_class>(input_vec2);

    cout << entropy / log(2.0) << endl << endl;

    return 0;
}
