// Problem: https://leetcode.com/problems/longest-palindromic-substring/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string answer = "";
        answer += s[0];

        for (int i = 0; i < s.length()-1; ++i)
        {
            if (i > 0 && s[i-1] == s[i+1])
            {
                TrySubstring(i, i, s, answer);
            }
            if (s[i] == s[i+1])
            {
                TrySubstring(i, i+1, s, answer);
            }
        }

        return answer;
    }

    void TrySubstring(int l, int r, string& s, string& answer)
    {
        while (l > 0 && r < s.length()-1 && s[l-1] == s[r+1])
        {
            l -= 1;
            r += 1;
        }

        if (r+1 - l > answer.length())
        {
            answer = s.substr(l, r+1 - l);
        }
    }
};
