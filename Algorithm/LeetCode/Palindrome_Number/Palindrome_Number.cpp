//  https://leetcode.com/problems/palindrome-number/

class Solution {
public:
  bool isPalindrome(int x) {
    long _first = x;
    long _check = 0;

    if (x < 0)
      return false;

    while (x != 0) {
      _check = _check * 10 + x % 10;
      x = x / 10;
    }

    return _first == _check;
  }
};