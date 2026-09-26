class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        return (s+s).contains(goal);
        
    }
};

/*class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.length(), m = goal.length();
        for(int i=0;i<n;i++){
            s = s.substr(1,n-1) + s.substr(0,1);

            if(s == goal) return true;
        }
        return false;
        
    }
};*/