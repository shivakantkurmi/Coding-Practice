/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
    int ans = INT_MIN;

    int solve(Node* root) {
        if (!root) return 0;

        //we will use this if its maximum path sum between any two nodes not leaf to leaf
        //by using this we can ignore negative root sum ie roots till whome the sum id negative 
        //so its only give node to node maxPathSum
        
        // int lSum = max(0, solve(root->left));
        // int rSum = max(0, solve(root->right)); 
        
        
        //leaf to leaf max path sum
        int lSum = solve(root->left);
        int rSum = solve(root->right); 
        
        if(root->left && root->right){
            ans = max(ans, root->data + lSum + rSum);
            return root->data + max(lSum, rSum);
            
        }
        //if only one side child exist due to we now not using max(0,solve(root->left)) or other one so if only one child exist we need to do it
        return root->data + (root->left?lSum:rSum);
    }

public:
    int maxPathSum(Node* root) {
        int temp = solve(root);
        //skew tree sppecific due to leaf to leaf path sum if not leaft to leaf we need not use this 
        if (root->left == nullptr || root->right == nullptr)
            return max(ans, temp);
        
        return ans;
    }
};
