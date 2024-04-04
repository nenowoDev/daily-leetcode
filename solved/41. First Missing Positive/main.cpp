#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        

        
        sort(nums.begin(),nums.end());
        int prev=0;
        
        if((nums.front()>1))
            return 1;

        if(nums.back()<1)
            return 1;

        for(int a:nums){
            
            if((a>0)&&(a-prev>1)){
                
                
                if(prev<=0&&a!=1)
                    return 1;
                if(prev>0)
                    return prev+1;
                
            }
            prev=a;
        }

        return nums.back()+1;
    }
};

int main(){
    Solution a;
    vector<int> test;
    
    test.push_back(0);
    test.push_back(2);
    



    cout<<a.firstMissingPositive(test);
    cout<<"\n\n";
    for(int a:test){
        cout<<a<<"\n";
    }
}