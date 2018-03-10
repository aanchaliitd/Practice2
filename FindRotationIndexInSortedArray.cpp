#include <iostream>
#include <vector>
using namespace std;

int findIndexRotationPointBinary(const vector<string>& string_vector,
                                 int start_index, 
                                 int end_index)
{
    string start_str = string_vector[start_index];
    string end_str = string_vector[end_index];
    
    if (start_index == end_index - 1) {
        if (start_str.compare(end_str) > 0) {
            return end_index;
        }
        return 0;
    }
    
    int mid_index = (start_index + end_index) / 2;
    string mid_str = string_vector[mid_index];
    if (start_str.compare(mid_str) > 0) {
        return findIndexRotationPointBinary(string_vector, start_index, mid_index);
    }
    else {
        return findIndexRotationPointBinary(string_vector, mid_index, end_index);
    }
    return 0;
}                                 

int findIndexRotationPoint(const vector<string>& string_vector) {
    return findIndexRotationPointBinary(string_vector, 0, string_vector.size() - 1);
}




int main ()
{
    vector<string> input_vector = {"a", "b", "c", "d"};
    cout << findIndexRotationPoint(input_vector) << endl;
    return 0;
}
