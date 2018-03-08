#include <iostream>
#include <vector>
using namespace std;

vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{
    try {
        if(intVector.size() < 2) {
            throw 2;
        }
    }
    catch (int e) {
        cout << "Vector size is less than " << e << endl;
        return vector<int>(0);
    }
    
    
    // make a vector of the products
    auto productVector = vector<int>(intVector.size());
    
    // first pass
    long int productBeforeIndex = 1;
    for (int i = 0; i < intVector.size(); i++) {
        productVector[i] = productBeforeIndex;
        productBeforeIndex *= intVector[i];
    }
    
    // second pass
    long int productAfterIndex = 1;
    for (int i = intVector.size() - 1; i >= 0; i--) {
        productVector[i] *= productAfterIndex;
        productAfterIndex *= intVector[i]; 
    }

    return productVector;
}

int main()
{
    const vector<int> intVector {0};
    auto result = getProductsOfAllIntsExceptAtIndex(intVector);
    for (auto out : result) {
        cout << out << " ";
    }
    cout << endl;

    return 0;
}
