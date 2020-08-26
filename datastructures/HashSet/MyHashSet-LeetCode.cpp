#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {};
};

class MyHashSet {
public:
    int n = 1e4 + 1;
    vector<ListNode*> myset;
    /** Initialize your data structure here. */
    MyHashSet() {
      myset = vector<ListNode*> (n);
    }
    
    void add(int key) {
      int idx = key % n;

      if (myset[idx] == nullptr) myset[idx] = new ListNode(key);
      else {
        ListNode* node = myset[idx];
        while (node->next) {
          if (node->next->val == key) return;
          node = node->next;
        }
        node->next = new ListNode(key);
      }
    }
    
    void remove(int key) {
      int idx = key % n;

      if (myset[idx] == nullptr) return;
      ListNode* node = myset[idx];
      if (node->val == key) myset[idx] = node->next;
      while (node->next) {
        if (node->next->val == key) {
          node->next = node->next->next;
          return;
        }
        node = node->next;
      }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
      int idx = key % n;
      if (myset[idx] == nullptr) return false;
      ListNode* node = myset[idx];
      while (node) {
        if (node->val == key) return true;
        node = node->next;
      }

      return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main () {
  MyHashSet* obj = new MyHashSet();
  obj->add(1);
  obj->remove(3);
  bool param_3 = obj->contains(1);
}