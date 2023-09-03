class Solution {
public:
    bool checkIfPangram(string s) {
         // Create an array to store the count of each letter
    int letterCount[26] = {0};

    // Iterate through the input string
    for (char c : s) {
        // Convert the character to lowercase (if it's an uppercase letter)
        if (isupper(c)) {
            c = tolower(c);
        }

        // Check if the character is a lowercase letter
        if (islower(c)) {
            // Increment the count for the corresponding letter
            letterCount[c - 'a']++;
        }
    }

    // Check if all letters have been encountered at least once
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] == 0) {
            return false;
        }
    }

    return true;
    }
};

/*
Certainly! In the code snippet `letterCount[c - 'a']++;`, `letterCount` is an array that is used to count the occurrences of each letter in the alphabet. Here's an explanation of each part of this line of code:

1. `c`: This variable represents the current character being processed in the input string. We are iterating through the input string character by character.

2. `'a'`: This is a character literal representing the lowercase letter 'a'. In ASCII encoding, characters are represented as integer values, and the character 'a' has a value of 97. So, `'a' - 'a'` equals 0 because we are subtracting the ASCII value of 'a' from itself, which results in zero.

3. `c - 'a'`: This expression calculates the relative position of the character `c` in the alphabet. For example, if `c` is 'b', then `c - 'a'` would be 1 because 'b' is the second letter in the alphabet (0-based indexing).

4. `letterCount[c - 'a']++`: This line of code uses the result of `c - 'a'` as an index to access the corresponding element in the `letterCount` array and increments its value by 1. In other words, it's counting how many times each letter appears in the input string.

So, as you iterate through the input string, this line of code increments the count of the specific letter encountered, allowing you to keep track of the occurrences of each letter in the alphabet.
*/