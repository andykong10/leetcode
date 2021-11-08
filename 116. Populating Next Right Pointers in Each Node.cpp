// ***
//
// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The
// binary tree has the following definition:
//
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
//
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should
// be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
//
// Follow up:
//
// You may only use constant extra space.
// Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
//
// Example:
//
// Given the following perfect binary tree,
//
//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
// After calling your function, the tree should look like:
//
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL
//
// ***

// BFS.
// Exactly same solution can be applied to 117. Populating Next Right Pointers in Each Node II
// Almost the same as 102. Binary Tree Level Order Traversal with one added line.
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int currentLevelSize = q.size();
            for (int i = 0; i < currentLevelSize; ++i) {
                Node* node = q.front();
                q.pop();

                // As long as we have not reached the rightmost node in current level,
                // set current node's next to be the next element in the queue
                // (which is the next node on current level)
                if (i < currentLevelSize - 1) {
                    node->next = q.front();
                }

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

// BFS, constant space.
// This solution uses the idea in 102. Binary Tree Level Order Traversal.
// Note that we are told that we are given a perfect binary tree.
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        Node* curLevelStart = root;

        while (curLevelStart) {
            // Current node on current level
            Node* curNode = curLevelStart;

            while (curNode) {
                if (curNode->left) {
                    curNode->left->next = curNode->right;
                }

                if (curNode->right && curNode->next) {
                    curNode->right->next = curNode->next->left;
                }

                curNode = curNode->next;
            }

            // The start position of next level.
            // Note that we are given in the problem that the tree is a perfect binary tree,
            // so curLevelStart->left exists and it is the start of the next level.
            curLevelStart = curLevelStart->left;
        }

        return root;
    }
};

// DFS (preorder)
void connect(Node* root) {
    if (!root) {
        return;
    }

    if (root->left) {
        root->left->next = root->right;
    }

    if (root->right && root->next) {
        root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);
}
