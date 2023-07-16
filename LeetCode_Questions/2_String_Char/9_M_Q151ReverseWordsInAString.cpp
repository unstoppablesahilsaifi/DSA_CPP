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
