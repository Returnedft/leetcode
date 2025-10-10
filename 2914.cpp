// Medium - Minimum Number of Changes to Make Binary String Beautiful

#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int minChanges(string s) {
        stack<char> st;
        int minChanges = 0;

        for (auto c : s){
            if (st.empty()){
                st.push(c);
                continue;
            }
            
            if (c == '0' && st.top() == '0' || c == '1' && st.top() == '1'){
                st.pop();
            }
            else if (c == '1' && st.top() == '0' || c == '0' && st.top() == '1'){
                st.pop();
                minChanges++;
            }
        }
        
        return minChanges;
        
    }
};

int main(){
    
    Solution sol;
    cout << sol.minChanges("1001") << endl;
    cout << sol.minChanges("10") << endl;
    cout << sol.minChanges("0000") << endl;
    cout << sol.minChanges("001011") << endl;
    cout << sol.minChanges("11000111") << endl;
    return 0;
}