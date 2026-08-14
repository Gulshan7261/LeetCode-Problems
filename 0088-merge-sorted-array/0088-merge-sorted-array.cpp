class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // copying all values of nums2 into the vacant space of nums1

        // int index = m;
        // for(int i=0; i<n; i++){
        //     nums1[index++] = nums2[i];
        // }

        // sort num1
        // std::sort(nums1.begin(),nums1.end());  //o(NlogN), n = m+n

        // start filling value into nums1nfrom the rhs

        int index = m+n-1;
        int i = m-1;
        int j = n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[index] = nums1[i];
                i--;
            }
            else {
                nums1[index] = nums2[j];
                j--;
            }
            index--;
        }
        while(i>=0){
            nums1[index] = nums1[i];
            i--;
            index--;
        }

        // if there are value left in nums2
         while(j>=0){
            nums1[index] = nums2[j];
            j--;
            index--;
        }      
    }
};