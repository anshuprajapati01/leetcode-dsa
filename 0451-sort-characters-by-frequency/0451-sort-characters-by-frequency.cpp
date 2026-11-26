
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Store characters and their frequencies
        vector<pair<char, int>> v(freq.begin(), freq.end());

        // Sort in decreasing order of frequency
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Build the answer
        string ans = "";

        for (auto &p : v) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};
