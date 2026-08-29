/*class Solution {
public:
    int countPrimes(int n) {
       vector<bool> v(n,true);

       int ans =0;
       for(int i=2;i<n;i++){
        if(v[i] == true){
            ans++;

            for(int j=2*i; j<n;j+=i){
                v[j]=false;
            }
        }
       }
       return ans;
        
    }
};*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<char> isPrime(n, true);
        
        int count =1; 

        for(int i =3; i * i < n; i += 2) {
            if(isPrime[i]) {
                
                for(int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }
        for(int i = 3; i < n; i += 2) {
            if(isPrime[i]) count++;
        }

        return count;
    }
};