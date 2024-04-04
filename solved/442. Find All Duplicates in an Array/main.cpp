#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int,int> a;
        for(auto m:nums){
            a[m]+=1;
            if(a[m]==2)
                ret.push_back(m);
        }
        
        return ret;
    }
};

int main(){
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(2);
    test.push_back(3);

    Solution a;
    for(auto m:a.findDuplicate(test))
        cout<<m;

    

}