#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        
        if(k<=0)
            return 0;
        
        int count=0;
        int prod=1;
        for(int right=0;right<nums.size();right++){
            prod=nums[right];
            if(prod<k)
                count++;

            for(int left=right+1;left<nums.size();left++){
                prod*=nums[left];
                
                if(prod<k)
                    count++;
                else
                    break;
                    
            }
        }

        cout<<"\n\n";
        return count;

    }
};

int main(){

    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);


    Solution aa;
    cout<<aa.numSubarrayProductLessThanK(a,10);

}