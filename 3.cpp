// Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        //unordered_map<char, int> lastOccurence;
        vector<int> lastOccurence(256, -1); // Vector is fast :)

        int best = 0;
        int start = 0;
        int i = 0;
        while (i < s.length())
        {
            //if (lastOccurence.find(s[i]) == lastOccurence.end())
            if (lastOccurence[s[i]] == -1)  // Vector is fast :)
            {
                lastOccurence[s[i]] = i;
            }
            else
            {
                if (lastOccurence[s[i]] >= start)
                {
                    best = max(best, i - start);
                    start = lastOccurence[s[i]] + 1;
                }
                lastOccurence[s[i]] = i;
            }
            i += 1;
        }

        return max(best, i - start);
    }
};
