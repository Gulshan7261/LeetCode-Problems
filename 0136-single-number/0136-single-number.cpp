class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int i : nums){
            answer = answer^i;
        }
        return answer;
        
    }
};