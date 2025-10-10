// Map Sum Pairs

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class MapSum {
public:
    MapSum() {
        map_ = {};
    }
    
    void insert(string key, int val) {
        map_[key] = val;
    }
    
    int sum(string prefix) {
        int len = prefix.size();
        int sum = 0;
        for (pair<string,int> vals : map_){
            //cout << vals.first.substr(0,len) << endl;
            if (vals.first.substr(0,len) == prefix) sum += vals.second;
        }

        return sum;
    }
private:
    unordered_map<string,int> map_;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

 int main(){
    MapSum* obj = new MapSum();
    obj->insert("apple", 3);
    cout << obj->sum("ap") << endl; // 3
    obj->insert("app", 2);
    cout << obj->sum("ap") << endl; // 5

    return 0;
 }