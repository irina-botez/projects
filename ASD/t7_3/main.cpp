#include <iostream>

using namespace std;
int v[100];

void inter(int li,int m,int ls)
{
    int i,j,k,a[100];
    i=li; j=m+1; k=1;
    while(i<=m && j<=ls)
     if(v[i]<=v[j]) a[k++]=v[i++];
    else a[k++]=v[j++];
        if(i<=m)
            for(j=i;j<=m;j++) a[k++]=v[j];
        else for(i=j;i<=ls;i++) a[k++]=v[i];
     k=1; for(i=li;i<=ls;i++) v[i]=a[k++];
}

void merge(int li,int ls)
{
    int aux;
    if(li<=ls)
        if(ls-li<=1)
    {
        if(v[li]>v[ls]) {aux=v[li]; v[li]=v[ls]; v[ls]=aux;}

    }
    else { merge(li,(li+ls)/2);
            merge((li+ls)/2+1,ls);
            inter(li,(li+ls)/2,ls);

            }
}



int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++) cin>>v[i];
    merge(1,n);
    for(i=1;i<=n;i++) cout<<v[i]<<" ";
        return 0;
}
