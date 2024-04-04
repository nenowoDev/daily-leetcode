#include <iostream>
#include <string>
#include <hashtable.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size()!=t.size()) return false;

        unordered_map<char,char> mp,rmp;

        for(int i=0;i<s.size();i++){

            if(mp.find(s[i])==mp.end()&&rmp.find(t[i])==rmp.end()){
                mp[s[i]]=t[i];
                rmp[t[i]]=s[i];
            } 
            else if((mp[s[i]]!=t[i])||rmp[t[i]]!=s[i]) return false;
            

        }
        
        return true;

    }
};

int main(){

    string a="baba";
    string b="badc";

    Solution aa;

    cout<<aa.isIsomorphic(a,b);

}