#include <bits/stdc++.h>
using namespace std;

//one optimal soln to test how to implement and write clean code
// top->right->bottom->left->top
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,b=m-1,r=n-1,t=0;
        vector<int> ans;
        while(l<=r && t<=b){
            for(int i=l;i<=r;i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            for(int j=t;j<=b;j++){
                ans.push_back(matrix[j][r]);
            }
            r--;
            if(t<=b){
                for(int k=r;k>=l;k--){
                    ans.push_back(matrix[b][k]);
                    } 
                b--;
            }

            if(l<=r){
                for(int x=b;x>=t;x--){
                ans.push_back(matrix[x][l]);
                }
                l++;
            }
        }
        return ans;
    }
};