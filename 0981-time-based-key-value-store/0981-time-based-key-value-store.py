# My solution 
# Olog(timestamps)
from collections import defaultdict
class TimeMap:
    

    def __init__(self):
        self.ds = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.ds[key].append({timestamp: value})
        

    def get(self, key: str, timestamp: int) -> str:
        
        
        if len(self.ds[key]) == 0 or timestamp < list(self.ds[key][0].keys())[0]:
            return ""
        

        l = 0
        h = len(self.ds[key]) - 1
        
        mid = None
        while l<=h:
            mid = (l+h)//2
            # print(type(self.ds[key][mid].keys()))
            if list(self.ds[key][mid].keys())[0] == timestamp:
                return list(self.ds[key][mid].values())[0]
            elif list(self.ds[key][mid].keys())[0] < timestamp:
                l = mid + 1
            else:
                h = mid - 1
        
        if list(self.ds[key][mid].keys())[0] > timestamp:
            mid -= 1
        return list(self.ds[key][mid].values())[0]
            
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)