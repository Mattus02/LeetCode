// Problem: https://leetcode.com/problems/add-two-numbers/

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {

    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {

        let v1 = Solution::make_vector(l1);
        let v2 = Solution::make_vector(l2);
        let mut v3: Vec<i32> = Vec::new();
        let mut v1_iter = v1.iter().peekable();
        let mut v2_iter = v2.iter().peekable();
        let mut carry = false;
        loop {
            if v1_iter.peek() == None && v2_iter.peek() == None {
                break;
            }
            let mut sum = if carry { 1 } else { 0 };
            if let Some(val) = v1_iter.next() {
                sum += val;
            }
            if let Some(val) = v2_iter.next() {
                sum += val;
            }
            carry = sum > 9;
            sum = if sum > 9 { sum - 10 } else { sum };
            v3.push(sum);
        }
        if carry {
            v3.push(1);
        }

        let mut l3: Option<Box<ListNode>> = None;
        for elem in v3.iter().rev() {
            let new_node = ListNode {
                val: *elem,
                next: l3,
            };
            l3 = Some(Box::new(new_node));
        }

        return l3;
    }

    fn make_vector(mut list: Option<Box<ListNode>>) -> Vec<i32> {
        let mut result: Vec<i32> = Vec::new();
        while let Some(node) = list {
            result.push((*node).val);
            list = (*node).next;
        }
        return result;
    }
}
