class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n*(n+1)/2;
        int currentSum = 0;

        for(int i=0; i<n;i++){
            currentSum +=nums[i];

        }
            return (expectedSum - currentSum);
        
    }
};

/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x= n;

        for(int i=0; i<n;i++){
            x = x ^ i ^ nums[i];

        }
            return x;
        
    }
};*/