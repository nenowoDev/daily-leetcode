#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j){

        grid[i][j]='0';

        if(i+1<grid.size()&&grid[i+1][j]=='1')    dfs(grid,i+1,j);
        if(j+1<grid[0].size()&&grid[i][j+1]=='1') dfs(grid,i,j+1);
        if(i-1>=0&&grid[i-1][j]=='1')             dfs(grid,i-1,j);
        if(j-1>=0&&grid[i][j-1]=='1')             dfs(grid,i,j-1);

        
    
    }

    
    int numIslands(vector<vector<char>>& grid) {
        
        int noisland=0;
        bool found=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    noisland++;
                } 
            }
                
        }

        return noisland;

    }
};

int main(){
    vector<vector<char>> grid;
    // grid.push_back({0,1,0,0});
    // grid.push_back({1,1,1,0});
    // grid.push_back({0,1,0,0});
    // grid.push_back({1,1,0,0});

    grid.push_back({'1','1'});
    grid.push_back({'1','1'});

    Solution a;
    cout<<a.numIslands(grid);

}