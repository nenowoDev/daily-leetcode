#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& grid,int i,int j,int &perimeter){

        //2 ways-collapsing perimeter, set to 4 , each visit -2(for overlapping)
        //but prob is when the U problem 
        //1  2    goes 1-2-3-4,,, 4 doesnt know 1 is next to it, so have overlap
        //4  3
        //theres problem a solution to this using normal for loop or something idk

        //second way, just check for water/out of bound and add 1 for each


        grid[i][j]=-1;

        if(i+1<grid.size()&&grid[i+1][j]==1)    dfs(grid,i+1,j,perimeter);
        if(j+1<grid[0].size()&&grid[i][j+1]==1) dfs(grid,i,j+1,perimeter);
        if(i-1>=0&&grid[i-1][j]==1)             dfs(grid,i-1,j,perimeter);
        if(j-1>=0&&grid[i][j-1]==1)             dfs(grid,i,j-1,perimeter);

        if(i+1>=grid.size()||grid[i+1][j]==0)       perimeter++;
        if(j+1>=grid[0].size()||grid[i][j+1]==0)    perimeter++;
        if(i-1<0||grid[i-1][j]==0)                  perimeter++;
        if(j-1<0||grid[i][j-1]==0)                  perimeter++;

    
    }

    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int perimeter=0;
        bool found=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,perimeter);
                    found=true;
                    break;
                } 
            }
            if(found) break;      
        }

        return perimeter;

    }
};

int main(){
    vector<vector<int>> grid;
    // grid.push_back({0,1,0,0});
    // grid.push_back({1,1,1,0});
    // grid.push_back({0,1,0,0});
    // grid.push_back({1,1,0,0});

    grid.push_back({1,1});
    grid.push_back({1,1});

    Solution a;
    cout<<a.islandPerimeter(grid);

}