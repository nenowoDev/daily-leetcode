#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<char> ch;
        int yes=0,k=0;
        for(char c:s){
            ch.push(c);
            if(c==' ')
                yes++;
        }

        int c=0;
        while(ch.top()==' '){
            ch.pop();
            yes--;
            k++;
        }
        if(yes>0){
            
            while(ch.top()!=' '){
                ch.pop();
                c++;
            }
        }
        if(yes==0)
            c=s.length()-k;
        return c;

    }

    int alengthofLastWord(string s){
        int pos=s.size()-1;

        while(pos>=0&&s[pos]==' ')
            pos--;

        int c=0;

        while(pos>=0&&s[pos]!=' '){
            c++;
            pos--;
        }
            

        return c;

    }
};

int main(){
    Solution a;
    string b="c ";
    cout<<a.lengthOfLastWord(b);
}