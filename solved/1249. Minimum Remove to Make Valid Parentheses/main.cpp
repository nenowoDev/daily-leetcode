#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int leftopen=0;
        vector<int> temp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                leftopen++;
                temp.push_back(i);  
            } 
            if(s[i]==')'){
                leftopen--;
                if(!temp.empty())
                    temp.pop_back();
            }

            if(leftopen<0){
                s.erase(i,1);
                leftopen++;
                i--;
            }
                
 
        }

        for(int i=temp.size()-1;i>=0;i--){
            s.erase(temp[i],1);
        }
        
        return s;
    }
};

int main(){
    string s="())()(((";
    Solution a;

    cout<<a.minRemoveToMakeValid(s);
}