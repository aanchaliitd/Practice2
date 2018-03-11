#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class TempTracker {
public:
    TempTracker() : _sum(0), _count(0), _min(INT_MAX), _max(INT_MIN), _modeTemp(-1), _tempCount(111) {}

    void insert(int temp) {
        _tempCount[temp]++;
        _sum += temp;
        _count++;
        _min = min(_min, temp);
        _max = max(_max, temp);
        
        if (_tempCount[_modeTemp] < _tempCount[temp]) {
            _modeTemp = temp;
        }
    }
    
    int getMax() {
        return _max;
    }
    
    int getMin() {
        return _min;
    }
    
    double getMean() {
        return (_sum / _count);
    }
    
    int getMode() {
        return _modeTemp;
    }
    
private:
    double _sum;
    int _count;
    int _min;
    int _max;
    int _modeTemp;
    vector<int> _tempCount;
};

int main ()
{
    TempTracker t;
    t.insert(4);
    t.insert(7);
    t.insert(7);
    t.insert(10);
    cout << "Get max temp : " << t.getMax() 
         << " Get min temp : " << t.getMin()
         << " Get mean temp : " << t.getMean()
         << " Get mode temp : " << t.getMode() << endl;
    return 0;
}
