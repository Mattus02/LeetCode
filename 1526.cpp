// Problem: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

class Solution
{
public:
    int minNumberOperations(vector<int>& target)
    {
        int h = target.front();
        int count = 0;
        for (int i = 1; i < target.size(); ++i)
        {
            if (h > target[i])
            {
                count += h - target[i];
            }
            h = target[i];
        }
        return count + h;
    }
};
