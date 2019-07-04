#include <bits/stdc++.h>

using namespace std;

int n,m,k,sol[1003][1003],contor;
char a[1003][1003];

/*
    O aplicatie misto a algoritmului Fill(umplere)
*/

inline void Fill(int i,int j)
{
    if(a[i][j]=='.')
    {
        a[i][j]='+';
        Fill(i,j+1);
        Fill(i+1,j);
        Fill(i,j-1);
        Fill(i-1,j);
    }
    else if(a[i][j]=='*')
        contor++;
}

inline void Fill2(int i,int j)
{
    if(a[i][j]=='+')
    {
        a[i][j]='-';
        sol[i][j]=contor;
        Fill2(i,j+1);
        Fill2(i+1,j);
        Fill2(i,j-1);
        Fill2(i-1,j);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen ("date.in","r",stdin);
        freopen ("date.out","w",stdout);
    #endif
    int i,j,x,y;
    cin>>n>>m>>k;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            if(a[i][j]=='.')
            {
                contor=0;
                Fill(i,j);//numar tablourile
                Fill2(i,j);//pun in sol
            }
        }
    }
    ///
    for(i=1;i<=k;++i)
    {
        cin>>x>>y;
        cout<<sol[x-1][y-1]<<"\n";
    }
    return 0;
}
