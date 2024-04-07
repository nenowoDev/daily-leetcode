#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool checkValidString(string s) {

        int openleftmax=0,openleftmin=0;
        for(char a:s){
            if(a=='(') {openleftmin++; openleftmax++;}
            if(a==')') {openleftmin--; openleftmax--;}
            if(a=='*') {openleftmin--; openleftmax++;}

            if(openleftmin<0&&openleftmax>0) openleftmin=0;
            if(openleftmax<0) return false;


        }

        if(openleftmin<=0 && openleftmax>=0) return true;

        return false;
    }

    
};




int main(){
    Solution a;
    string s="((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()";

    cout<<a.checkValidString(s);
}

