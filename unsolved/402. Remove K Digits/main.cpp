#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string temp;
        
        for(int i=0;i<num.length();i++){
            if(num[i]==' ') num.erase(i,1);
        }

        int smallest=stoi(num);

        for(int i=0;i<num.size()-k+1;i++){
            temp=num;
            temp.erase(i,min(k,(static_cast<int>(num.length())-i)));
            if(temp=="") temp="0";
            if(stoi(temp)<smallest)
                smallest=stoi(temp);        
        }

        return to_string(smallest);;

    }
};


int main(){
    string a="10";
    Solution s;
    cout<<s.removeKdigits(a,2);
}