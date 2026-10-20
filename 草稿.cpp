#include<bits/stdc++.h>
using namespace std;

class TreeNode;
// void postTraversal(TreeNode* root) {
//     TreeNode* cur = root;
//     TreeNode* pre = nullptr;
//     if(root == nullptr) return;
//     stack<TreeNode*> st;
//     while(true) {
//         while(cur != nullptr) {
//             st.push(cur);
//             cur = cur -> left;
//         }
//         if(st.empty()) return;
//         cur = st.top();
//         if(cur -> right == nullptr || cur -> right == pre) {
//             cout << cur -> val;
//             pre = cur;
//             cur == nullptr;
//         }else {
//             cur = cur -> right;
//         }
//     }
// }