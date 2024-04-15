#include <vector>
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
    void visitLeft(TreeNode* left,vector<string> &sum){
        
        (sum)[sum.size()-1]+=to_string(left->val);
        
        
        if(left->left!=nullptr&&left->right!=nullptr){
            string tempp=sum.back();
            visitLeft(left->left,sum);
            sum.push_back(tempp);
            visitRight(left->right,sum);
        }

        else if(left->left!=nullptr)
            visitLeft(left->left,sum);

        else if(left->right!=nullptr)
            visitRight(left->right,sum);

    }
    void visitRight(TreeNode* right,vector<string> &sum){
        
        (sum)[sum.size()-1]+=to_string(right->val);
        
        
        if(right->right!=nullptr&&right->left!=nullptr){
            string tempp=sum.back();
            visitRight(right->right,sum);
            sum.push_back(tempp);
            visitLeft(right->left,sum);
        }

        else if(right->right!=nullptr)
            visitRight(right->right,sum);
        
        else if(right->left!=nullptr)
            visitLeft(right->left,sum);
     
    }
    int sumNumbers(TreeNode* root) {
        
        vector<string> sum;
        if(root->left==nullptr&&root->right==nullptr)
            sum.push_back(to_string(root->val));
        if(root->right!=nullptr){
            sum.push_back(to_string(root->val));
            visitRight(root->right,sum);
        }
        if(root->left!=nullptr){
            sum.push_back(to_string(root->val));
            visitLeft(root->left,sum);
        }

        int ret=0;
        for(int i=0;i<sum.size();i++){
            ret+=stoi(sum[i]);
        }
    

        return ret;
    }
};


int main(){
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(9);
    root->right=new TreeNode(0);

    root->left->left=new TreeNode(5);
    root->left->right=new TreeNode(1);

    Solution a;
    // vector<string> *b=new vector<string>();
    // b.push_back("a");
    // b.push_back("b");
    // b.push_back("c");
    // (*b)[1]+="1";
    // cout<< (*b)[1];
    
    cout<<a.sumNumbers(root);
    
}




