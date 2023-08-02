/*

A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input. 

Basic methods are:

clear()- To clear the stream.
str()- To get and set string object whose content is present in the stream. 
operator <<- Add a string to the stringstream object. 
operator >>- Read something from the stringstream object.



GFG Link:   https://www.geeksforgeeks.org/stringstream-c-applications/
*/


class Solution {
public:
    string reverseWords(string str) {
        //Used for breaking the words, word seprate krdega ye function
        stringstream s(str);
        // To store individual words
        string word;

        // to store words.
        vector<string>temp;
        // to store the ans.
        string ans="";

        while(s>>word)// works like a cin one operator
        {
            temp.push_back(word);
        }
        //now store the words in reverse order and add the extra space at the end of eaach word. except the first one.

        for(int i=temp.size()-1;i>=0;i--){
            if(i!=0)
            ans+=temp[i]+" ";
            else
                ans+=temp[i];

        }
        return ans;
    }
};


----------------------
    Explaining Reversed  loop

    for (int i = temp.size() - 1; i >= 0; i--) {
    if (i != 0)
        ans += temp[i] + " ";
    else
        ans += temp[i];
}

1.for (int i = temp.size() - 1; i >= 0; i--) { ... }: This loop iterates through the temp vector, starting from the last element (temp.size() - 1) and going down to the first element (0).

2.if (i != 0): This condition checks whether the current iteration is not the last element of the vector.

3. ans += temp[i] + " ";: If the current iteration is not the last element, this line adds the current word temp[i] to the ans string, followed by a space " ".
   This space is used to separate words in the reversed string.

4. else: If the current iteration is the last element of the vector (i.e., the first word), this block of code executes.

5. ans += temp[i];: In this case, it adds only the current word temp[i] to the ans string without appending a space at the end.
    This is to avoid adding an extra space after the last word in the reversed string.

The purpose of this loop is to reverse the order of words from the temp vector and construct the ans string by concatenating the reversed words with spaces between them. The loop takes care to not add an extra space after the last word, ensuring the correct formatting of the reversed string.

In summary, this loop plays a crucial role in reversing the words and formatting the final reversed string that is returned by the reverseWords function.
