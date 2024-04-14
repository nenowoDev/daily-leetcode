#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include <vector>
#include <queue>

using namespace std;
//i dont know how to use q
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int> r(deck.size());
        vector<int> q;
        
        for(int i=0;i<deck.size();i++)
            q.push_back(i);
        
        int s=deck.size();

        for(int i=0;i<s;i++){
            r[q.front()]=deck[i];
            q.erase(q.begin());
            if(!q.empty()){
                q.push_back(q.front());
                q.erase(q.begin());
            }                        
        }

    
        return r;

    }
};

int main(){

    Solution a;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    
    vector<int> b=a.deckRevealedIncreasing(v);
    for(int a:b){
        cout<<a;
        cout<<",";
    }
}