// Problem: https://leetcode.com/problems/remove-letter-to-equalize-frequency/

class Solution
{
public:
    bool equalFrequency(string word)
    {
        vector<int> occurrences(256, 0);
        for (char c : word) occurrences[c] += 1;

        map<int, int> variants;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (occurrences[i] == 0) continue;
            if (occurrences[i] == word.length()) return true;
            variants[occurrences[i]] += 1;
        }

        if (variants.size() == 1 && (*variants.begin()).first == 1) return true;
        if (variants.size() == 2)
        {
            pair<int, int> const& low  = *variants.begin();
            pair<int, int> const& high = *variants.rbegin();
            if (low.first == 1 && low.second == 1) return true;
            if (high.second == 1 && high.first == low.first + 1) return true;
        }

        return false;
    }
};
