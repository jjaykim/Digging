// https://leetcode.com/problems/reverse-integer/

#include <iostream>
#include <limits.h>

class Solution {
public:
  int reverse(int x) {
    long result = 0;

    while (x != 0) {
      result = result * 10 + x % 10;
      x = x / 10;
    }

    if (result > INT_MAX || result < INT_MIN) result = 0;
    // INT_MAX and INT_MIN are included in <limits.h>

    return result;
  }
};