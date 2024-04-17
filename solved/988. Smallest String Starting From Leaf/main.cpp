#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    class Solution {
    public:
        void dfs(TreeNode *root,vector<string> &path,string indvpath){

            //ASCII "a" is 97 dec
            indvpath.push_back(static_cast<char>(root->val+97));
            
            if(root->left!=nullptr)
                dfs(root->left,path,indvpath);
            
            if(root->right!=nullptr)
                dfs(root->right,path,indvpath);
                
            if(root->right==nullptr&&root->left==nullptr)
                path.push_back(indvpath);
            
            indvpath.pop_back();
        }

        string smallestFromLeaf(TreeNode* root) {
            
            vector<string> path;
            string individualpath;

            dfs(root,path,individualpath);

            for(int i=1;i<path.size();i++){
                for(int j=1;j>-1&&j<=path[i].size()&&j<=path[i-1].size();j++){
                    if(static_cast<int>(path[i-1][path[i-1].size()-j])!=static_cast<int>(path[i][path[i].size()-j])){
                        //compare end of string at i-1, with i
                        
                        if(static_cast<int>(path[i-1][path[i-1].size()-j])>static_cast<int>(path[i][path[i].size()-j])) path.erase(path.begin()+i-1);
                        else path.erase(path.begin()+i);
                        i--;
                        break;
                    }       
                    else if(static_cast<int>(path[i].size()-j)==0||static_cast<int>(path[i-1].size()-j)==0){
                        if(static_cast<int>(path[i-1].size())>static_cast<int>(path[i].size())) path.erase(path.begin()+i-1);
                        else path.erase(path.begin()+i);
                        i--;
                    }

                }
            }

            
            

            reverse(path[0].begin(),path[0].end());

            return path[0];
        }
    };


int main(){
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);

    
    

    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    

    

    Solution a;
    // vector<string> *b=new vector<string>();
    // b.push_back("a");
    // b.push_back("b");
    // b.push_back("c");
    // (*b)[1]+="1";
    // cout<< (*b)[1];
    
    cout<<a.smallestFromLeaf(root);
    
    
}




