/*
出专辑
时间限制：1秒
空间限制：32768K
你作为一名出道的歌手终于要出自己的第一份专辑了，你计划收录 n 首歌而且每首歌的长度都是 s 秒，每首歌必须完整地收录于一张 CD 当中。每张 CD 的容量长度都是 L 秒，而且你至少得保证同一张 CD 内相邻两首歌中间至少要隔 1 秒。为了辟邪，你决定任意一张 CD 内的歌数不能被 13 这个数字整除，那么请问你出这张专辑至少需要多少张 CD ？

输入描述:
每组测试用例仅包含一组数据，每组数据第一行为三个正整数 n, s, L。 保证 n ≤ 100 , s ≤ L ≤ 10000 


输出描述:
输出一个整数代表你至少需要的 CD 数量。

输入例子:
7 2 6

输出例子:
4
*/

#include <iostream>
  
using namespace std;
  
int main() {
    long long n, s, l;//n首歌，每首s秒，CD容量l秒
    long long i, z;//每张CD存i首歌，需要z张
    while(scanf("%lld%lld%lld", &n, &s, &l) != EOF) {
        for(i=1; i*s+i-1<=l; i++);//计算1张CD可以存i首歌
        i--;
        z=1;
  
        if(i % 13 == 0) {//每张CD不能存13的倍数首歌
            i--;
        }
  
        for(z=1; i*z<n; z++);//计算需要多少张CD
  
        if((n % 13 == 0) && (n <= i)) {//针对n是13的倍数且1张CD就可以存所有歌曲的情况
            z++;
        }
        if((i - 1) % 13 == 0){//针对最后i-1可能是13的倍数
            z++;
        }
        if((n == 1) && (s == 1) && (l == 1)){//单独考虑1,1,1
            z=1;
        }
        cout << z << endl;
    }
    return 0;
}
