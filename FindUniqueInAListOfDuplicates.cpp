#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findUnique(const vector<int>& listOfIDs) {
    int unique = 0;
    for (int i = 0; i < listOfIDs.size(); i++) {
        unique ^= listOfIDs[i];
    }
    return unique;
}

int main ()
{
    vector<int> ids = {1, 2, 3, 4, 3, 2, 1};
    cout << findUnique(ids) << endl;
    return 0;
}
