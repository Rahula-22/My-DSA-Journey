#include <bits/stdc++.h>
using namespace std;

//brute soln TC-O(n^3)
class Solution {
public:
    void row(vector<vector<int>>& mat,int m,int n,int i){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=0){
                mat[i][j]=-1;
            }
        }
    }

    void col(vector<vector<int>>& mat,int m,int n,int j){
        for(int i=0;i<m;i++){
            if(mat[i][j]!=0){
                mat[i][j]=-1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row(matrix, m, n, i);
                    col(matrix, m, n, j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//better

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//optimal 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col0=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        for(int j=0;j<n;j++){
            if(matrix[0][0]==0){
                matrix[0][j]=0;
            }
        }
        
        for(int i=0;i<m;i++){
            if(col0==0){
                matrix[i][0]=0;
            }
        }

    }
};

