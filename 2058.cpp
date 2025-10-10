// Find the Minimum and Maximum Number of Nodes Between Critical Points


#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> criticalPos;
        int pos = 1;

        ListNode *curr = head->next;
        ListNode *bef = head;

        while (curr->next != nullptr){

            if ((bef->val > curr->val && curr->val < curr->next->val) || (bef->val < curr->val && curr->val > curr->next->val)){  // local minima  | local maxima
                criticalPos.push_back(pos);
            }

            pos++;
            bef = curr;
            curr = curr->next;
        }

        if (criticalPos.size() < 2) return {-1,-1};
        
        int minDist = INT_MAX;
        int maxDist = criticalPos[criticalPos.size()-1] - criticalPos[0]; 

        for (int i = 0; i < criticalPos.size() - 1; i++){
            //cout << "Pos " << criticalPos[i] << endl;
            int possDist = criticalPos[i+1] - criticalPos[i];
            if (possDist < minDist) minDist = possDist;
        }
        //cout << "Pos " << criticalPos[criticalPos.size()-1] << endl;



        return {minDist,maxDist};
    }
};

int main(){
    Solution sol;
    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);
    vector<int> res = sol.nodesBetweenCriticalPoints(head);
    cout << "Min: " << res[0] << " Max: " << res[1] << endl;
    return 0;
}