// Power of 2 # EASY

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return 0;
        int val = n;
        while (val%2 == 0){
            val /= 2;
        }

        if (val == 1) return true;
        return false;
    }
};


int main(){
    Solution sol;
    cout << (sol.isPowerOfTwo(0));
    return 0;
}