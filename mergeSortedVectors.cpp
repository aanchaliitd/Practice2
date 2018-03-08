nclude <iostream>
#include <vector>
using namespace std;

template <typename type>
vector<type> mergeVectors(const vector<type>& v1,
                          const vector<type>& v2)
{
    vector<type> mergedVector;
    
    int index1 = 0;
    int index2 = 0;
    
    while(index1 < v1.size() || index2 < v2.size()) {
        if (index1 < v1.size() && index2 < v2.size()) {
            if (v1[index1] < v2[index2]) {
                mergedVector.push_back(v1[index1++]);
            }
            else {
                mergedVector.push_back(v2[index2++]);
            }
        }
        else if (index1 < v1.size()) {
            mergedVector.push_back(v1[index1++]);
        }
        else {
            mergedVector.push_back(v2[index2++]);
        }
    }
    
    return mergedVector;
}

int main ()
{
    const vector<int> myVector{4, 5};
    const vector<int> alicesVector{1};
    
    vector<int> mergedVector = mergeVectors(myVector, alicesVector);

    cout << "[";
    for (size_t i = 0; i < mergedVector.size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << mergedVector[i];
    }
    cout << "]" << endl;
    return 0;
}
