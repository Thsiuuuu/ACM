import sys
dt=list(map(int,sys.stdin.read().split()))
a,b,c,d=dt
p=a/b
q=c/d
ans=a/b/(1-(b-a)/b*(d-c)/d)
print("%.10f"% ans)