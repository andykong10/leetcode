// ***
//
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be
// stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the
// same or another computer environment.
//
// Design an algorithm to serialize and deserialize a binary tree.
// There is no restriction on how your serialization/deserialization algorithm should work.
// You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the
// original tree structure.
//
// Example:
//
// You may serialize the following tree:
//
//     1
//    / \
//   2   3
//      / \
//     4   5
//
// as "[1,2,3,null,null,4,5]"
//
// Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to
// follow this format, so please be creative and come up with different approaches yourself.
//
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms
// should be stateless.
//
// ***

// To serialize, preorder traverse the tree, add the value of each node followed by a space to ostringstream&,
// if null node is encountered, simplly add "# " to ostringstream&.
//
// To deserialize, covert string to istringstream (so we can take advantage of "in >> value" is natually separated by
// space), preorder traverse the istringstream& and construct the tree.
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (!root) {
            out << "# ";
            return;
        }

        out << root->val << " ";
        serialize(root->left, out);
        serialize(root->right, out);
    }

    TreeNode* deserialize(istringstream& in) {
        string value;
        in >> value;

        if (value == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));
        root->left = deserialize(in);
        root->right = deserialize(in);

        return root;
    }
};

// BFS. Compare with 102. Binary Tree Level Order Traversal.
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out) {
        queue<TreeNode*> q;
        q.push(root);

        while (not q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (not node) {
                out << "# ";
                continue;
            }
            out << node->val << " ";

            q.push(node->left);
            q.push(node->right);
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string value;
        in >> value;

        if (value == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));

        queue<TreeNode*> q;
        q.push(root);

        while (not q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            in >> value;

            if (value != "#") {
                node->left = new TreeNode(stoi(value));
                q.push(node->left);
            } else {
                node->left = nullptr;
            }

            in >> value;
            if (value != "#") {
                node->right = new TreeNode(stoi(value));
                q.push(node->right);
            } else {
                node->right = nullptr;
            }
        }

        return root;
    }
};
