#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int c=0;
        int d=0;
        int n=nums.size();

        for(int l=0,r=0;l<n;l++){

            
            while(d<k){
                if(mp[nums[r]]==0)
                    d++;
                mp[nums[r]]++;
                
                r++;
            }
            while(d==k&&mp[nums[r]]!=0){
                mp[nums[r]]++;
                r++;
                c += r - l;
            }

            mp[nums[l]]--;
            if(mp[nums[l]]==0)
                d--;

        }

        return c;
    }
};

int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);


    Solution s;

    cout<<s.subarraysWithKDistinct(v,2);

}