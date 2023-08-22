# Striver Solution
same as leetcode solution
# Leetcode Solution
```
public class Solution {
public int maxProfit(int prices[]) {
int minprice = Integer.MAX_VALUE;
int maxprofit = 0;
for (int i = 0; i < prices.length; i++) {
if (prices[i] < minprice)
minprice = prices[i];
else if (prices[i] - minprice > maxprofit)
maxprofit = prices[i] - minprice;
}
return maxprofit;
}
}
```
# Did not get
Brute On^2 time O1 space