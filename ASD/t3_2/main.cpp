#include <iostream>

using namespace std;

struct nod { int info;
            nod *urm;
           };

int main()
{
  int n,i,poz=0,s=0;
    nod*p;
    float ma;
    cin>>n;
    p=new nod;
    cin>>p->info;
    p->urm=NULL;
    nod*u=p;

     for(i=1;i<n;i++)
     { nod*a=new nod;
       cin>>a->info;
       u->urm=a;
       a->urm=NULL;
       u=a;
    }

    for(nod*a=p;a!=NULL;a=a->urm)
        if(a->info>=0)poz++;
    else s+=a->info;
    ma=s/(n-poz);
    cout<<"pozitive="<<poz<<endl<<"ma="<<ma;
    return 0;
}
