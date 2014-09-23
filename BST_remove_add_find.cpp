//
//  main.cpp
//  BST_add_remove_find
//
//  Created by Junwei Hu on 9/23/14.
//  Copyright (c) 2014 Junwei Hu. All rights reserved.
//

#include <iostream>

using namespace std;
class BST {
private:
    class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x):val(x), left(NULL), right(NULL){}
        TreeNode():val(0),left(NULL),right(NULL) {}
        ~TreeNode() {}
    };
    
    
    
public:
    TreeNode* root;
    
    
    int find(int target) {
        return find(target, root);
    }
    
    void add(int target) {
        root = add(target, root);
    }
    
    int find(int target, TreeNode* curr) {
        if (curr == NULL) return -1;
        if (target == curr->val) return root->val;
        if (target < curr->val) return find(target, curr->left);
        return find(target, curr->right);
    }
    
    TreeNode* add(int target, TreeNode* curr) {
        if (curr == NULL) {
            return new TreeNode(target);
        }
        if (curr->val > target) curr->left = add(target, curr->left);
        else curr->right = add(target, curr->right);
        return curr;
    }
    
    void inorderPrint(TreeNode* curr) {
        if (curr == NULL) return;
        inorderPrint(curr->left);
        cout << curr->val << " ";
        inorderPrint(curr->right);
        return;
    }
    
    /* helper function for replace the leftRightMost */
    TreeNode* replaceLeftRightMost(TreeNode* curr, TreeNode* replace) {
        if (replace->right == NULL) {
            curr->val = replace->val;
            TreeNode* tmp = replace->left;
            delete replace;
            return tmp;
        }
        curr = replaceLeftRightMost(curr, replace->right);
        return curr;
    }
    
    void remove(int target) {
        remove(target, root);
        return;
    }
    
    TreeNode* remove(int target, TreeNode* curr) {
        if (curr == NULL) return NULL;
        if (curr->val == target) {
            //replace the leftRightMost node with the target delete node(curr)
            //dealloc
            if (curr->left == NULL) return curr->right;
            if (curr->right == NULL) return curr->left;
            curr = replaceLeftRightMost(curr, curr->left);
            return curr;
            
        }
        if (curr->val > target) {
            curr->left = remove(target, curr->left);
        }
        else {
            curr->right = remove(target, curr->right);
        }
        return curr;
    }
    
    
    
    
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    BST* tree = new BST();
    tree->add(1);
    tree->add(2);
    tree->add(3);
    tree->inorderPrint(tree->root);
    cout << "\n[find]: "<<tree->find(3, tree->root) << endl;
    tree->remove(2);
    cout << "after remove" << endl;
    tree->inorderPrint(tree->root);
    return 0;
}
