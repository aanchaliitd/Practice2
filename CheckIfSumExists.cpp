#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool PairExists(const vector<int>& movieLengths, int flightLength) {
    unordered_set<int> movieLengthSet;
    for (int i = 0; i < movieLengths.size(); i++) {
        int currentMovieLength = movieLengths[i];
        movieLengthSet.emplace(currentMovieLength);
        int diff = flightLength - currentMovieLength;
        if (!(movieLengthSet.find(diff) == movieLengthSet.end())) return true;
    }
    return false;
}

int main ()
{
    // run your function through some test cases here
    // remember: debugging is half the battle!
    vector<int> movieLengths = {1, 3, 5};
    cout << PairExists(movieLengths, 8) << endl;
    return 0;
}
