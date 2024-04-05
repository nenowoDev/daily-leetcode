#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string makeGood(string s) {

        for(int i=0;i<s.length();i++){
            if(abs(s[i]-s[i+1])==32){
                s.erase(i,2);
                i=-1;
            }

        }  
        
        return s;   
    }
};

int main(){


        string a="aAbcCB";
        // cout<<a.length()<<endl;
        // // cout<<static_cast<char>(toupper(a[0]));
        // cout<<a[3]<<endl;
        // cout<<a.erase(3,1)<<endl;

        // cout<<a[3]<<endl;
        // cout<<a.length()<<endl;

        // cout<<char(a[0]-32);
        Solution s;
        cout<<s.makeGood(a);
}