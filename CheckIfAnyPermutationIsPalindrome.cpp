#include <iostream>
#include <unordered_set>
using namespace std;

bool ContainsPalindromicChars (const string& arg)
{
    unordered_set<char> unpaired_chars;
    
    for (int i = 0; i < arg.length(); i++) {
        char current_char = arg[i];
        
        if (unpaired_chars.find(current_char) == unpaired_chars.end()) {
            unpaired_chars.insert(current_char);
        }
        else {
            unpaired_chars.erase(current_char);
        }
    }
    
    if (unpaired_chars.size() > 1) {
        return false;
    }
    else {
        return true;
    }
}

int main ()
{
    cout << ContainsPalindromicChars("civil") << endl;
    return 0;
}

