// Sorting approach 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

// Best Approach , two pointer approach

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = (m-1), j = (n-1), k = (m + n - 1);
        while(j >= 0 && i>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
                k--;
            }else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        if(i < 0){
            for(int i=0; i<=j; i++){
                nums1[i] = nums2[i];
            }
        }
    }
};