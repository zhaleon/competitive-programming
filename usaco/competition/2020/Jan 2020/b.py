import sys, itertools
from io import IOBase
import os

file = open("wormsort.in", "r")
sys.stdin = file
input = lambda: sys.stdin.readline().rstrip("\r\n")
# 8/10 test cases ...
len = len
if sys.version_info[0] < 3:
  range = xrange
  filter = itertools.ifilter
  map = itertools.imap

N, M = map(int,input().split())

p = list(map(lambda x: int(x)-1,input().split()))
ed = [(lambda a, b, w: (w, a-1, b-1))(*map(int, input().split())) for _ in range(M)]
ed.sort(reverse=True)

cnt = 0

parent = [0]*N
size = [0]*N

def mst():
  edge = 0
  for i in range(N):
    parent[i] = i;
    size[i] = 0; 

  for i in range(M):
    if union(ed[i][1], ed[i][2]):
      edge += 1
    if edge == N-1:
      return i
  return 0

def find(x):
  if (x == parent[x]):
    return x    
  parent[x] = find(parent[x])
  return parent[x]

def union(a, b):
  a = find(a)
  b = find(b)
  if a == b:
    return False
  if size[a] < size[b]:
    a,b = b,a
  parent[b] = a;
  size[a] += size[b]
  return True

def ok(mid, cur):
  global cnt
  
  if cur == 0:
    for i in range(N):
      parent[i] = i;
      size[i] = 0;

  #any(u(t) for t in ed[:mid])
  for i in range(cur, mid):
    cur = union(ed[i][1], ed[i][2])
    
  for i in range(N):
    if find(i) != find(p[i]):
      return False
  return True
  
lo,hi = 0,M
hi = mst()+1
cur = 0

while lo < hi:
  mid = (lo+hi)//2
  if ok(mid, cur):
    hi = mid
    cur = 0
  else:
    lo = mid+1
    cur = mid
    
fout = open("wormsort.out","w")
fout.write(str(-1 if lo == 0 else ed[lo-1][0]))
fout.write('\n')
