#include <iostream>
#include <vector>

using namespace std;

// Standard node for Path Copying
struct Node {
    long long sum;
    Node *left, *right;
    
    Node(long long val) : sum(val), left(nullptr), right(nullptr) {}
    Node(Node *l, Node *r) : left(l), right(r) {
        sum = (l ? l->sum : 0) + (r ? r->sum : 0);
    }
};

// Build the initial version 0 segment tree
Node* build(const vector<int>& a, int tl, int tr) {
    if (tl == tr) return new Node(a[tl]);
    int tm = tl + (tr - tl) / 2;
    return new Node(build(a, tl, tm), build(a, tm + 1, tr));
}

// O(log N) point update, returns new root
Node* update(Node* node, int tl, int tr, int pos, int new_val) {
    if (tl == tr) return new Node(new_val);
    int tm = tl + (tr - tl) / 2;
    
    if (pos <= tm)
        return new Node(update(node->left, tl, tm, pos, new_val), node->right);
    else
        return new Node(node->left, update(node->right, tm + 1, tr, pos, new_val));
}

// O(log N) range sum query
long long query(Node* node, int tl, int tr, int l, int r) {
    if (l > r || !node) return 0;
    if (l == tl && r == tr) return node->sum;
    int tm = tl + (tr - tl) / 2;
    
    return query(node->left, tl, tm, l, min(r, tm)) + 
           query(node->right, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    // Basic test to prove persistence
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    
    vector<Node*> versions;
    
    // Version 0: [1, 2, 3, 4, 5]
    versions.push_back(build(arr, 0, n - 1));
    
    // Version 1: Update index 2 from '3' to '10' -> [1, 2, 10, 4, 5]
    versions.push_back(update(versions[0], 0, n - 1, 2, 10));
    
    // Version 2: Update index 4 from '5' to '1' -> [1, 2, 10, 4, 1]
    versions.push_back(update(versions[1], 0, n - 1, 4, 1));
    
    cout << "--- Path Copying Tests ---\n";
    cout << "V0 Sum [0..4]: " << query(versions[0], 0, n - 1, 0, 4) << " (Expected: 15)\n";
    cout << "V1 Sum [0..4]: " << query(versions[1], 0, n - 1, 0, 4) << " (Expected: 22)\n";
    cout << "V2 Sum [0..4]: " << query(versions[2], 0, n - 1, 0, 4) << " (Expected: 18)\n";
    
    return 0;
}