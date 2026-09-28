class Solution {
public:
    bool isPalindrome(string s) {
        int str = 0, end = s.size() - 1;
        while (str < end) {
            while (str < end && !isalnum(s[str])) {
                str++;
            }
            while (str < end && !isalnum(s[end])) {
                end--;
            }
            if (tolower(s[str]) != tolower(s[end])) {
                return false;
            }
            str++;
            end--;
        }
        return true;
    }
};