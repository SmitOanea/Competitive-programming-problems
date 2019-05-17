#include <bits/stdc++.h>
#define pi 3.14159265358979323846

using namespace std;

/**

    Trebuie sa sortam acei vectori dupa coordonatele polare.
    Pentru ast se foloseste in mod normal functia arctg(atan in C++),
    dar aceasta are valori identice pentru vectori aflati in cadrane
    diferite si ar trebui sa ne batem capul sa punem if-uri pentru fiecare cadran.

    Din fericire exista functia atan2(y, x) pentru noi, care asociaza fiecarui
    unghi polar cate un numar intre -pi si pi, fara sa se repete.

    Singura chestie e ca asta nu o sa fie tocmai o sortare in adevaratul sens al
    cuvantului, deoarace:
    1) dupa sortare primul vector poate fi foarte aproape de ultimul, dar
       pentru asta facem un if nu-i bai
    2) ca sa vedem exact "diferenta"(distanta) dintre doi vectori, trebuie
       sa vedem daca diferenta dintre unghiurile lor polare e mai mare decat pi.
       Daca da, e ca si cum am inconjura mai mult de jumatate de cerc aiurea,
       deci trebuie sa o luam in partea cealalta(in sensul invers acelor de ceas).

    Calculatorul meu recunoaste constanta M_PI definita de C++, dar
    Codeforces-ul nu, da eraore de compilare. A trebuit sa definesc
    eu valoarea lui pi.

    Si trebuie pus si long double pentru precizie, meh.
*/

struct Punct_2D{
    int x, y;
    int id;
};

int n, ind;
Punct_2D a[100003];

inline bool CMP_CoordonatePolare(const Punct_2D A, const Punct_2D B)
{
    return atan2((long double)A.y, (long double)A.x) > atan2((long double)B.y, (long double)B.x);
}

long double unghi(Punct_2D &A, Punct_2D &B)
{
    long double fi1 = atan2((long double)A.y, (long double)A.x);
    long double fi2 = atan2((long double)B.y, (long double)B.x);
    long double dif;
    dif = abs(fi2-fi1);
    if(abs(fi2-fi1)>pi)///asta e marea smecherie
        dif = 2*pi-dif;
    return dif;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen ("date.in","r",stdin);
        freopen ("date.out","w",stdout);
    #endif
    int i;
    Punct_2D p;
    cin>>n;

    ind=0;
    for(i=1;i<=n;++i)
    {
        cin>>p.x>>p.y;
        p.id = i;
        a[++ind] = p;
    }

    sort(a+1,a+n+1,CMP_CoordonatePolare);

    long double dif_min;
    dif_min = unghi(a[1], a[n]);

    int id1=a[1].id, id2=a[n].id;
    for(i=1;i<n;++i)
        if(unghi(a[i], a[i+1]) < dif_min )
        {
            dif_min = unghi(a[i], a[i+1]);
            id1 = a[i].id;
            id2 = a[i+1].id;
        }
    cout<<id1<<" "<<id2<<"\n";
    return 0;
}
