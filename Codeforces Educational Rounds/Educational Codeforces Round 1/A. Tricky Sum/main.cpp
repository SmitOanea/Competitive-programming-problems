#include <bits/stdc++.h>

using namespace std;

int n,T;

long long Solution1(int n)
{
    long long s;
    int num;
    s=(1LL*n*(n+1))/2;
    num=1;
    for(num=1;num<=n;num*=2)
        s=s-2*num;///it's multiplied by two, because I have to substract this value two times
    return s;
}

long long Solution2(int n)
{
    /**
        It seems that:
        2^0 + 2^1 + 2^2 + ... + 2^k = (2^(k+1))-1, for any k(natural number)
        where ^ is exponentiation, not xor.
        I've learned this reading alex_bucevschi's solution.
        Solution1 is also fine and more obvious.
    */
    long long s,dif;
    s = (1LL*n*(n+1))/2;
    //dif = 2^0 + 2^1 + 2^2 + ... + 2^log2(n) = (2^(log2(n)+1))-1
    dif = (1LL << ( (long long)log2(n)+1) )  -  1;
    s-=2*dif;
    return s;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen ("date.in","r",stdin);
        freopen ("date.out","w",stdout);
    #endif
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<Solution2(n)<<"\n";
    }
    return 0;
}
