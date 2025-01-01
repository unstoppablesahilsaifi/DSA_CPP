
/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //Map will help us to store the count of the no.
        //thier is no sorting needed so we will go with unordered_map
        unordered_map<int,int> m;
        for(auto val:arr){
            m[val]++;  // storing the element in map
        }
        //Set will help us to store the unique no. thus we will store the count of elements from map in this
        unordered_set<int> s;
        for(auto val:m){
            s.insert(val.second); // storing the count in setm
        }
//Then in the last we will look for the sizes of both map and set , if their sizes are equal then it means every count is unique else it always be false
        if(m.size() == s.size()){ // checking if the size are same or not
            return true;
        }

        return false; //return false if condition is wrong
    }
};



/*
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Sort the array to group identical elements together
        sort(arr.begin(), arr.end());
        
        // Step 2: Count the occurrences of each unique element
        vector<int> counts; // To store the counts of each element
        int n = arr.size();
        int count = 1; // Start counting from the first element

        for (int i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1]) {
                count++; // Increment count if the current element matches the previous one
            } else {
                counts.push_back(count); // Store the count for the previous element
                count = 1;              // Reset count for the new element
            }
        }
        counts.push_back(count); // Add the count for the last element

        // Step 3: Check if all counts are unique
        sort(counts.begin(), counts.end()); // Sort the counts
        for (int i = 1; i < counts.size(); ++i) {
            if (counts[i] == counts[i - 1]) {
                return false; // Found duplicate counts, return false
            }
        }

        return true; // All counts are unique, return true
    }
};

*/