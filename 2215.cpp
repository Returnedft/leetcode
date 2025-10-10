// Different items between both vectors

#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> first;
        vector<int> second;

        for (auto &value : nums1){
            if (find(nums2.begin(),nums2.end(), value) == nums2.end() && find(first.begin(),first.end(), value) == first.end()) first.push_back(value);
        }

        for (auto &value : nums2){
            if (find(nums1.begin(),nums1.end(), value) == nums1.end() && find(second.begin(),second.end(), value) == second.end()) second.push_back(value);
        }
        
        return {first,second};
    }  
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> result = sol.findDifference(nums1, nums2);
    cout << result[0][0];
    return 0;
}