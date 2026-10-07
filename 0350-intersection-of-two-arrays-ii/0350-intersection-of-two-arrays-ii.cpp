class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> np;

        for(int num : nums1){
            np[num]++;
        }
        vector<int>result;
        for(int i = 0; i<nums2.size();i++){
            int num = nums2[i];

            if(np[num] > 0){
                np[num]--;
                result.push_back(num);
            }
        }
        return result;
    }
};