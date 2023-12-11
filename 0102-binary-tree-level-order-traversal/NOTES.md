vv[lev + 1].push_back(t->right->val);
q.push({t->right, lev + 1});
}
}
​
else
{
vector<int> vl;
if (t->left != NULL)
{
vl.push_back(t->left->val);
q.push({t->left, lev + 1});
}
if (t->right != NULL)
{
vl.push_back(t->right->val);
q.push({t->right, lev + 1});
}
if (vl.size() != 0)
vv.push_back(vl);
}
}
​
return vv;
}
```