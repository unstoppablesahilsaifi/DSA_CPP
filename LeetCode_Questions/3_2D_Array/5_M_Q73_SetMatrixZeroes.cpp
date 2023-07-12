class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> x, y;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {

                    // yha s vo nikal liya jaha jaha per zero h mtlb i and j ki value nikal li, i mtlb row yaani x axis m daal diya
                    // j mtlb y axis m daal diya.
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        // row->0
        // yha a row zero krni h wrt to x axis
        for (int i = 0; i < x.size(); i++) {
            int index = x[i];
            for (int j = 0; j < n; j++) {
                matrix[index][j] = 0;
            }
        }

        // col->0
        
        // yha a col zero krni h wrt to y axis
        for (int i = 0; i < y.size(); i++) {
            int index = y[i];
            for (int j = 0; j < m; j++) {  // Fixed the loop condition here
                matrix[j][index] = 0;
            }
        }
    }
};
