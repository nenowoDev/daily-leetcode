#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reversePrefix(string &word, char ch) {
        stack<char> a;
        bool found=false;
        for(int i=0;i<word.size()&&!found;i++){
            if(word[i]==ch){
                a.push(word[i]);
                for(int j=0;j<=i;j++){
                    word[j]=a.top();
                    a.pop();
                    found=true;
                }
            }
            else
                a.push(word[i]);
        }
        return word;
    }
};


int main(){
    string a="aa";
    Solution aa;
    cout<<aa.reversePrefix(a,'b');
}