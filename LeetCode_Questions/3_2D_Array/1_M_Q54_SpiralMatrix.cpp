#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        
        
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int total = row*col;
        
        //index initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        
        
        while(count < total) {
            
            //print starting row
           /*
           Ab niche vale loop m 1,2,3 print krna h, jisme start hoga startingcol s kyuki col ++ hoga  tabhi to 1,2,3 hoga ok
           end hoga loop jab jhaa tak col end hoga mtlb ending col thik h
           ab print kaise krna h ??    kya kya print hoga ?? samjh ye aaya ki pehli row print honi and while doing col++ ok
           pehli row mtlb starting Row and col++ end tak  jayga mtlb ending col ok
           ab jo in dono m row h use pehle daal do baaki baad m, row h hmari starting row that's why matrix[startingRow][index]
           */

            for(int index = startingCol; count < total && index<=endingCol; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            
            //print ending column
            for(int index = startingRow; count < total && index<=endingRow; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            
            //print ending row
            for(int index = endingCol; count < total && index>=startingCol; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            
            //print starting column
            for(int index = endingRow; count < total && index>=startingRow; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        } 
        return ans;
    }
};