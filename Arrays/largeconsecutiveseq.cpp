#include <bits/stdc++.h>
using namespace std;

//Naive soln using two loops and iterate for x+1, update cnt, then update largest.

//better just sort the array then seach for seq If check arr[i]-1 == lastSmaller, if If arr[i] == lastSmaller then skip for duplicate
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}


//best solution O(3n) Sc- O(n) for solving
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int l=0;
        unordered_set<int> mp(nums.begin(), nums.end());
        for(int num:mp){
            if(mp.find(num-1)==mp.end()){
                int x=num;
                int cnt=1;
                while(mp.find(x+1)!=mp.end()){
                    x++;
                    cnt++;
                }
                l=max(l,cnt);
            }
        }
        return l;
    }
};