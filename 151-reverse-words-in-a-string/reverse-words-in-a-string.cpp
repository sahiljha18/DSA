
class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        string temp = "";

        // Extract words
        for (int i = 0; i < s.length(); i++) {

            if (s[i] != ' ') {
                temp += s[i];
            }
            else {
                if (temp != "") {
                    words.push_back(temp);
                    temp = "";
                }
            }
        }

        // Push the last word
        if (temp != "") {
            words.push_back(temp);
        }

        // Reverse the words
        reverse(words.begin(), words.end());
   
        // Build the answer
        string ans = "";

        for (int i = 0; i < words.size(); i++) {

            ans += words[i];

            if (i != words.size() - 1) {
                ans += " ";
            }
        }

        return ans;
    }
};
