### **第二类斯特林数**
第二类斯特林数$\left\{ \begin{matrix}
    n\\m
\end{matrix}\right\}$,也可以记做$S(n,k)$，表示将$n$个两两不同的元素，划分为$k$个互不区分的非空子集的方案数。

#### 递推式
$\begin{Bmatrix}
    n\\k
\end{Bmatrix}$=$\begin{Bmatrix}
    n-1\\k-1
\end{Bmatrix}$+$k\begin{Bmatrix}
    n-1\\k    
\end{Bmatrix}$

边界是$\begin{Bmatrix}
    n\\0
\end{Bmatrix}=[n=0]$
**组合意义证明**：
插入最后一个元素，有两种方案：
* 将新元素单独放入一个子集,有$\begin{Bmatrix}
    n-1\\k-1
\end{Bmatrix}$中方案
* 将新元素放入一个现有的非空子集，有$k\begin{Bmatrix}
    n-1\\k
\end{Bmatrix}$中方案。
根据加法原理，两式相加即可得到递推式
#### 通项公式
$$\begin{Bmatrix}
    n\\m
\end{Bmatrix}=\sum_{i=0}^m\frac{(-1)^{m-i}i^n}{i!(m-i)!}$$
**证明**：
设将$n$个两两不同的元素,划分到$i$个两两不同的集合(允许空集)的方案数为$G_i$,将$𝑛$个两两不同的元素,划分到$
i$个两两不同的非空集合(不允许空集)的方案数为$F_i$．
显然
$$G_i=i^n\\G_i=\sum_{j=0}^i\binom{i}{j}F_j$$
根据二项式反演
$$F_i=\sum_{j=0}^i(-1)^{i-j}\binom{i}{j}G_j\\=\sum_{j=0}^i(-1)^{i-j}\binom{i}{j}j^n\\=\sum_{j=0}^i\frac{i!(-1)^{i-j}j^n}{j!(i-j)!}$$
考虑$F_i$与$\begin{Bmatrix}
    n\\m
\end{Bmatrix}$的关系，第二类斯特林数要求集合之间互不区分，因此$F_i$正好就是$\begin{Bmatrix}
    n\\i
\end{Bmatrix}$的$i!$倍，于是$$\begin{Bmatrix}
    n\\m
\end{Bmatrix}=\frac{F_m}{m!}=\sum_{i=0}^m\frac{(-1)^{m-i}i^n}{i!(m-i)!}$$