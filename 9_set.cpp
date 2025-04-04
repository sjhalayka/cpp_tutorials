#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


class dougs_class
{
public:
    int x = 0, y = 0;

    // Overloaded less than operator
    //
    // This is required for using the class
    // in a std::set and for the sorting of 
    // a vector
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

    friend ostream& operator<<(ostream& os, const dougs_class& d);
};

ostream& operator<<(ostream& os, const dougs_class& d)
{
    os << d.x << " " << d.y;
    return os;
}



int main(void)
{
    vector<dougs_class> input_vec;

    // Three out of four are distinct
    dougs_class tempd;
    tempd.x = 1;
    tempd.y = 2;
    input_vec.push_back(tempd);

    tempd.x = 5;
    tempd.y = 6;
    input_vec.push_back(tempd);

    tempd.x = 3;
    tempd.y = 4;
    input_vec.push_back(tempd);

    tempd.x = 3;
    tempd.y = 4;
    input_vec.push_back(tempd);

    // Note that:
    // - The vector accepts duplicates
    // - The vector is not automatically sorted
    cout << "Vector has a size of " << input_vec.size() << endl;

    // Manually sort the vector
    sort(input_vec.begin(), input_vec.end());

    cout << "Elements are: " << endl;

    for (size_t i = 0; i < input_vec.size(); i++)
        cout << input_vec[i] << endl;

    cout << endl;


    // Three out of four are distinct
    set<dougs_class> input_set;
    tempd.x = 1;
    tempd.y = 2;
    input_set.insert(tempd);

    tempd.x = 5;
    tempd.y = 6;
    input_set.insert(tempd);

    tempd.x = 3;
    tempd.y = 4;
    input_set.insert(tempd);

    tempd.x = 3;
    tempd.y = 4;
    input_set.insert(tempd);

    // Note that:
    // - The set is duplicate-free
    // - The set is automatically sorted
    cout << "Set has a size of " << input_set.size() << endl;

    cout << "Elements are: " << endl;

    for (set<dougs_class>::const_iterator ci = input_set.begin(); ci != input_set.end(); ci++)
        cout << *ci << endl;

    cout << endl;

    return 0;
}
