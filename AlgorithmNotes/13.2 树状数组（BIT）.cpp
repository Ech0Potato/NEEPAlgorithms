/**
* 树状数组（BIT）
**/

//lowbit运算：lowbit(x)=x&(-x)

//树状数组：一个记录和的数组，存放的是在i号位之前（含i号位）lowbit(i)个整数之和
//树状数组经典应用：统计序列中在元素左边比该元素小的元素个数
#include <cstdio>
#include <cstring>
const int maxn = 100010;
#define lowbit(i) ((i)&(-i)) //lowbit写成宏定义的形式，注意括号

int c[maxn]; //树状数组

//将第x个整数加上v
void update(int x, int v) {
    //i<maxn或者i<=n都可以
    for (int i = x; i < maxn; i += lowbit(i))
        c[i] += v; //让c[i]加上v，然后让c[i+lowbit(i)]加上v
}

//返回前x个整数之和
int getSum(int x) {
    int sum = 0; //记录和
    //注意是i>0而不是i>=0
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i]; //累计c[i]，然后把问题缩小为SUM(1,i-lowbit(i))
    return sum; //返回和
}

int main() {
    int n, x;
    scanf("%d", &n);
    memset(c, 0, sizeof(c)); //树状数组初值为0
    for (int i = 0; i < n; i++) {
        scanf("%d", &x); //输入序列元素
        update(x, 1); //x的出现次数加1
        printf("%d\n", getSum(x - 1)); //查询当前小于x的个数
    }
    return 0;
}

//离散化
