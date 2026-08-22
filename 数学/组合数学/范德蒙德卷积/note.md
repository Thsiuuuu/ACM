## **范德蒙德卷积公式**

$$\sum_{i=0}^{k}\binom{n}{i}\binom{m}{k-i}=\binom{n+m}{k}$$

**证明**
$$\sum_{k=0}^{n+m}\binom{n+m}{k}x^k=(x+1)^{n+m}=(x+1)^n(x+1)^m=\sum_{r=0}^{n}\binom{n}{r}x^r\sum_{s=0}^{m}\binom{m}{s}x^s=\sum_{k=0}^{n+m}\sum_{r=0}^{k}\binom{n}{r}\binom{m}{k-r}x^k$$

**组合意义**：一个$n+m$个集合取$k$个数，可认为拆成$n$和$m$两个集合，$n$取$i$个，$m$取$k-i$个。

### **推论**：
#### **推论1**：
$$\sum_{i=-r}^{s}\binom{n}{r+i}\binom{m}{s-i}=\binom{n+m}{r+s}$$

**证明**：
$$\sum_{k=0}^{K} \binom{n}{k} \binom{m}{K-k} = \binom{n+m}{K}$$
**令 $k = r + i$,$K = r + s$,则：**
$$\sum_{k=0}^{K} \binom{n}{k} \binom{m}{K - k} = \binom{n+m}{K} = \binom{n+m}{r+s}$$

#### **推论2**：
$$\sum_{i=1}^{n}\binom{n}{i}\binom{n}{n-1}=\binom{2n}{n-1}$$
**证明**:
$$\sum_{i=1}^{n}\binom{n}{i}\binom{n}{i-1}=\sum_{i=0}^{n-1}\binom{n}{i+1}\binom{n}{i}=\sum_{i=0}^{n-1}\binom{n}{n-1-i}\binom{n}{i}=\binom{2n}{n-1}$$

#### **推论3**:
$$\sum_{i=0}^{n}\binom{n}{i}^{2}=\binom{2n}{n}$$
**证明**:
$$\sum_{i=0}^{n}\binom{n}{i}^{2}=\sum_{i=0}^{n}\binom{n}{i}\binom{n}{n-i}=\binom{2n}{n}$$

#### **推论4**:
$$\sum_{i=0}^{m}\binom{n}{i}\binom{m}{i}=\binom{n+m}{m}$$
**证明**:
$$\sum_{i=0}^{m}\binom{n}{i}\binom{m}{i}=\sum_{i=0}^{m}\binom{n}{i}\binom{m}{m-i}=\binom{n+m}{m}$$