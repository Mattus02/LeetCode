// Problem: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
// The trick to this question is realizing that it does not matter if ants reverse when meeting or not.

impl Solution {
    pub fn get_last_moment(n: i32, left: Vec<i32>, right: Vec<i32>) -> i32 {
        let mut biggest: i32 = 0;
        for pos in left {
            biggest = std::cmp::max(biggest, pos);
        }
        for pos in right {
            biggest = std::cmp::max(biggest, n - pos)
        }
        return biggest;
    }
}