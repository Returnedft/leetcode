// Ways to place houses # MEDIUM

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int countHousePlacements(int n) {
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(2);

        const int mod = 1000000007;
        for (int i = 2 ; i <= n; i++){
            dp.push_back((dp[i - 1] + dp[i - 2]) % mod);
        }

        long long ways = (1LL * dp[n] * dp[n]) % mod;


        return (int) ways;
        
    }
};


int main() {
    Solution sol;
    int n = 1000;
    cout << sol.countHousePlacements(n);
    return 0;
}