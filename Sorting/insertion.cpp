#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int j=i+1;
            while(j>0 && arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                j--;
            }
        }
        
    }
};
