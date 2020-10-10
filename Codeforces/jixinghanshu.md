前置技能
积性函数的定义
若$$f(n)$$的定义域为正整数域，值域为复数，即<script type="math/tex" id="MathJax-Element-2">f:\mathbb{Z}^+\to\mathbb{C}</script>，则称<script type="math/tex" id="MathJax-Element-3">f(n)</script>为数论函数。
若<script type="math/tex" id="MathJax-Element-4">f(n)</script>为数论函数，且<script type="math/tex" id="MathJax-Element-5">f(1)=1</script>，对于互质的正整数<script type="math/tex" id="MathJax-Element-6">p,q</script>有<script type="math/tex" id="MathJax-Element-7">f(p\cdot q)=f(p)\cdot f(q)</script>，则称其为积性函数。
若<script type="math/tex" id="MathJax-Element-8">f(n)</script>为积性函数，且对于任意正整数<script type="math/tex" id="MathJax-Element-9">p,q</script>都有<script type="math/tex" id="MathJax-Element-10">f(p\cdot q)=f(p)\cdot f(q)</script>，则称其为完全积性函数。
积性函数的性质与例子
常见的积性函数有
除数函数<script type="math/tex" id="MathJax-Element-11">\sigma_k(n)=\sum_{d|n}{d^k}</script>，表示<script type="math/tex" id="MathJax-Element-12">n</script>的约数的<script type="math/tex" id="MathJax-Element-13">k</script>次幂和，注意<script type="math/tex" id="MathJax-Element-14">\sigma_k(n)</script>与<script type="math/tex" id="MathJax-Element-15">\sigma^k(n)</script>是不同的。
约数个数函数<script type="math/tex" id="MathJax-Element-16">\tau(n)=\sigma_0(n)=\sum_{d|n}{1}</script>，表示<script type="math/tex" id="MathJax-Element-17">n</script>的约数个数，一般也写为<script type="math/tex" id="MathJax-Element-18">d(n)</script>。
约数和函数<script type="math/tex" id="MathJax-Element-19">\sigma(n)=\sigma_1(n)=\sum_{d|n}{d}</script>，表示<script type="math/tex" id="MathJax-Element-20">n</script>的约数之和。
欧拉函数<script type="math/tex" id="MathJax-Element-21">\varphi(n)=\sum_{i=1}^{n}{[(n,i)=1]\cdot 1}</script>，表示不大于<script type="math/tex" id="MathJax-Element-22">n</script>且与<script type="math/tex" id="MathJax-Element-23">n</script>互质的正整数个数，另外<script type="math/tex" id="MathJax-Element-24">\sum_{i=1}^{n}{[(n,i)=1]\cdot i}=\frac{n\cdot\varphi(n)+[n=1]}{2}</script>，且对于正整数<script type="math/tex" id="MathJax-Element-25">n>2</script>来说<script type="math/tex" id="MathJax-Element-26">\varphi(n)</script>是偶数。
莫比乌斯函数<script type="math/tex" id="MathJax-Element-27">\mu(n)</script>，在狄利克雷卷积的乘法中与恒等函数互为逆元，<script type="math/tex" id="MathJax-Element-28">\mu(1)=1</script>，对于无平方因子数<script type="math/tex" id="MathJax-Element-29">n=\prod_{i=1}^{t}p_i</script>有<script type="math/tex" id="MathJax-Element-30">\mu(n)=(-1)^t</script>，对于有平方因子数<script type="math/tex" id="MathJax-Element-31">n</script>有<script type="math/tex" id="MathJax-Element-32">\mu(n)=0</script>。
元函数<script type="math/tex" id="MathJax-Element-33">e(n)=[n=1]</script>，狄利克雷卷积的乘法单位元，完全积性。
恒等函数<script type="math/tex" id="MathJax-Element-34">I(n)=1</script>，完全积性。
单位函数<script type="math/tex" id="MathJax-Element-35">id(n)=n</script>，完全积性。
幂函数<script type="math/tex" id="MathJax-Element-36">id^k(n)=n^k</script>，完全积性。
关于莫比乌斯函数和欧拉函数有两个经典的公式
<script type="math/tex" id="MathJax-Element-37">[n=1]=\sum_{d|n}{\mu(d)}</script>，将<script type="math/tex" id="MathJax-Element-38">\mu(d)</script>看作是容斥的系数即可证明。
<script type="math/tex" id="MathJax-Element-39">n=\sum_{d|n}{\varphi(d)}</script>，将<script type="math/tex" id="MathJax-Element-40">\frac{i}{n}(1\le i\le n)</script>化为最简分数统计个数即可证明。
若<script type="math/tex" id="MathJax-Element-41">f(n)</script>为积性函数，则对于正整数<script type="math/tex" id="MathJax-Element-42">n=\prod_{i=1}^{t}{p_i^{k_i}}</script>有<script type="math/tex" id="MathJax-Element-43">f(n)=\prod_{i=1}^{t}{f(p_i^{k_i})}</script>；若<script type="math/tex" id="MathJax-Element-44">f(n)</script>为完全积性函数，则对于正整数<script type="math/tex" id="MathJax-Element-45">n=\prod_{i=1}^{t}{p_i^{k_i}}</script>有<script type="math/tex" id="MathJax-Element-46">f(n)=\prod_{i=1}^{t}{f(p_i)^{k_i}}</script>。
狄利克雷卷积与莫比乌斯反演
数论函数<script type="math/tex" id="MathJax-Element-47">f</script>和<script type="math/tex" id="MathJax-Element-48">g</script>狄利克雷卷积定义为<script type="math/tex" id="MathJax-Element-49">(f*g)(n)=\sum_{d|n}{f(d)\cdot g(\frac{n}{d})}</script>，狄利克雷卷积满足交换律、结合律，对加法满足分配律，存在单位元函数<script type="math/tex" id="MathJax-Element-50">e(n)=[n=1]</script>使得<script type="math/tex" id="MathJax-Element-51">f*e=f=e*f</script>，若<script type="math/tex" id="MathJax-Element-52">f</script>和<script type="math/tex" id="MathJax-Element-53">g</script>为积性函数则<script type="math/tex" id="MathJax-Element-54">f*g</script>也为积性函数。
狄利克雷卷积的一个常用技巧是对于积性函数<script type="math/tex" id="MathJax-Element-55">f</script>与恒等函数<script type="math/tex" id="MathJax-Element-56">I</script>的卷积的处理，例如<script type="math/tex" id="MathJax-Element-57">n=\prod_{i=1}^{t}{p_i^{k_i}},g(n)=\sum_{d|n}{f(d)}</script>，则有<script type="math/tex" id="MathJax-Element-58">g(n)=\prod_{i=1}^{t}\sum_{j=0}^{k_i}{f(p_i^j)}</script>。
莫比乌斯反演也是对于<script type="math/tex" id="MathJax-Element-59">g(n)=\sum_{d|n}{f(d)}</script>的讨论，但是不要求<script type="math/tex" id="MathJax-Element-60">f</script>是积性函数，适用于已知<script type="math/tex" id="MathJax-Element-61">g(n)</script>求<script type="math/tex" id="MathJax-Element-62">f(n)</script>的情况，由于<script type="math/tex" id="MathJax-Element-63">I*\mu= e</script>，则<script type="math/tex" id="MathJax-Element-64">g*\mu=f*I*\mu=f*e=f</script>，即<script type="math/tex" id="MathJax-Element-65">f(n)=\sum_{d|n}{g(d)\cdot\mu(\frac{n}{d})}</script>，类似地有<script type="math/tex" id="MathJax-Element-66">g(n)=\sum_{n|d}{f(d)}\Rightarrow f(n)=\sum_{n|d}{g(d)\cdot\mu(\frac{d}{n})}</script>，二项式反演也是类似的技巧。有一个例子可以看出欧拉函数和莫比乌斯函数之间的关系，由于<script type="math/tex" id="MathJax-Element-67">\sum_{d|n}{\varphi(d)}=id(n)</script>，所以<script type="math/tex" id="MathJax-Element-68">\varphi(n)=\sum_{d|n}{\mu(d)\frac{n}{d}}</script>，也即<script type="math/tex" id="MathJax-Element-69">\frac{\varphi(n)}{n}=\sum_{d|n}{\frac{\mu(d)}{d}}</script>。
正文：黑科技
这种黑科技大概起源于Project Euler这个网站，由xudyh引入中国的OI、ACM界，目前出现了一些OI模拟题、OJ月赛题、ACM赛题是需要这种技巧在低于线性时间的复杂度下解决一类积性函数的前缀和问题。

