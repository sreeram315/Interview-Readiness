// https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/

// O(m+n) -> merge and partition at mid
// below is O(logM)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n2>n1) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n2, t = (n1+n2), tr = t/2, L1, L2, R1, R2, c1, c2; 
        // tr->elements needed in right partition (floor(total/2)), i.e. left will have extra (if any)
        while(l<=r){
            c2 = (l+r)/2; c1 = t-tr-c2; // c1 = n1-(tr-(n2-c2));
            L1 = (c1-1>=0) ? nums1[c1-1] : INT_MIN;
            L2 = (c2-1>=0) ? nums2[c2-1] : INT_MIN;
            R1 = (c1<n1)   ? nums1[c1]   : INT_MAX;
            R2 = (c2<n2)   ? nums2[c2]   : INT_MAX;
            if(L1 > R2)
                l = c2+1;
            else if(L2 > R1)
                r = c2-1;
            else{
                if(t%2 == 1)
                    return (double)max(L1, L2);
                return (double)(max(L1, L2)+min(R1, R2))/2;
            }
        }
        return -1;
    }
};

