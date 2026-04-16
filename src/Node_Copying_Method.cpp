#include <iostream>
#include <vector>

using namespace std;

const int MAX_SLOTS = 2; // 'e' in our proof

struct FatNode;

// Represents a modification with a version stamp
struct Slot {
    int version;
    long long new_sum;
    FatNode* new_left;
    FatNode* new_right;
};

struct FatNode {
    int creation_version;
    long long base_sum;
    FatNode *base_left, *base_right;
    vector<Slot> slots;

    FatNode(int ver, long long sum, FatNode* l = nullptr, FatNode* r = nullptr) 
        : creation_version(ver), base_sum(sum), base_left(l), base_right(r) {}

    // Get the state of the node at a specific version
    long long get_sum(int ver) {
        long long current_sum = base_sum;
        for (const auto& slot : slots) {
            if (slot.version <= ver) current_sum = slot.new_sum;
            else break;
        }
        return current_sum;
    }

    FatNode* get_left(int ver) {
        FatNode* curr_left = base_left;
        for (const auto& slot : slots) {
            if (slot.version <= ver) curr_left = slot.new_left;
            else break;
        }
        return curr_left;
    }

    FatNode* get_right(int ver) {
        FatNode* curr_right = base_right;
        for (const auto& slot : slots) {
            if (slot.version <= ver) curr_right = slot.new_right;
            else break;
        }
        return curr_right;
    }

    // Handles Driscoll's Cases: Returns either 'this' or a fresh copy
    FatNode* apply_update(int ver, long long n_sum, FatNode* n_left, FatNode* n_right) {
        // CASE 1: Free slot available (Amortized O(1))
        if (slots.size() < MAX_SLOTS) {
            slots.push_back({ver, n_sum, n_left, n_right});
            return this; 
        } 
        // CASE 2/3: Overflow triggers Node Copy
        else {
            FatNode* fresh = new FatNode(ver, get_sum(ver-1), get_left(ver-1), get_right(ver-1));
            fresh->slots.push_back({ver, n_sum, n_left, n_right});
            return fresh; 
        }
    }
};

int main() {
    cout << "--- Driscoll's Fat Node Mechanism Test ---\n";
    
    // Simulating a node across versions
    FatNode* root = new FatNode(0, 15); // Version 0: sum = 15
    
    // Update 1 (Fits in slot 1)
    FatNode* v1_root = root->apply_update(1, 22, nullptr, nullptr);
    
    // Update 2 (Fits in slot 2)
    FatNode* v2_root = v1_root->apply_update(2, 18, nullptr, nullptr);
    
    // Update 3 (Overflow! Forces copy)
    FatNode* v3_root = v2_root->apply_update(3, 30, nullptr, nullptr);
    
    cout << "V0 Sum: " << root->get_sum(0) << "\n";
    cout << "V1 Sum: " << root->get_sum(1) << "\n";
    cout << "V2 Sum: " << root->get_sum(2) << "\n";
    
    if (root == v2_root) {
        cout << "[Logic Check] V0, V1, and V2 share the same memory location (Space optimized!)\n";
    }
    
    cout << "V3 Sum: " << v3_root->get_sum(3) << "\n";
    if (root != v3_root) {
        cout << "[Logic Check] V3 overflowed slots and created a new node location.\n";
    }

    return 0;
}