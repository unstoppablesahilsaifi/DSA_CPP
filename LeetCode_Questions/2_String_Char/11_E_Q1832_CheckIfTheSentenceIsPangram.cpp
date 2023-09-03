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