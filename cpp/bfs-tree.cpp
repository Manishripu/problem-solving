#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x)  {
            val=x;
            left=nullptr;
            right=nullptr;
        }
        TreeNode(int x,TreeNode * l,TreeNode * r){
            val=x;
            left=l;
            right=r;
        }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        // Edge Case: Empty tree
        if (root == nullptr) {
            return result; 
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currNode = q.front();
                q.pop();
                
                currentLevel.push_back(currNode->val);
                
                // Push children to the queue for the next level
                if (currNode->left != nullptr) {
                    q.push(currNode->left);
                }
                if (currNode->right != nullptr) {
                    q.push(currNode->right);
                }
            }
            // Add the fully processed level to our result
            result.push_back(currentLevel);
        }
        
        return result;
    }
  
};

  int main(){
      TreeNode* root=new TreeNode(5);
      root->left=new TreeNode(6,new TreeNode(1),new TreeNode(2));
      root->right=new TreeNode(7,new TreeNode(10),new TreeNode(12));
      Solution sol ;
      vector<vector<int>> ans=sol.levelOrder(root);
      for(auto& level:ans){
          for(auto i:level){
              cout<<i<<" ";
          }
          cout<<"\n";
      }
      delete root;
        return 0;
    }