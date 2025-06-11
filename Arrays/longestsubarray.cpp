#include <bits/stdc++.h>
using namespace std;

// Brute O(3) select subarray using two loops, then sun check if equal and update maxi.
// O(2) if keep s=0  just above second loop and update s+=arr[j] then check

//best using hashing if it has negative and positive TC- O(nlogn) if ordered map used ow O(n) in case of unordered map
//Use a prefix sum and hash map to track where the sum started and find the longest subarray that ends at current index and sums to k.
//then subract the index from sum-prefixsum to get the max length and update
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        int maxl=0,sum=0;
        map<long long,int> mpp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxl=max(maxl,i+1);
            }
            long long rem=sum-k;
            if(mpp.find(rem)!=mpp.end()){
                int x=i-mpp[rem];
                maxl=max(maxl,x);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return maxl;
    }
};

//best if array has pos and zeros using two pointer both moving worst TC-O(2n)
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size();

    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}
