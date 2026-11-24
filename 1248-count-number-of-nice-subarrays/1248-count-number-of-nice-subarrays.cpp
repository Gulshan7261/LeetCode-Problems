class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> countMap;
        countMap[0] = 1;
        int prefixOdd = 0;
        int ans = 0;

        for(int num: nums){
            if(num % 2 != 0){
                prefixOdd++;
            }
            if(countMap.find(prefixOdd - k) != countMap.end()){
                ans += countMap[prefixOdd - k];
            }
            countMap[prefixOdd] ++;
        }
        return ans;
        
    }
};