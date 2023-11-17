class Solution {
public:

    // TC-O(m+n), SC-O(m+n)
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    //     int m = nums1.size(), n = nums2.size();
    //     int i=0,j=0;
    //     vector<int>ans;
        
    //     int mid = (m+n)/2-1;


    //     while(i<m && j<n){
    //         if(nums1[i]<nums2[j]){
    //             ans.push_back(nums1[i]);
    //             i++;
    //         }
    //         else{
    //            ans.push_back(nums2[j]); 
    //            j++;
    //         }
    //     }
    //     while(i<m){
    //         ans.push_back(nums1[i]);
    //         i++;
    //     }
    //     while(j<n){
    //         ans.push_back(nums2[j]);
    //         j++;
    //     }
        
    //     double res;
    //     if(ans.size() % 2 == 0){
    //         res= (double)(ans[mid]+ans[mid+1])/2.0;
    //     }
    //     else{
    //         res=ans[mid+1];
    //     }
    //     return res;
    // }


// // TC-O((m+n)/2), SC-O(1)
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
//         int m = nums1.size(), n = nums2.size();
//         int i=0,j=0;
//         int ist, sec;
        
//         int mid = (m+n)/2;
//         int count = 0;


//         while(i<m && j<n && count <= mid){
            
//             if(nums1[i]<nums2[j]){
//                 if(count == mid-1)  ist = nums1[i];
//                 else if(count == mid)   sec = nums1[i];
//                 i++;
//             }
//             else{
//                if(count == mid-1)  ist = nums2[j];
//                 else if(count == mid)   sec = nums2[j];
//                j++;
//             }
//             count++;
//         }
//         while(i<m and count <= mid){
            
//             if(count == mid-1)  ist = nums1[i];
//             else if(count == mid)   sec = nums1[i];
//             i++;
//             count++;
//         }
//         while(j<n and count <= mid){
            
//             if(count == mid-1)  ist = nums2[j];
//             else if(count == mid)   sec = nums2[j];
//             j++;
//             count++;
//         }
        
        
//         if((m+n) % 2 == 0){
//             return (double)(ist+sec)/2.0;
//         }
//         else{
//             return sec;
//         }

//     }




    // Binary Search
    // TC-O(log (min(m,n))), SC-O(1)

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        // if(n1>n2)	return findMedianSortedArrays(b,a);

        int no_of_elem_before = (n1+n2)/2;
        int lo=max(0, no_of_elem_before-n2), hi = min(n1, no_of_elem_before);


        while(lo<=hi){
            int mid = (lo+hi)/2;
            int rem = no_of_elem_before - mid;

            int l1 = mid>0  ? a[mid-1] : INT_MIN;
            int r1 = mid<n1 ? a[mid] : INT_MAX;
            int l2 = rem > 0 ? b[rem - 1] : INT_MIN; 
            int r2 = rem < n2 ? b[rem] : INT_MAX; 
            
            if(l1 > r2 )		hi = mid-1;
            else if(l2 > r1)	lo = mid+1;
            else{
                if((n1+n2)%2 == 0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else	return min(r1,r2);
            }
        }
        
        return -1;
    }



   
};
