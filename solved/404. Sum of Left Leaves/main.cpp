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
    void visitLeft(TreeNode* left,int &sum){
        if(left->left!=nullptr){
            visitLeft(left->left,sum);
        }
        if(left->right!=nullptr){
            visitRight(left->right,sum);
        }
        if(left->left==nullptr&&left->right==nullptr){
            sum+=left->val;
            
        }
    }
    void visitRight(TreeNode* right,int &sum){
        if(right->right!=nullptr){
            visitRight(right->right,sum);
        }
        if(right->left!=nullptr){
            visitLeft(right->left,sum);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root->right!=nullptr){
            visitRight(root->right,sum);
        }
        if(root->left!=nullptr){
            visitLeft(root->left,sum);
        }
        return sum;
    }
};


int main(){
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);

    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    Solution a;
    cout<<a.sumOfLeftLeaves(root);
}