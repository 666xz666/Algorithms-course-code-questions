// //有趣的素数

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    /*
    判断单个数是否为素数
    时间复杂度O(√n)

    如果m个数要判断，总的时间复杂度就是O(m√n)
    */
    if (n == 1)
        return false;
    if (n == 2)
        return true;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int n;

unordered_set<int> st;   // 用来记录2n以内的素数
std::vector<bool> prime; // 布尔数组，初始假设所有数都是素数
void generatePrimeSet(int n)
{
    /*
    生成n以内的所有素数，最常用的高效算法是埃拉托斯特尼筛法（Sieve of Eratosthenes），其时间复杂度是
    O(n log n)。这个算法的基本思想是：
        创建一个从2到n的连续整数列表，开始时假设所有数都是素数。
        从列表中的第一个素数2开始，将其所有倍数（除了它自身）标记为非素数。
        然后找到列表中下一个未被标记的数，这个数是下一个素数，重复上一步。
        继续这个过程，直到你处理完所有小于等于√n的素数。
    */
    prime.clear();
    prime = std::vector<bool>(n + 1, true);
    prime[0] = prime[1] = false; // 0和1不是素数

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        { // 如果p是素数
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false; // 标记p的所有倍数为非素数
            }
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            st.insert(p); // 将素数添加到结果数组
        }
    }
}

bool isPrime1(int n)
{
    return prime[n]; // 直接查表 O(1)
}

void backTracking(vector<int> &v, int &sum, int i = 2)
{
    if (i == n)
    {
        if (isPrime1(v[i] + v[i - 1]) && isPrime1(v[i] + v[1]))
            sum++;
        return;
    }

    for (int j = i; j <= n; j++)
    {
        swap(v[i], v[j]);

        if (isPrime1(v[i] + v[i - 1]))
            backTracking(v, sum, i + 1);

        swap(v[i], v[j]);
    }
}

void work()
{

    while (cin >> n)
    {
        generatePrimeSet(2 * n);

        vector<int> v(n + 5);
        for (int i = 1; i <= n; i++)
            v[i] = i;

        // 接下来要固定1，对剩下的进行排列
        int sum = 0;
        backTracking(v, sum);

        cout << sum << endl;
    }
}

int main()
{
    work();
    return 0;
}