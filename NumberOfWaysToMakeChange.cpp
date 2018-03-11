#include <iostream>
#include <vector>
using namespace std;

size_t numberOfWaysToMakeChange(int amount,
                                const vector<int>& denominations)
{
    vector<size_t> waysOfDoingN(amount + 1);
    waysOfDoingN[0] = 1;
    
    for (const int current_denomination : denominations) { // iterate through the denominations
        cout << "Current denomination " << current_denomination << endl;
        for (int base_amount = current_denomination; 
             base_amount <= amount;
             base_amount++) {
                 cout << "base amount for iteration " << base_amount << endl;
                 int remainder_amount = base_amount - current_denomination;
                 cout << "remainder amount for iteration " << remainder_amount << endl;
                 waysOfDoingN[base_amount] += waysOfDoingN[remainder_amount];
                 cout << "Ways of making change for " << base_amount << " so far " << waysOfDoingN[base_amount] << endl;
             }
    }
    
    return waysOfDoingN[amount];
}                                

int main ()
{
    vector<int> denominations = {1, 2, 3, 4};
    cout << numberOfWaysToMakeChange(4, denominations) << endl;
    return 0;
}
