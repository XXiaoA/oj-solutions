#include <iostream>
#include <string>
using namespace std;

using node = struct LNode *;
using element = char;

struct LNode {
    element date;
    node left;
    node right;
};

inline node insert(element data) {
    node root = new LNode;
    root->left = new LNode;
    root->right = new LNode;
    root->date = data;
    return root;
};

// NOLINTNEXTLINE(misc-no-recursion)
void create(node root, const string &in, string post) {
    if (in.empty())
        return;
    element ch = post.at(post.size() - 1);
    root->date = ch;
    unsigned pos = in.find(ch);
    root->left = new LNode;
    root->right = new LNode;
    create(root->left, in.substr(0, pos), post.substr(0, pos));
    create(root->right, in.substr(pos + 1),
           post.substr(pos, in.size() - pos - 1));
}

// NOLINTNEXTLINE(misc-no-recursion)
void pre_traversal(node root) {
    if (!root || !root->date)
        return;
    cout << root->date;
    pre_traversal(root->left);
    pre_traversal(root->right);
};

int main() {
    int n;
    string inorder, postorder;
    node tree = new LNode;
    cin >> inorder >> postorder;
    create(tree, inorder, postorder);
    // create(tree, "badc", "bdca");
    pre_traversal(tree);

    return 0;
}
