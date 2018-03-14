#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CakeType
{
public:
    size_t weight_;
    long long value_;

    CakeType(size_t weight = 0, long long value = 0) :
        weight_(weight),
        value_(value)
    {
    }
};

long long maxDuffelBagValue(const vector<CakeType>& cakes, size_t capacity) {
    vector<long long> maxValue(capacity + 1);
    
    for (size_t currentCapacity = 0; currentCapacity <= capacity; currentCapacity++) {
        long long maxValueCurrentCapacity = 0;
        
        for (auto cake : cakes) {
            if (cake.weight_ <= currentCapacity) {
                long long currentValue = cake.value_ + maxValue[currentCapacity - cake.weight_];
                maxValueCurrentCapacity = max(maxValueCurrentCapacity, currentValue);
            }
        }
        maxValue[currentCapacity] = maxValueCurrentCapacity;
    }
    
    return maxValue[capacity];
}

int main ()
{
    const vector<CakeType> cakeTypes {
        CakeType(7, 160),
        CakeType(3, 90),
        CakeType(2, 15)
    };
    
    size_t capacity = 20;
    
    cout << maxDuffelBagValue(cakeTypes, capacity) << endl;
    return 0;
}
