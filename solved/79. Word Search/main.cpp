#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    

    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int columns=board[0].size();

        function<bool(int,int,int)> bt = [&](int rr,int cc,int ww){
            if(ww==word.size()) return true;
            if(rr>=rows||cc>=columns||cc<0||rr<0||board[rr][cc]!=word[ww]) return false;

            char temp = board[rr][cc];
            board[rr][cc] = '#'; 
            
            if(bt(rr+1,cc,ww+1)||bt(rr-1,cc,ww+1)||bt(rr,cc+1,ww+1)||bt(rr,cc-1,ww+1)) return true;
            
            board[rr][cc] = temp;

            return false;
        };

        for(int r=0;r<rows;r++){
            for(int c=0;c<columns;c++){
                if(bt(r,c,0)) return true;
            }
        }
        
        return false;
    }
};



int main(){
    Solution a;
    vector<vector<char>> vc;
    vc.push_back({'a','b','c'});
    vc.push_back({'d','e','f'});
    vc.push_back({'g','h','i'});


    cout<<a.exist(vc,"abc");
    // for(auto cc:vc){
    //     for(char c:cc)
    //         cout<<c<<endl;
    // }
}