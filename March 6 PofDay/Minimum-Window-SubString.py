from os import *
from sys import *
from collections import *
from math import *

def minSubstring(str1,str2):
    if(len(str1)<len(str2)):    return -1
    dic = {}
    desirecount=len(str2)
    
    for elem in str2:
        dic[elem] = dic.get(elem,0)+1
    l = 0
    ans =-1
    mathcount=0
    mathdic = {}
    for i in range(len(str1)):
        
        mathdic[str1[i]] =mathdic.get(str1[i],0)+1
        if(mathdic.get(str1[i],0)<=dic.get(str1[i],0)):
            mathcount+=1
            
        while(l<=i and mathcount==desirecount):
            if(ans==-1):
                ans = i-l+1
            else:   ans = min(ans,i-l+1)
            # print(ans,i,l)       
            mathdic[str1[l]] =mathdic.get(str1[l],0)-1      
            if(mathdic.get(str1[l],0)<dic.get(str1[l],0)):
                mathcount-=1
            l+=1
   
    return ans
