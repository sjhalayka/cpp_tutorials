#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;


class dougs_class
{
public:
    int x = 0, y = 0;

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
    std::chrono::high_resolution_clock::time_point start_time, end_time;
    std::chrono::duration<float, std::milli> elapsed;

    // Set the input to pseudorandom values
    const size_t num_elements = 100000;

    vector<dougs_class> input_vec;
    vector<dougs_class> input_vec2;
    list<dougs_class> input_list;
    deque<dougs_class> input_double_ended_queue;

    for (size_t i = 0; i < num_elements; i++)
    {
        dougs_class tempd;
        tempd.x = rand();
        tempd.y = rand();

        input_vec.push_back(tempd);
        input_vec2.push_back(tempd);
        input_list.push_back(tempd);
        input_double_ended_queue.push_back(tempd);
    }


    // Test vector iterator performance
    start_time = std::chrono::high_resolution_clock::now();

    // Clear the entire vector by erasing the first element
    // until there are no more elements
	vector<dougs_class>::iterator vi = input_vec.begin();
	while (vi != input_vec.end())
		vi = input_vec.erase(vi);

    end_time = std::chrono::high_resolution_clock::now();
    elapsed = end_time - start_time;
    cout << "Elapsed time: " << elapsed.count() / 1000.0f << " seconds" << endl;


    // Test vector performance using 'swap and pop' method
    start_time = std::chrono::high_resolution_clock::now();

    // If the order does not matter, then use what's called 'swap and pop'
    // where the first and last elements are swapped before the
    // last element is discarded via pop_back
    while (input_vec2.size() > 0)
    {
        swap(input_vec2[0], input_vec2[input_vec2.size() - 1]);
        input_vec2.pop_back();
    }

    end_time = std::chrono::high_resolution_clock::now();
    elapsed = end_time - start_time;
    cout << "Elapsed time: " << elapsed.count() / 1000.0f << " seconds" << endl;


    // Test list performance
    start_time = std::chrono::high_resolution_clock::now();

    list<dougs_class>::iterator li = input_list.begin();
    while (li != input_list.end())
        li = input_list.erase(li);

    end_time = std::chrono::high_resolution_clock::now();
    elapsed = end_time - start_time;
    cout << "Elapsed time: " << elapsed.count() / 1000.0f << " seconds" << endl;


    // Test deque performance
    start_time = std::chrono::high_resolution_clock::now();

    deque<dougs_class>::iterator di = input_double_ended_queue.begin();
    while (di != input_double_ended_queue.end())
        di = input_double_ended_queue.erase(di);

    end_time = std::chrono::high_resolution_clock::now();
    elapsed = end_time - start_time;
    cout << "Elapsed time: " << elapsed.count() / 1000.0f << " seconds" << endl;


    // The clear winner in terms of speed is the 'swap and pop' method

    return 0;
}
