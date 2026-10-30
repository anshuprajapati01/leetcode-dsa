class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        // Build LPS array
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Search needle in haystack
        i = 0;
        int j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;
            }
            else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return -1;
    }
};