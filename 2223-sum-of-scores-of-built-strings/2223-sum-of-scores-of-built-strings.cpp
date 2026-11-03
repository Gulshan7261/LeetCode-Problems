#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    long long sumScores(std::string s) {
        int n = s.length();
        std::vector<int> z(n, 0);
        
        // Z-Algorithm implementation
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) {
                z[i] = std::min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        
        // Sum of all LCP lengths
        long long total_score = n; 
        for (int i = 1; i < n; ++i) {
            total_score += z[i];
        }
        
        return total_score;
    }
};