// Problem: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

#define BIG 1000000007

class Solution
{
public:

    int numWays(int steps, int arrLen)
    {
        this->arrLen = arrLen;
        this->mem    = vector<vector<int>> (steps+1, vector<int>(251, -1));
        return dp(steps, 0);
    }

    vector<vector<int>> mem;
    int arrLen;

    int dp(int steps, int idx)
    {
        if (steps == 0)
        {
            if (idx == 0) return 1;
            else          return 0;
        }

        if (steps < idx) return 0;

        if (mem[steps][idx] != -1)
        {
            return mem[steps][idx];
        }

        int result = dp(steps-1, idx);
        if (idx > 0) result = (result + dp(steps-1, idx-1)) % BIG;
        if (idx < arrLen-1) result = (result + dp(steps-1, idx+1)) % BIG;

        return mem[steps][idx] = result;
    }
};
