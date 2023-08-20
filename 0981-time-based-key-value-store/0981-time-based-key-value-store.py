# My solution 
# set 
# O(n calls)
# get
# O(m calls * log(L length of values for a key))
# from collections import defaultdict
# class TimeMap:
    

#     def __init__(self):
#         self.ds = defaultdict(list)

#     def set(self, key: str, value: str, timestamp: int) -> None:
#         self.ds[key].append({timestamp: value})
        

#     def get(self, key: str, timestamp: int) -> str:
        
#         # Edge case when timestamp is small than first timestamp
#         if len(self.ds[key]) == 0 or timestamp < list(self.ds[key][0].keys())[0]:
#             return ""
        

#         l = 0
#         h = len(self.ds[key]) - 1
        
#         mid = None
#         while l<=h:
#             mid = (l+h)//2
#             # print(type(self.ds[key][mid].keys()))
#             if list(self.ds[key][mid].keys())[0] == timestamp:
#                 return list(self.ds[key][mid].values())[0]
#             elif list(self.ds[key][mid].keys())[0] < timestamp:
#                 l = mid + 1
#             else:
#                 h = mid - 1
        
#         # edge case when mid points to higher element than target after binary search
#         if list(self.ds[key][mid].keys())[0] > timestamp:
#             mid -= 1
#         return list(self.ds[key][mid].values())[0]
            
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

# neetcode solution
# Set
# O(n calls)
# get
# O(m calls * log(L length of values for a key))
class TimeMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.keyStore = {}  # key : list of [val, timestamp]

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.keyStore:
            self.keyStore[key] = []
        self.keyStore[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        res, values = "", self.keyStore.get(key, [])
        l, r = 0, len(values) - 1
        while l <= r:
            m = (l + r) // 2
            if values[m][1] <= timestamp:
                res = values[m][0]
                l = m + 1
            else:
                r = m - 1
        return res
