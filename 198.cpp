// House Robber # MEDIUM

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(nums[0]);

        for (int i = 2; i <= nums.size(); i++){
            dp.push_back(max(dp[i-1], nums[i - 1] + dp[i-2]));
        }

        return dp[nums.size()];
    }
};



int main() {
    Solution sol;
    vector<int> nums = {100,1,2,100};
    cout << sol.rob(nums) << endl; 
    return 0;
}