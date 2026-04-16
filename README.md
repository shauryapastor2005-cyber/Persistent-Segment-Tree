# Persistent Segment Tree 🌳⏳

An advanced data structure implementation in C++ that supports fully persistent historical range queries. This project explores, implements, and mathematically analyzes two methods for achieving persistence: the **Path-Copying Method** and **Driscoll’s Node-Copying Method**.

## 🚀 Real-World Applications
Persistence is highly valuable in scenarios requiring efficient access to historical states:
* **Competitive Programming:** Solving complex range queries on 2D planes or historical array states (frequently seen in advanced Codeforces and CSES problem sets).
* **Version Control Systems:** Managing state changes over time without copying full repositories.
* **Computational Geometry:** Planar point location and sweeping line algorithms.

## 📊 Complexity Analysis

| Feature | Path Copying | Driscoll's Node Copying |
| :--- | :--- | :--- |
| **Time per Update** | $O(\log N)$ worst-case | $O(\log N)$ amortized |
| **Space per Update**| $O(\log N)$ worst-case | $O(1)$ amortized |
| **Query Time** | $O(\log N)$ | $O(\log N)$ |
| **Space Strategy** | New nodes for historical paths | History stored in extra node slots |

## 💻 Implementation Snippet (Path-Copying)

The core logic relies on dynamic node allocation. Instead of modifying an existing node during an update, we create a new node. The new node shares the unaffected child's pointer from the previous version, ensuring memory efficiency.

```cpp
struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
    Node(Node *l, Node *r) : left(l), right(r) {
        val = (l ? l->val : 0) + (r ? r->val : 0);
    }
};

// Returns the root of the newly created version
Node* update(Node* prev, int L, int R, int idx, int val) {
    // Base Case: Leaf node
    if (L == R) return new Node(val);
    
    int mid = L + (R - L) / 2;
    
    // Recurse left, share right subtree
    if (idx <= mid)
        return new Node(update(prev->left, L, mid, idx, val), prev->right);
        
    // Recurse right, share left subtree
    else
        return new Node(prev->left, update(prev->right, mid + 1, R, idx, val));
}