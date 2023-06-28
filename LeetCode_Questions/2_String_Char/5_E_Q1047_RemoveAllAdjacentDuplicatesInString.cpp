/*
Approach
Create a empty string temp

make a pointer i=0

iterate till (i<length of string )

if either the string is empty or the char is not equal to the last char at temp
push the current character.

else
pop the last character of the temp string.
i++
return temp.
*/

class Solution {
public:
    string removeDuplicates(string s) {
        string temp = "";
        int i = 0;
        
        while (i < s.length()) {
            if (temp.empty() || s[i] != temp.back()) {
                temp.push_back(s[i]);
            } else {
                temp.pop_back();
            }
            i++;
        }
        
        return temp;
    }
};