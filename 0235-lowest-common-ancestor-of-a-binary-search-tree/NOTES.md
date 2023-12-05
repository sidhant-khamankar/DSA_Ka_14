# Code library gfg solution bst efficient Oheight time
​
```
// Code library gfg solution bst efficient Oheight time On space
/* Function to find LCA of n1 and n2.
The function assumes that both
n1 and n2 are present in BST */
node *lca(node *root, int n1, int n2)
{
if (root == NULL)
return NULL;
​
// If both n1 and n2 are smaller
// than root, then LCA lies in left
if (root->data > n1 && root->data > n2)
return lca(root->left, n1, n2);
​
// If both n1 and n2 are greater than
// root, then LCA lies in right
if (root->data < n1 && root->data < n2)
return lca(root->right, n1, n2);
​
return root;
}
​
/* Function to find LCA of n1 and n2.
The function assumes that both n1 and n2
are present in BST */
struct node *lca(struct node *root, int n1, int n2)
{
while (root != NULL)
{
// If both n1 and n2 are smaller than root,
// then LCA lies in left
if (root->data > n1 && root->data > n2)
root = root->left;
​
// If both n1 and n2 are greater than root,
// then LCA lies in right
else if (root->data < n1 && root->data < n2)
root = root->right;
​
else
break;
}
return root;
}
```
​
# Code library solution On time binary tree
​
```
/*
* @lc app=leetcode id=235 lang=cpp
*
* [235] Lowest Common Ancestor of a Binary Search Tree
*/