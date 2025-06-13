#include <bits/stdc++.h>
using namespace std;

//brute high TC-O(n!*n) list all permutations then do linear search 
// better use next_permutation(arr.begin(), arr.end())
// best get the longer prefix match a[i]<a[i+1] (see dip from last), find jsut >a[i] but smallest and swap it, try to place all other in sorted order (just rev)
// Tc - O(3n)
class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                ind=i;
                break;
            }
        }

        if(ind==-1){
            reverse(arr.begin(), arr.end());
        }
        else{
            for(int i=n-1;i>=0;i--){
                if(arr[i]>arr[ind]){
                    swap(arr[i],arr[ind]);
                    break;
                }
            }
            reverse(arr.begin()+ind+1,arr.end());
        }
    }
};