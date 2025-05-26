#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low>=high) return;
        int pivotind=partition(arr,low,high);
        quickSort(arr,low,pivotind-1);
        quickSort(arr,pivotind+1,high);
        
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int idx=low-1; int pivot=arr[high];
        for(int i=low;i<high;i++){
            if(arr[i]<=pivot){
                idx++;
                swap(arr[idx],arr[i]);
            }
        }
        idx++;
        swap(arr[idx],arr[high]);
        return idx;
    }
};