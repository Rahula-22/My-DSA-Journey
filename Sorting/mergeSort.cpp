#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void merge(vector<int>& arr, int l,int m, int h) {
        vector<int> temp;
        int left=l, right=m+1;
        while(left<=m && right<=h){
            if(arr[left]<arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=m){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=h){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=0;i<temp.size();i++){
            arr[i+l]=temp[i];
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        int m=(l+r)/2;
        if(l>=r) return;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
};