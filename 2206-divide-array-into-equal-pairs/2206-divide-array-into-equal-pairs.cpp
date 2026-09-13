class Solution {
public:
        bool divideArray(std::vector<int>& nums) {
        std::unordered_set<int> st;

        for(int num : nums){
            if (st.count(num)) {
                st.erase(num);
            }
            else{
                st.insert(num);
            }
        }
        return st.empty();
        
    }
};