### **二项式推论**

#### **对称性**
$$\binom{n}{m}=\binom{n}{n-m} \tag{1}$$

#### **递推式**
$$\binom{n}{k}=\frac{n}{k}\binom{n-1}{k-1}\tag{2}$$
\
$$\binom{n}{m}=\binom{n-1}{m}+\binom{n-1}{m-1}\tag{3}$$

#### **二项式定理特殊情况**
$$\binom{n}{0}+\binom{n}{1}+\cdots+\binom{n}{n}=\sum_{i=0}^{n}\binom{n}{i}=2^n\tag{4}$$

对二项式定理取$a=b=1$得到上式

$$\sum_{i=0}^{n}(-1)^i\binom{n}{i}=[n=0] \tag{5}$$
对二项式定理取$a=1,b=-1$得到上式

$$\sum_{i=0}^k\binom{n}{i}\binom{m}{k-i}=\binom{m+n}{k}\tag{6}$$
范德蒙德卷积

$$\sum_{i=0}^n\binom{n}{i}^2=\binom{2n}{n}
\tag{7}$$

$(6)$的特殊情况，取$n=k=m$即可

$$\sum_{i=0}^ni\binom{n}{i}=n2^{n-1}\tag{8}$$
对$(4)$对应的多项式函数求导得出

$$\sum_{i=0}^ni^2\binom{n}{i}=n(n+1)2^{n-2}\tag{9}$$
与$(8)$类似，用多项式求导证明

$$\sum_{i=0}^n\binom{l}{k}=\binom{n+1}{k+1}\tag{10}$$

朱世杰恒等式,恒等式证明中较常用，考虑$S=\{a_1,a_2,\cdots,a_{n+1}\}$的$k+1$子集数可以得证

$$\binom{n}{r}\binom{r}{k}=\binom{n}{k}\binom{n-k}{r-k}\tag{11}$$
\
$$\sum_{i=0}^n\binom{n-i}{i}=F_{n+1}\tag{12}$$
其中$F$是斐波那契数列

$$\binom{n+k}{k}^2=\sum_{j=0}^k\binom{k}{j}^2\binom{n+2k-j}{2k}\tag{13}$$
李善兰恒等式，通过$(6)$可证

### **二项式反演**

$$g(n)=\sum_{i=0}^n(-1)^i\binom{n}{i}f(i)\iff f(n)=\sum_{i=0}^n(-1)^i\binom{n}{i}g(i)\tag{1}$$
$$g(n)=\sum_{i=0}^n\binom{n}{i}f(i)\iff f(n)=\sum_{i=0}^n(-1)^{n-i}\binom{n}{i}g(i)\tag{2}$$
$$g(n)=\sum_{i=n}^N(-1)^i\binom{i}{n}f(i)\iff f(n)=\sum_{i=n}^N(-1)^i\binom{i}{n}g(i)\tag{3}$$
$$g(n)=\sum_{i=n}^N\binom{i}{n}f(i)\iff f(n)=\sum_{i=n}^N(-1)^{i-n}\binom{i}{n}g(i)\tag{4}$$

其中，
$(1),(2)$中$g(i),f(i)$分别表示**至多有$i$个元素**满足条件的方案数和**恰好有$i$个元素**满足条件的方案数
$(3),(4)$中$g(i),f(i)$分别表示**至少有$i$个元素**满足条件的方案数和**恰好有$i$个元素**满足条件的方案数