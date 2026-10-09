class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int max = *max_element(arr1.begin(), arr1.end());
        vector<int> freq(max+1, 0);

        for(auto el : arr1) freq[el]++;

        vector<int> ans;
        for(auto el : arr2){
            while(freq[el]--){
                ans.push_back(el);
            }
        }
        for(int el = 0; el  <= max; el++){
            int f = freq[el];
            while(f>0 && f--){
                ans.push_back(el);
            }
        }
        return ans;
        
    }
};