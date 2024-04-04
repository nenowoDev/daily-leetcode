#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> a;
        for(auto m:nums){
            a[m]+=1;
            if(a[m]>1)
                return m;
        }
        return -1;
    }
};

int main(){
    vector<int> test;
    test.push_back(1);
    test.push_back(4);
    test.push_back(3);
    test.push_back(2);
    test.push_back(3);

    Solution a;
    cout<<a.findDuplicate(test);

    

}