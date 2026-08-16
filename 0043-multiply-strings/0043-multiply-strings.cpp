class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 =="0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n = num1.length();
        int m = num2.length();

        vector<int>v(n+m,0);

        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                v[i+j]+=(num1[i]-'0')*(num2[j] - '0');

            }
        }
        //  reverse(v.begin(), v.end());
         for(int i=0;i<n+m-1;i++){
            v[i+1]+=v[i]/10;
            v[i]%=10;

         }
         int edge = n+m-1;
         while(edge >= 0 && v[edge] == 0){
            edge--;
         }

         string ans = "";
         for(int i =edge;i>=0;i--){
            ans += to_string(v[i]);
         }
         return ans;
        
    }
};