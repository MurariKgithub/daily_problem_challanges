from os import *
from sys import *
from collections import *
from math import *

def nestedRangesCheck(ranges, n):
    res1 = [0]*n
    res2 = [0]*n
    # print(list(enumerate(ranges)))
    ranges = [[elem,i] for i,elem in enumerate(ranges)]
    ranges.sort()
    # print(ranges)
    for i in range(len(ranges)):
        s,e = ranges[i][0][0],ranges[i][0][1]
        for j in range(i+1,len(ranges)):
            ns,ne = ranges[j][0][0],ranges[j][0][1]
            indx1,indx2 = ranges[i][1],ranges[j][1]
            if(s<=ns and e>=ne):
                res1[indx1]=1
                res2[indx2]=1
            if(ns<=s and ne>=e):
                res1[indx2] =1
                res2[indx1]=1

    res = [res1,res2]
    return res
