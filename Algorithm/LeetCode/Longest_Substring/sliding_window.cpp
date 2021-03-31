// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// using sliding window algorithm and tow pointer
#include <iostream>
#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
  // using unordered_set
  /*
  int result = 0;
  unordered_set<char> arr;
  int left = 0;
  int right = 0;

  while (left < s.size() && right < s.size()) {
    if (arr.find(s[right]) == arr.end()) {
      arr.insert(s[right]);
      result = max(result, right - left + 1);
      right++;
    }
    else {
      arr.erase(s[left]);
      left++;
    }
  }

  return result;
  */

  if (s.size() == 0) return 0;

  int arr[128] = {0};
  int max = 0, left = 0, right = 0;

  for (int i = 0; i < s.size(); i++) {
    arr[int(s[i])]++;
    right++;

    while (arr[int(s[i])] > 1) {
      arr[int(s[left])]--;
      left++;
      right--;
    }

    if (right > max)
      max = right;
  }

  return max;
}
