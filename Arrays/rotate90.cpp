#include <bits/stdc++.h>
using namespace std;

// Brute force- we will use extra matric to store arr[j][n-i-1]=matrix[i][j]
// optimise space 
// take transpose and reverse every row nearly O(n^2/2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
