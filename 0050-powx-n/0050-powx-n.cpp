class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        if(x == -1) return (n % 2 == 0) ? 1.0 : -1.0;

        long long binForm = n;
        long double ans = 1.0;
        long double base = x;

        if(binForm < 0){
            base = 1.0 / base;
            binForm = -binForm;
        }

        while(binForm > 0){
            if(binForm & 1){
                ans *= base;
            }
            base *= base;
            binForm >>= 1;
        }
        return (double)ans;
    }
};