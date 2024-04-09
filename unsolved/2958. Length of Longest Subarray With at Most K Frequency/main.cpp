#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int> a;

        int hh=0;
        
        for(int r=0,l=0;l<nums.size();r++){

            a[nums[r]]+=1;
            

        }
        
        
        
        return hh;

    }
};


int main(){

    Solution a;
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(2);
    b.push_back(1);
    b.push_back(3);
    b.push_back(1);
    b.push_back(1);

    cout<<a.maxSubarrayLength(b,3);

}
