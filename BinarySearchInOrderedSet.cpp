#include <iostream>
#include <vector>
using namespace std;

int FindPosRec(const vector<int>& vec, int num, int start, int end) {
    if (vec[start] == num) return start;
    if (vec[end] == num) return end;
    if (start >= end) return -1;
    
    int mid = (start + end) / 2;
    
    if (vec[mid] >= num) {
        return FindPosRec(vec, num, start, mid);
    }
    else {
        return FindPosRec(vec, num, mid + 1, end);
    }
}

int FindPos(const vector<int>& vec, int num) {
    return FindPosRec(vec, num, 0, vec.size() - 1);
}

int main ()
{
    vector<int> vec = {1, 2, 4, 5, 7, 9};
    cout << FindPos(vec, 6) << endl;
    return 0;
}
