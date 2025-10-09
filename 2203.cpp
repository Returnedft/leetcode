// Minimum Weighted Subgraph with the Required Paths # HARD

// This problem took me quite some time to solve (9 tries). At first i thought it was a simple dijkstra problem and we could assume that at least a path either from src1 to dest or from src2 to dest exists in the subgraph. But that is not the case, so we need to consider the possibility that both paths share some nodes in between.
// The hints on leetcode were very useful to understand that we need to find a middle node that connects both src1 path and src2 path to dest.
// Although i haven't done dijkstra in a while, the implementation was straightforward. The only tricky part was to deduct that we needed to run dijkstra from each required source and also from the destination on the reversed graph.

#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<pair<int, int>>> reverseAdj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            reverseAdj[edge[1]].push_back({edge[0], edge[2]});
        }

        // Run Dijkstra from both src1 and src2
        vector<long long> src1Dists = diijkstra(n, adj, src1);
        vector<long long> src2Dists = diijkstra(n, adj, src2);

        // Reverse Graph and Run Diijkstra from Destination

        vector<long long> distances = diijkstra(n, reverseAdj, dest);

        //cout << "Src1 to Dest is " << distances[src1].first << endl;
        //cout << "Src2 to Dest is " << distances[src2].first << endl;

        long long ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            if (src1Dists[i] == LONG_LONG_MAX || src2Dists[i] == LONG_LONG_MAX || distances[i] == LONG_LONG_MAX) continue;
            ans = min(ans, src1Dists[i] + src2Dists[i] + distances[i]);
        }

        return ans == LONG_LONG_MAX ? -1 : ans;

    }

    vector<long long> diijkstra(int n, vector<vector<pair<int, int>>>& adj, int src){

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minHeap;

        vector<long long> distances(n, LONG_LONG_MAX);

        minHeap.push({0,src});
        distances[src] = 0;

        while (!minHeap.empty()){
            int nodeMin = minHeap.top()[1];
            long long distMin = minHeap.top()[0];
            minHeap.pop();
            if (distMin > distances[nodeMin]) continue;

            for (auto& [neighboor, weight] : adj[nodeMin]){
                if (distances[neighboor] > distances[nodeMin] + weight){

                    distances[neighboor] = distances[nodeMin] + weight;
                    minHeap.push({distances[neighboor], neighboor});

                }
            }
        }

        return distances;
    }
};

int main(){

    /*
    Solution sol1;
    vector<vector<int>> edges = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}}; // 9
    long long val = sol1.minimumWeight(6, edges, 0, 1, 5);


    Solution sol2;
    vector<vector<int>> edges2 = {{0,1,1},{2,1,1}};
    long long val2 = sol2.minimumWeight(3, edges2, 0, 1, 2); // -1

    Solution sol3;
    vector<vector<int>> edges3 = {{4,7,24},{1,3,30},{4,0,31},{1,2,31},{1,5,18},{1,6,19},{4,6,25},{5,6,32},{0,6,50}};
    long long val3 = sol3.minimumWeight(8, edges3, 4, 1, 6); // 44

    Solution sol4;
    vector<vector<int>> edges4 = {{0,2,1},{0,3,1},{2,4,1},{3,4,1},{1,2,1},{1,3,10}};
    long long val4 = sol4.minimumWeight(5, edges4, 4, 0, 1); // 4


    Solution sol5;
    vector<vector<int>> edges5 = {{0,2,10},{1,2,10},{0,1,1}};
    long long val5 = sol5.minimumWeight(3, edges5, 0, 1, 2); // 11

    */

    Solution sol6;
    vector<vector<int>> edges6 = {{0,2,10},{0,4,2},{1,4,2},{1,3,10},{3,5,10},{4,5,20},{2,5,10}};
    long long val6 = sol6.minimumWeight(6, edges6, 0, 1, 5);

    cout << val6 << endl;

    return 0;
}