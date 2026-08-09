class Solution {
public:
    string addBinary(string a, string b) {
        // append 0s to the smallar value -no difit in both beaome the same
        if(a.length() > b.length()){
            //add leading 0s to b
            int numLeading0s = a.length() - b.length();
            for(int i=0; i<numLeading0s;i++) b ='0' + b;
        }

        else if(a.length() < b.length()){
                //add leading 0s to a
            int numLeading0s = b.length() - a.length();
            for(int i=0; i<numLeading0s;i++) a='0' + a;
        }
            string sum = "";
            int carry = 0;

            for(int i=a.length()-1; i>=0;i--){
                int digit1 = a[i] - '0';
                int digit2 = b[i] - '0';
                int d=0;

                // 4cases
                //  case 1 :- 0+0
                if(digit1==0 && digit2 == 0){
                    // 0+0+0
                    if(carry == 0){
                        d= 0;
                        carry = 0;
                    }
                    // 0+0+1
                    else{
                        d = 1;
                        carry = 0;
                    }

                }
                // 0+1
                  if(digit1 == 0 && digit2 == 1){
                    // 0+1+0
                    if(carry == 0){
                        d= 1;
                        carry = 0;
                    }
                    // 0+1+1
                    else{
                        d = 0;
                        carry = 1;
                    }

                }

                // 1+0
                 if(digit1==1 && digit2 == 0){
                    // 1+0+0
                    if(carry == 0){
                        d= 1;
                        carry = 0;
                    }
                    // 1+1+0
                    else{
                        d = 0;
                        carry = 1;
                    }

                }

                // 1+1
                 if(digit1==1 && digit2 == 1){
                    // 1+1+0
                    if(carry == 0){
                        d= 0;
                        carry = 1;
                    }
                    // 1+1+1
                    else{
                        d = 1;
                        carry = 1;
                    }

                }

                // add digit to sum
                sum = (char)('0'+ d) + sum;
            }

            if(carry==1) sum = '1'+sum;
             return sum ;
    }
        
};