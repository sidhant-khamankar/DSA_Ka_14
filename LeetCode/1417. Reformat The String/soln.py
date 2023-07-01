class Solution:
    def reformat(self, s: str) -> str:
        a=list()
        n=list()
        for c in s:
            if c.isalpha():
                a.append(c)
            else:
                n.append(c)
        ans=""
        if (len(a)==len(n)-1) or (len(n)==len(a)-1) or (len(a)==len(n)):
            if len(a)>len(n):
                last=a[-1]
                a.pop()
                l=list(zip(a,n))
                for al, num in l:
                    ans=str(al)+str(num)+ans
                return ans+str(last)
            elif len(n)>len(a):
                last=n[-1]
                n.pop()
                l=list(zip(a,n))
                for al, num in l:
                    ans=str(num)+str(al)+ans
                return ans+str(last)
            else:
                l=list(zip(a,n))
                for al, num in l:
                    ans=str(num)+str(al)+ans
                return ans
        else:
            return ""
                
                
                
        