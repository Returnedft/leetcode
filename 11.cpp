// Container with Most Water # MEDIUM

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0;
        int last = height.size() - 1;
        int currMax = min(height[first],height[last]) * (last - first);

        //cout << currMax; 

        while (first < last){
            int possMax1 = min(height[first+1],height[last]) * (last - first - 1);
            int possMax2 = min(height[first],height[last-1]) * (last - first - 1);
            if (possMax1 >= currMax) {
                currMax = possMax1;
                first++;
            }
            else if (possMax2 >= currMax) {
                currMax = possMax2;
                last--;
            }
            else if (height[first] < height[last]) first ++;
            else last --;
            
            //cout << "CurrMax is :" << currMax << endl;
        }

        return currMax;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl; // Output: 49
    return 0;
}