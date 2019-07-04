#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int T,n,m,k;
int dp[33][33][53];

/**
    O dinamica $$m3k3r4
*/

int Solutie(int n,int m,int k)
{
    //cout<<n<<" "<<m<<" "<<k<<"\n";
    if(k<0 || k>n*m)
        return INF;
    if(k==0 || k==n*m)
        return 0;
    if(dp[n][m][k]!=0)//l-am calculat deja si nu mai calculez inca o data
        return dp[n][m][k];

    int rez=INF;

    ///parcurg cu o linie orizontala de sus in jos
    int i;
    for(i=1;i<=n-i;++i)//nu are rost sa trec de jumate ca repet cazurile
    {
        ///fac o taiere orizontala sub linia i, si asa
        ///impart tableta in doua bucati
        ///vreau sa obtin k patratele. dar aceste k patratele nu
        ///trebuie sa fie neaparat in aceeasi bucata(din cele doua obtinute)
        ///pot fi p patratele in bucata de sus si k-p in cea de jos
        int p;
        for(p=0;p<=k;++p)
            rez = min(rez, m*m + Solutie(i,m,p) + Solutie(n-i, m, k-p));
    }

    ///parcurg cu o linie si de la stanga la dreapta
    int j;
    for(j=1;j<=m-j;++j)//nu are rost sa trec de jumate ca repet cazurile
    {
        ///fac o taiere la dreapta liniei j, si asa
        ///impart tableta in doua bucati
        ///vreau sa obtin k patratele. dar aceste k patratele nu
        ///trebuie sa fie neaparat in aceeasi bucata(din cele doua obtinute)
        ///pot fi p patratele in bucata din stanga si k-p in cea din dreapta
        int p;
        for(p=0;p<=k;++p)
            rez = min(rez, n*n + Solutie(n,j,p) + Solutie(n, m-j, k-p));
    }

    dp[n][m][k] = rez;
    return rez;
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
        cin>>n>>m>>k;
        cout<<Solutie(n,m,k)<<"\n";
    }
    return 0;
}
