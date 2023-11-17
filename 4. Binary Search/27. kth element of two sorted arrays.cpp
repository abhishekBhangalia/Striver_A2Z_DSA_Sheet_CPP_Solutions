#include <bits/stdc++.h>

int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    // Write your code here
    
    // if(n1>n2)	return kthElement(b,a,n1, n2, k);

    int lo=max(0,k-n2), hi = min(n1, k);


    while(lo<=hi){
        int mid = (lo+hi)/2;
        int rem = k - mid;

        int l1 = mid>0  ? a[mid-1] : INT_MIN;
        int r1 = mid<n1 ? a[mid] : INT_MAX;
        int l2 = rem > 0 ? b[rem - 1] : INT_MIN; 
        int r2 = rem < n2 ? b[rem] : INT_MAX; 
        
        if(l1 > r2 )		hi = mid-1;
        else if(l2 > r1)	lo = mid+1;
        else{
            return max(l1,l2);
        }
    }
    
    return -1;
}
