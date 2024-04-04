#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch=='('||ch==')') st.push(ch);
        }
        // while(!st.empty()){
        //     cout<<st.top();
        //     st.pop();
        // }
        int c=0;
        int max=0;
        while(!st.empty()){
            if(st.top()==')'){
                c++;
                st.pop();
                while(st.top()!='('){
                    if(st.top()==')') c++;
                    st.pop();
                }
                if(c>max)
                    max=c;
                while(c>0&&st.top()!=')'){
                    if(st.top()=='(') c--;
                    st.pop();
                }

            }
                
        }

        return max;
    }
};


int main(){
    string s="(1+(2*3)+((8)/4))+1";
    Solution a;

    cout<<a.maxDepth(s);
}