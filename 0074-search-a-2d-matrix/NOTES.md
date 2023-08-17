# Striver Solution
GFG different question row and columns are sorted
* Naive On*m time O1 space Linear traversal in entire matrix
* Binary search for each row On*logm time
* Better
For GFG put pointer at last element of first row and elements before it in row will be lesser and elements in column below it will be greater, accordingly move pointer
when pointer moves out of bound then not found
* Optimal Olog(n*m) time O1 space Imaginary Index
Can use extra space to get whole sorted array
Else give indexes in matrix, for any index we can get row and column as
Row = index/no.of Columns
Column = index % no.of Columns
Accordingly do binary search
```
class Solution
{
public:
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
// Striver Solution Olog(n*m) time O1 space
if (!matrix.size())
return false;
int n = matrix.size();
int m = matrix[0].size();
​
int lo = 0;
int hi = (n * m) - 1;
​
while (lo <= hi)
{
int mid = (lo + (hi - lo)) / 2;
if (matrix[mid / m][mid % m] == target)
{
return true;
}
if (matrix[mid / m][mid % m] < target)
lo = mid + 1;
else
hi = mid - 1;