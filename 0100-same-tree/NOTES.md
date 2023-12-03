# Leetcode solution
​
```
/**
* Definition for a binary tree node.
* public class TreeNode {
*     int val;
*     TreeNode left;
*     TreeNode right;
*     TreeNode(int x) { val = x; }
* }
*/
class Solution {
public boolean isSameTree(TreeNode p, TreeNode q) {
// p and q are both null
if (p == null && q == null) return true;
// one of p and q is null
if (q == null || p == null) return false;
if (p.val != q.val) return false;
return isSameTree(p.right, q.right) &&
isSameTree(p.left, q.left);
}
}
```
* Like my solution
​
```
class Solution {
public boolean check(TreeNode p, TreeNode q) {
// p and q are null
if (p == null && q == null) return true;
// one of p and q is null
if (q == null || p == null) return false;
if (p.val != q.val) return false;
return true;
}
​
public boolean isSameTree(TreeNode p, TreeNode q) {
if (p == null && q == null) return true;
if (!check(p, q)) return false;
​
// init deques