首先看一个简单的例子，求前<script type="math/tex" id="MathJax-Element-70">n</script>个正整数的约数之和，即<script type="math/tex" id="MathJax-Element-71">\sum_{i=1}^{n}{\sigma(i)}</script>，其中<script type="math/tex" id="MathJax-Element-72">n\le 10^{12}</script>。
显然不能直接做了，但是我们可以推导一番：
<script type="math/tex; mode=display" id="MathJax-Element-73">\sum_{i=1}^{n}{\sigma(i)}=\sum_{i=1}^{n}{\sum_{j=1}^{n}{[j|i]\cdot j}}=\sum_{i=1}^{n}{i\cdot\sum_{j=1}^{n}{[i|j]}}=\sum_{i=1}^{n}{i\cdot\lfloor\frac{n}{i}\rfloor}</script>
当 <script type="math/tex" id="MathJax-Element-74">i\le\sqrt{n}</script>时， <script type="math/tex" id="MathJax-Element-75">\lfloor\frac{n}{i}\rfloor</script>显然只有 <script type="math/tex" id="MathJax-Element-76">O(\sqrt{n})</script>个取值；当 <script type="math/tex" id="MathJax-Element-77">i>\sqrt{n}</script>时， <script type="math/tex" id="MathJax-Element-78">\lfloor\frac{n}{i}\rfloor<\sqrt{n}</script>显然也只有 <script type="math/tex" id="MathJax-Element-79">O(\sqrt{n})</script>个取值；对于固定的 <script type="math/tex" id="MathJax-Element-80">\lfloor\frac{n}{i}\rfloor</script>， <script type="math/tex" id="MathJax-Element-81">i</script>的取值是一段连续的区间，这段区间是 <script type="math/tex" id="MathJax-Element-82">[\left\lfloor\frac{n}{\left\lfloor\frac{n}{i}\right\rfloor+1}\right\rfloor+1,\left\lfloor\frac{n}{\left\lfloor\frac{n}{i}\right\rfloor}\right\rfloor]</script>，因此可以 <script type="math/tex" id="MathJax-Element-83">O(\sqrt{n})</script>计算所求。
同样地，求前 <script type="math/tex" id="MathJax-Element-84">n</script>个正整数的约数个数之和也可以这样计算，留给读者练习。
另外需要说明的是， <script type="math/tex" id="MathJax-Element-85">\sum_{i=1}^{n}{\lfloor\frac{n}{i}\rfloor\cdot i}=\sum_{i=1}^{n}{\frac{\lfloor\frac{n}{i}\rfloor\cdot (\lfloor\frac{n}{i}\rfloor+1)}{2}}</script>，这也是一种常见的表示形式。
现在我们来加大一点难度，求前<script type="math/tex" id="MathJax-Element-86">n</script>个正整数的欧拉函数之和，即<script type="math/tex" id="MathJax-Element-87">\sum_{i=1}^{n}{\varphi(i)}</script>，其中<script type="math/tex" id="MathJax-Element-88">n\le 10^{11}</script>。
目前本文提到的有关欧拉函数的公式只有几个，是否能用它们来帮助化简呢？答案是肯定的，接下来我们就利用<script type="math/tex" id="MathJax-Element-89">\sum_{d|n}{\varphi(d)}=n</script>来化简这个式子。
这个公式也可以看成是<script type="math/tex" id="MathJax-Element-90">\varphi(n)=n-\sum_{d|n,d <script type="math/tex" id="MathJax-Element-91">\phi(n)=\sum_{i=1}^{n}{\varphi(i)}</script>，则有
<script type="math/tex; mode=display" id="MathJax-Element-92">\phi(n)=\sum_{i=1}^{n}{\varphi(i)}=\sum_{i=1}^{n}{i-\sum_{d|i,d 那么只要计算出 <script type="math/tex" id="MathJax-Element-93">O(\sqrt{n})</script>个 <script type="math/tex" id="MathJax-Element-94">\phi(\lfloor\frac{n}{i}\rfloor)</script>的值，就可以计算出 <script type="math/tex" id="MathJax-Element-95">\phi(n)</script>，这样的复杂度又如何呢？
假设计算出 <script type="math/tex" id="MathJax-Element-96">\phi(n)</script>的复杂度为 <script type="math/tex" id="MathJax-Element-97">T(n)</script>，则有 <script type="math/tex" id="MathJax-Element-98">T(n)=O(\sqrt{n})+\sum_{i=1}^{\sqrt{n}}{T(i)+T(\frac{n}{i})}</script>， 这里只展开一层就可以了，更深层的复杂度是高阶小量，所以有 <script type="math/tex" id="MathJax-Element-99">T(n)=\sum_{i=1}^{\sqrt{n}}{O(\sqrt{i})+O(\sqrt{\frac{n}{i}})}=O(n^\frac{3}{4})</script>。
由于 <script type="math/tex" id="MathJax-Element-100">\phi(n)</script>是一个积性函数的前缀和，所以筛法也可以预处理一部分，假设预处理了前 <script type="math/tex" id="MathJax-Element-101">k</script>个正整数的 <script type="math/tex" id="MathJax-Element-102">\phi(n)</script>，且 <script type="math/tex" id="MathJax-Element-103">k\ge\sqrt{n}</script>，则复杂度变为 <script type="math/tex" id="MathJax-Element-104">T(n)=\sum_{i=1}^{\frac{n}{k}}{\sqrt{\frac{n}{i}}}=O(\frac{n}{\sqrt{k}})</script>，当 <script type="math/tex" id="MathJax-Element-105">k=O(n^\frac{2}{3})</script>时可以取到较好的复杂度 <script type="math/tex" id="MathJax-Element-106">T(n)=O(n^\frac{2}{3})</script>。
之前利用 <script type="math/tex" id="MathJax-Element-107">\varphi(n)=n-\sum_{d|n,d
<script type="math/tex; mode=display" id="MathJax-Element-108">\frac{n\cdot(n+1)}{2}=\sum_{i=1}^{n}{i}=\sum_{i=1}^{n}\sum_{d}{[d|i]\cdot\varphi(d)}=\sum_{\frac{i}{d}=1}^{n}\sum_{d=1}^{\left\lfloor\frac{n}{\frac{i}{d}}\right\rfloor}{\varphi(d)}=\sum_{i=1}^{n}{\phi(\lfloor\frac{n}{i}\rfloor)}</script>
如果能通过狄利克雷卷积构造一个更好计算前缀和的函数，且用于卷积的另一个函数也易计算，则可以简化计算过程。例如上题就是利用了 <script type="math/tex" id="MathJax-Element-109">\varphi*I=id</script>的性质，但一定注意，不是所有的这一类题都只用配个恒等函数 <script type="math/tex" id="MathJax-Element-110">I</script>就可以轻松完事的，有时需要更细致的观察。
定义梅滕斯函数<script type="math/tex" id="MathJax-Element-111">M(n)=\sum_{i=1}^{n}{\mu(i)}</script>，给定正整数<script type="math/tex" id="MathJax-Element-112">n</script>，计算<script type="math/tex" id="MathJax-Element-113">M(n)</script>，其中<script type="math/tex" id="MathJax-Element-114">n\le10^{11}</script>。
有了欧拉函数的经验，这次似乎就轻车熟路了吧，使用<script type="math/tex" id="MathJax-Element-115">[n=1]=\sum_{d|n}{\mu(d)}</script>来试试？
<script type="math/tex; mode=display" id="MathJax-Element-116">1=\sum_{i=1}^{n}{[i=1]}=\sum_{i=1}^{n}\sum_{d|i}{\mu(d)}=\sum_{i=1}^{n}\sum_{d=1}^{\lfloor\frac{n}{i}\rfloor}{\mu(d)}=\sum_{i=1}^{n}{M(\lfloor\frac{n}{i}\rfloor)}</script>
因此 <script type="math/tex" id="MathJax-Element-117">M(n)=1-\sum_{i=2}^{n}{M(\lfloor\frac{n}{i}\rfloor)}</script>，问题可在 <script type="math/tex" id="MathJax-Element-118">O(n^\frac{2}{3})</script>时间复杂度下解决。
看了上面的例子，是不是认为这种做法很naive，很好学啊，再来看一个题吧！
令<script type="math/tex" id="MathJax-Element-119">A(n)=\sum_{i=1}^{n}{\frac{i}{(n,i)}},F(n)=\sum_{i=1}^{n}{A(i)}</script>，求<script type="math/tex" id="MathJax-Element-120">F(n)</script>模<script type="math/tex" id="MathJax-Element-121">(10^9+7)</script>的值，其中<script type="math/tex" id="MathJax-Element-122">n\le 10^9</script>。
先做一番化简，变成积性函数前缀和的样子：
<script type="math/tex; mode=display" id="MathJax-Element-123">A(n)=\sum_{i=1}^{n}{\frac{i}{(n,i)}}=\sum_{i=1}^{n}\sum_{d|n}{[(n,i)=d]\cdot\frac{i}{d}}=\sum_{d|n}\sum_{\frac{i}{d}=1}^{\frac{n}{d}}{[(\frac{n}{d},\frac{i}{d})=1]\cdot\frac{i}{d}}=\frac{1}{2}(1+\sum_{d|n}{d\cdot\varphi(d)})</script>
设 <script type="math/tex" id="MathJax-Element-124">G(n)=2\cdot F(n)-n</script>，则
<script type="math/tex; mode=display" id="MathJax-Element-125">G(n)=2\cdot F(n)-n=\sum_{i=1}^{n}\sum_{d|i}{d\cdot\varphi(d)}=\sum_{i=1}^{n}\sum_{d=1}^{\lfloor\frac{n}{i}\rfloor}{d\cdot\varphi(d)}</script>
因此要求的是 <script type="math/tex" id="MathJax-Element-126">\phi'(n)=\sum_{i=1}^{n}{i\cdot\varphi(i)}</script>。
而对于 <script type="math/tex" id="MathJax-Element-127">n=\prod_{i=1}^{t}{p_i^{k_i}}</script>，有
<script type="math/tex; mode=display" id="MathJax-Element-128">\sum_{d|n}{d\cdot\varphi(d)}=\prod_{i=1}^{t}\sum_{j=0}^{k_i}{p_i^j\cdot\varphi(p_i^j)}=\prod_{i=1}^{t}\frac{p_i^{2k_i+1}+1}{p_i+1}</script>这并不是什么好算前缀和的函数。
但是不难发现 <script type="math/tex" id="MathJax-Element-129">(id\cdot\varphi)*id=id^2</script>，即
<script type="math/tex; mode=display" id="MathJax-Element-130">\sum_{d|n}{d\cdot\varphi(d)\cdot\frac{n}{d}}=n\cdot\sum_{d|n}{\varphi(d)}=n^2</script>，这是一个很好计算前缀和的函数，于是有
<script type="math/tex; mode=display" id="MathJax-Element-131">\frac{n\cdot(n+1)\cdot(2n+1)}{6}=\sum_{i=1}^{n}{i^2}=\sum_{i=1}^{n}{\sum_{d|i}{d\cdot\varphi(d)\cdot\frac{i}{d}}}=\sum_{\frac{i}{d}=1}^{n}{\frac{i}{d}\cdot\sum_{d=1}^{\left\lfloor\frac{n}{\frac{i}{d}}\right\rfloor}{d\cdot\varphi(d)}}=\sum_{i=1}^{n}{i\cdot\phi'(\lfloor\frac{n}{i}\rfloor)}</script>
因此 <script type="math/tex" id="MathJax-Element-132">\phi'(n)=\frac{n\cdot(n+1)\cdot(2n+1)}{6}-\sum_{i=2}^{n}{i\cdot\phi'(\lfloor\frac{n}{i}\rfloor)}</script>，原问题可在预处理前 <script type="math/tex" id="MathJax-Element-133">O(n^\frac{2}{3})</script>个值的基础上，在 <script type="math/tex" id="MathJax-Element-134">O(n^\frac{2}{3}\log n)</script>的时间复杂度下解决。
但是注意到这种方法的常数与复杂度都可能较高，有时候可能再进行一些推导可以得到一个不使用正文方法的做法，例如ZOJ 3881 - From the ABC conjecture，本文的方法与网上一个解法类似，可以用于求解此题，但是可以这样推导之后得到更简单的一个做法。

需要使用此种方法的题目一般数据规模较大，例如<script type="math/tex" id="MathJax-Element-135">n\le 10^9,n\le 10^{11},n\le 10^{12}</script>，但是并不是都要使用此类方法，有时候可能存在其他<script type="math/tex" id="MathJax-Element-136">O(\sqrt{n}),O(n^\frac{2}{3})</script>的做法，例如51Nod 1222 - 最小公倍数计数，会利用正文复杂度分析的方法即可，再例如ZOJ 5340 - The Sum of Unitary Totient，笔者不是很懂这题是否有其他做法能过，例如<script type="math/tex" id="MathJax-Element-137">O(\frac{n^\frac{3}{4}}{\log n})</script>的积性函数求和方法（会在不久后更新），可能会因为数据组数较多而超时，网上的一个解法是分段压缩打表，具体问题需要具体分析。

推荐题目
这里给出一些练手的题目供大家理解上述方法，这类题还是较少的，如有其他题的题源欢迎分享。
51Nod 1244 - 莫比乌斯函数之和
51Nod 1239 - 欧拉函数之和
BZOJ 3944 - Sum
HDU 5608 - function
51Nod 1238 - 最小公倍数之和 V3
51Nod 1237 - 最大公约数之和 V3
51Nod 1227 - 平均最小公倍数
Tsinsen A1231 - Crash的数字表格
SPOJ DIVCNT2 - Counting Divisors (square)
51Nod 1222 - 最小公倍数计数（复杂度分析）
BZOJ 4176 - Lucas的数论
51Nod 1220 - 约数之和
51Nod 1584 - 加权约数和
ZOJ 3881 - From the ABC conjecture（不需要使用正文方法）
BZOJ 3512 - DZY Loves Math IV
ZOJ 5340 - The Sum of Unitary Totient（常规积性函数求和，数据组数较多，只可分段打表）
SPOJ DIVCNT3 - Counting Divisors (cube)（常规积性函数求和，注意代码长度限制，不可打表）
51Nod 1575 - Gcd and Lcm（常规积性函数求和，可分段打表）
51Nod 1847 - 奇怪的数学题（非常规积性函数求和，综合题，可分段打表）
Tips: 加粗内容为待更新内容。
