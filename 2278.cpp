// Percentage of letter in string

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;

        for (char l : s){
            if (l == letter) count++;
        }

        return round(100*count/s.size());
    }
};

int main() {
    Solution sol;
    string s = "foobar";
    char letter = 'o';
    cout << sol.percentageLetter(s, letter) << endl; // Output: 33
    return 0;
}