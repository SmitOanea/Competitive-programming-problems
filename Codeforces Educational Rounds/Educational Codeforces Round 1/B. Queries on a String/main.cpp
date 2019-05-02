#include <bits/stdc++.h>

using namespace std;

int m;
char s[10003],t[20004];

/**
    Pur si simplu brut, fac efectiv fiecare query
*/

inline void Solutie(int l,int r, int k)
{
    int lg,i,st,j;
    lg=r-l+1;
    k%=lg;//nu are rost sa shiftez mai mult de atat
    for(i=l;i<=r;++i)//iau doar bucata care ma intereseaza
        t[i-l]=s[i];
    for(i=lg;i<2*lg;++i)//si o dublez. pentru ca dublarea unui sir e cea mai eleganta metoda de a face cyclic shifts
        t[i]=t[i-lg];
    //am dublat sirul
    st=lg;
    st-=k;
    j=st;
    for(i=l;i<=r;++i)//bag sirul shiftat in s
    {
        s[i]=t[j];
        j++;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen ("date.in","r",stdin);
        freopen ("date.out","w",stdout);
    #endif
    int i,l,r,k;
    cin>>s;
    cin>>m;
    for(i=1;i<=m;++i)
    {
        cin>>l>>r>>k;
        Solutie(l-1,r-1,k);
    }
    cout<<s<<"\n";
    return 0;
}
