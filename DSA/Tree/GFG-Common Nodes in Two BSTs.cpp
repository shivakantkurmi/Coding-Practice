/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> findCommon(Node* r1, Node* r2) {
        if(r1 == nullptr || r2 == nullptr) return {};
        if(r1->data == r2->data){
            int tmp = r1->data;
            auto lans = findCommon(r1->left,r2->left);
            lans.push_back(tmp);
            auto rans = findCommon(r1->right,r2->right);
            for(auto x:rans) lans.push_back(x);
            return lans;
        }
        if(r1->data < r2->data){
            auto node = r1->right;
            r1->right = nullptr;
            auto lans = findCommon(r1,r2->left);
            r1->right = node;
            auto rans = findCommon(r1->right,r2);
            for(auto x:rans) lans.push_back(x);
            return lans;
        }
        auto node = r2->right;
        r2->right = nullptr;
        auto lans = findCommon(r1->left,r2);
        r2->right = node;
        auto rans = findCommon(r1,r2->right);
        for(auto x:rans) lans.push_back(x);
        return lans;
    }
};
