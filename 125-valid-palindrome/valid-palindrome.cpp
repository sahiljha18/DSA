char toLowerCase(char ch){
    if(ch>='a'&& ch<='z'){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}
   bool checkPalindrome(string s) {
        int st = 0;
        int e = s.length() - 1;

        while (st < e) {
            if (!isalnum(s[st])) {
                st++;
            }
            else if (!isalnum(s[e])) {
                e--;
            }
            else {
                if (toLowerCase(s[st]) != toLowerCase(s[e])) {
                    return false;
                }
                st++;
                e--;
            }
        }
        return true;
    }
class Solution {
public:

    bool isPalindrome(string s) {
       return checkPalindrome(s);
    }
};