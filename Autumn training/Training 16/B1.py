import numpy as np
n=input()
data=input()
num=list(map(int,data.split()))
sum=np.float128(0)
for x in num:
    sum=(sum/2)+np.float128(x)
    if sum<0:
        print("-",end="")
    elif sum>0:
        print("+",end="")
    else:
        print("0",end="")
