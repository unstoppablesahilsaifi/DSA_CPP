#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
      // character do daal kr check krenge ki repeat ho rha ya nhi
        unordered_set<char> seen;
        int maxLen = 0;

        while (right < s.length()) {
            char c = s[right];
            if (seen.insert(c).second) {
// ek point per l and r 0th index per honge to 0-0+1=1, to window size=1         
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                while (s[left] != c) {
                    seen.erase(s[left]);
                    left++;
                }
                seen.erase(c);
                left++;
            }
        }

        return maxLen;
    }
};
