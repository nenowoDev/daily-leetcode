#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;


class Solution {
public:

    
    
    void dfs(unordered_map<int,int> &visited,unordered_map<int,vector<int>> &mp,int src){

        int temp=0;
        visited[temp]++;
        
        for(int i=0;i<mp[src].size();i++){
            temp=mp[src][i];
            if(visited[temp]==0)
                dfs(visited,mp,temp);
        }
        
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> mp;
        unordered_map<int,int> visited;
        if(edges.empty()) return true;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
            visited[edges[i][0]]=0;
            visited[edges[i][1]]=0;
        }
    
        dfs(visited,mp,source);

        if(visited[destination]==0)
            return false;
        else
            return true;
 
    }

    
};


int main(){

    Solution a;
    vector<vector<int>> e;

    e.push_back({4,3});
    e.push_back({1,4});
    e.push_back({4,8});
    e.push_back({1,7});
    e.push_back({6,4});
    e.push_back({4,2});
    e.push_back({7,4});
    e.push_back({4,0});
    e.push_back({0,9});
    e.push_back({5,4});


    cout<<a.validPath(10,e,5,9);

}