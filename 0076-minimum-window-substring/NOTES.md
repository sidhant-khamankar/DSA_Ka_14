}
// pop from the left of our window
window[s[l]] -= 1;
​
// check if s[l] is present in t's dictionary and if its occurrence is less in s's dictionary
if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]])
{
have -= 1;
}
​
// popped from left
l += 1;
}
}
​
int start = res[0];
int end = res[1];
if (resLen != INT_MAX)
return s.substr(start, end - start + 1);
else
return "";
}
};
// @lc code=end
​
```