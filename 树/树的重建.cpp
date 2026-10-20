/*我们使用前序遍历+中序遍历  中序遍历+后序遍历*/

/*我们首先理清这两个序列的区别*/
/*前序： *root* *左子树前序序列* *右子树前序序列*  */
/*中序： *左子树中序序列* *root* *右子树中序序列*  */
/*总体采用先根构造*/
/*先找到当前根节点，构造根节点*/
/*再通过递归分别构造左右子树，每次传入这一个子树的两种便利方式*/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    TreeNode* right;
    TreeNode* left;
    int val;
    TreeNode(TreeNode* left, TreeNode* right, int val){
        this -> left = left;
        this -> right = right;
        this -> val = val;
    }
};


TreeNode* buildTree(int* inorder, int* preorder, int len) {
    //终止条件
    if(len <= 0) return nullptr;
    //先找当前的根节点
    /*就是先根便利的第一个元素*/
    int val = preorder[0];
    TreeNode* node = new TreeNode(nullptr, nullptr, val);
    //现在我们需要获得左子树和右子树的长度在分别进行递归
    int i = 0;
    for(; i < len; i++) {
        if(inorder[i] == val) break;
    }
    //i就是左子树长度
    node -> left = buildTree(inorder, &preorder[1], i);
    node -> right = buildTree(&inorder[i+1], &preorder[i+1], len - i - 1);
    return node;
}
int main() {
    int n;
    cin >> n;
    int inOrder[n];
    for(int i = 0; i < n; i++) {
        cin >> inOrder[i];
    }
    int preOrder[n];
    for(int i = 0; i < n; i++) {
        cin >> preOrder[i];
    }
    TreeNode* root = buildTree(inOrder, preOrder, n);
}