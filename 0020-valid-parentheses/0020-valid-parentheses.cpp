#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // Pehle check karo ki stack empty toh nahi hai
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); 
                } else {
                    return false; 
                }
            }
        }

        return st.empty();
    }
};