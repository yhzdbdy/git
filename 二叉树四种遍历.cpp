#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    TreeNode* right;
    TreeNode* left;
    int val;
};

//前序
void preTraversal(TreeNode* root) {
    if(root == nullptr) return;
    stack<TreeNode*> st;
    TreeNode* p = root;
    while(true) {
        while(p != nullptr) {
            //遍历中节点
            cout << p -> val << endl;
            st.push(p);
            p = p -> left;
        }
        if(st.empty()) return;
        //到达空节点弹栈遍历右子树
        p = st.top();
        st.pop();
        p = p -> right;
    }
}

//中序
void inTraversal(TreeNode* root) {
    if(root == nullptr) return;
    stack<TreeNode*> st;
    TreeNode* p = root;
    while(true) {
        while(p != nullptr) {
            //中节点先入栈
            st.push(p);
            p = p -> left;
        }
        if(st.empty()) return;
        //到达空节点先访问左节点再遍历右子树
        p = st.top();
        st.pop();
        cout << p -> val << endl;
        p = p -> right;
    }
}

//后序
void posTraversal(TreeNode* root) {
    if(root == nullptr) return;
    stack<TreeNode*> st;
    TreeNode* p = root;
    //额外申请一个空间存贮前一个遍历的节点
    TreeNode* pre = nullptr;
    while(true) {
        while(p != nullptr) {
            //先压栈
            st.push(p);
            p = p -> left;
        }
        if(st.empty()) return;
        //遇到空节点开始弹栈
        p = st.top();
        //我们在该节点的右子树为空或者刚才遍历过的情况下可以访问这个节点
        if(p -> right == nullptr || p -> right == pre) {
            st.pop();//一定不要忘记弹栈
            cout << p -> val << endl;
            //前一个访问的节点变成当前节点
            pre = p;
            //p变成空节点
            p = nullptr;
        } else {
            //否则需要压入该节点的右子树继续遍历
            p = p -> right;//千万不要把右子树压栈，改变p就好了
        }
    }
}

//层序
void levTraversal(TreeNode*root) {
    if(root == nullptr) return;
    queue<TreeNode*> que;
    TreeNode* p = root;
    //先入根节点
    que.push(p);
    while(!que.empty()) {
        //当前层的元素个数
        int size = que.size();
        //依次遍历当前层的节点
        for(int i = 0; i < size; i++) {
            p = que.front();
            que.pop();
            cout << p -> val << endl;

            //还需要把该节点的左右子树入队,不要入空节点
            if(p -> left) que.push(p -> left);
            if(p -> right) que.push(p -> right);
        }
    }
}