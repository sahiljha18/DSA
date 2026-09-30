class Solution {
public:

    void fun(int n, int open, int close, string s, vector<string>& ans) {

      if(s.length()==2*n){
        ans.push_back(s);
        return;
      }
  

       
        if (open < n) {
            fun(n, open + 1, close, s + '(', ans);
        }

       
        if (close < open) {
            fun(n, open, close + 1, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        fun(n, 0, 0, "", ans);

        return ans;
    }
};