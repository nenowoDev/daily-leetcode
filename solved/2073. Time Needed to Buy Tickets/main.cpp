#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int sum=0;
        for(int i=0;i<tickets.size();i++){
            if(i<k) sum+=min(tickets[k],tickets[i]);
            if(i==k) sum+=tickets[k];
            if(i>k) sum+=min(tickets[k]-1,tickets[i]);
        }
        return sum;
    }
};

/*
check draw.png
if before tickets[k], then choose min(tickets[k],tickets[i]) and add it to sum
this is because when k=0, all index , 0-k , will pass at most exactly tickets[k]
or at least, exactly tickets[i] times

when i=k, just take tickets[k] and put it in sum

if i>k, min(tickets[k]-1,tickets[i]) and add it to sum
this is because from k+1 to tickets.size(),it will pass at most exactly tickets[k] times
or at least exactly tickets[i] times


*/

int main(){

    Solution a;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);

    cout<<a.timeRequiredToBuy(v,3);


}