#include <iostream>
using namespace std;
// p a l i n d r o m e N = 10

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void ReverseString(string& testString) {
    int stringLength = testString.length();
    int midLength = (stringLength % 2 == 0)  ? 
                    (stringLength / 2) - 1   :
                    (stringLength / 2);
                    
    for (int i = 0; i <= midLength; i++) {
        char temp = testString[i];
        testString[i] = testString[stringLength - i - 1];
        testString[stringLength - i - 1] = temp;
    }
}

int main ()
{
    string a("palindrome");
    ReverseString(a);
    cout << a << endl;
    return 0;
}
