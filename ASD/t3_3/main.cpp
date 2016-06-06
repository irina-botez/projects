#include <iostream>

using namespace std;
struct nod { int info;
            nod *urm;
           };
void ins(nod*&p)
{ nod*c,*a;
  a=p;
  while(a->urm!=NULL)
  { c=new nod;
    c->info=(a->info+a->urm->info)/2;
    c->urm=a->urm;
    a->urm=c;
    a=a->urm->urm;

  }
}
 void afisare(nod *&prim)
{
    nod *p=prim;
     while(p!=NULL) { cout<<p->info<<" "; p=p->urm; }
}



int main()
{
int n,i;
    nod*p,*a,*c;
    float ma;
    cin>>n;
    p=new nod;
    cin>>p->info;
    p->urm=NULL;
    nod*u=p;

     for(i=1;i<n;i++)
     { a=new nod;
       cin>>a->info;
       u->urm=a;
       a->urm=NULL;
       u=a;
    }
    ins(p);
    afisare(p);
    return 0;
}
