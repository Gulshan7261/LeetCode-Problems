class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle explicit 32-bit signed integer overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == divisor) return 1;

        // Determine the sign of the final quotient
        bool sign = true;
        if (dividend >= 0 && divisor < 0) sign = false;
        else if (dividend <= 0 && divisor > 0) sign = false;

        // Use long to prevent intermediate overflow steps
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long quotient = 0;

        // Bit-shifting loop to calculate quotient efficiently
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quotient += (1L << cnt); // Use 1L literal to ensure safe bit-shifts
            n -= (d << cnt);
        }

        // Apply final sign to result
        return sign ? quotient : -quotient;
    }
};