class Solution {
public:
    int superPow(int a, std::vector<int>& b) {
        const int MOD = 1337;
        if(a == 1) return 1;
        const int phi = 1140;

        int exponent = 0;

        for(int digit : b) {
            exponent = (exponent * 10 + digit) % phi;
        }
        if(exponent == 0){
            exponent = phi;
        }

        // compute a ^ exponent mod MOD
        int result = 1;
        a % MOD;
        long long base = a;

        while(exponent > 0) {
            if(exponent % 2 == 1){
                result = (result * base) % MOD;
            }
           base = (base * base) % MOD;
            exponent /=2;
        }
        return result;
        
    }
};