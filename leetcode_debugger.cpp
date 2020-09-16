#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumOperations(string s) {
    int n = s.size(), le = 0, ri = n - 1;
    while (le < n && s[le] == 'r')
      le++;
    while (ri > le && s[ri] == 'r')
      ri--;
    if (le == n) {
      return 1;
    }
    if (le == ri) {
      return 0;
    }
    return helper(s.substr(le, ri - le + 1));
  }
  int helper(string s) {
    int n = s.size(), le = 0, ri = n - 1, cntr = 0;
    while (le < n && s[le] == 'y')
      le++;
    while (ri > le && s[ri] == 'y')
      ri--;
    if (le == n)
      return 0;
    if (le == ri) {
      return 1;
    }
    for (int i = le; i <= ri; i++) {
      if (s[i] == 'r') {
        cntr++;
      }
    }
    int ysize = le + (n - ri);
    return min(cntr, ysize + helper(s.substr(le, ri - le + 1)));
  }
};

int main() {
  Solution solution;
  string s = "rrryyyrryyyrr";
  cout << solution.minimumOperations(s) << endl;
}