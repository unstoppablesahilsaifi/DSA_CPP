#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // Trim the string
        int start = 0;
        int end = s.length() - 1;
        while (start <= end && s[start] == ' ') {
            start++;
        }
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        s = s.substr(start, end - start + 1);

        // Find the last word length
        int lastSpace = s.rfind(' ');
        if (lastSpace == string::npos) {
            return s.length();
        } else {
            return s.length() - lastSpace - 1;
        }
    }
};


/// Explainaton
This code defines a class Solution that contains a member function lengthOfLastWord which takes a string s as an argument and returns an integer.

int start = 0; and int end = s.length() - 1; initialize two variables start and end to keep track of the indices of the string's characters.

The subsequent while loops increment start and decrement end to trim any leading and trailing spaces in the string s.

s = s.substr(start, end - start + 1); extracts a substring from s based on the calculated start and end indices, effectively trimming any leading and trailing spaces.

int lastSpace = s.rfind(' '); finds the index of the last occurrence of a space character in the trimmed string s.

The if statement checks if lastSpace is equal to string::npos, indicating that no space was found. In that case, it means there is only one word in the string, so the function returns the length of the entire string s.

If a space is found, the function returns the length of the trimmed string s minus the index of the last space (lastSpace) minus 1, effectively giving the length of the last word.

This code essentially trims the input string s and calculates the length of the last word in the trimmed string.




------------------
 In C++, string::npos is a static member constant of the std::string class.
It represents a value that is used to indicate the absence or invalid position of a character or substring within a string.


--------------------------------
end - start + 1: This is the length of the substring to be extracted.
It is calculated by subtracting the start index from the end index and adding 1 to include the character at the end index itself.