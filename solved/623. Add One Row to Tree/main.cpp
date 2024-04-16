#include <iostream>
#include <vector>

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth,int cur=1) {
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            root=newroot;    
        } 

        else if(cur<depth-1){
            if(root->left!=nullptr)
                addOneRow(root->left,val,depth,cur+1);

            if(root->right!=nullptr)
                addOneRow(root->right,val,depth,cur+1);
        }

        else{
            if(root->right!=nullptr){
                TreeNode* temp=root->right;
                root->right=nullptr;
                root->right=new TreeNode(val);
                root->right->right=temp;
            }

            else if(root->right==nullptr)
                root->right=new TreeNode(val);
            

            if(root->left!=nullptr){
                TreeNode* temp=root->left;
                root->left=nullptr;
                root->left=new TreeNode(val);
                root->left->left=temp;
            }

            else if(root->left==nullptr)
                root->left=new TreeNode(val);
            
           
        }

        return root;
    }
};

int main(){

    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(6);

    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(1);

    root->right->left=new TreeNode(5);

    Solution a;
    TreeNode* t=a.addOneRow(root,1,2);
    

}