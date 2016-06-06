#include <iostream>

using namespace std;

struct nod { int info;
            nod *urm;
           };
void afisare(nod *&prim)
{
    nod *p=prim;
     while(p!=NULL) { cout<<p->info<<" "; p=p->urm; }
}

int main()
{
    int n,i;
    nod*p,*bp,*bu,*c,*a;
    cin>>n;
    nod*prim=new nod;
    cin>>prim->info;
    prim->urm=NULL;
    nod*ultim=prim;

     for(i=1;i<n;i++)
     { p=new nod;
       cin>>p->info;
       ultim->urm=p;
       p->urm=NULL;
       ultim=p;
    }

    bp=new nod;
    bp->info=ultim->info;
    bp->urm=NULL;
    bu=bp;
    i=1;
    while(i<n)
    { for(a=prim;a->urm->urm!=NULL;a=a->urm);
       c=new nod;
       c->info=a->info;
       bu->urm=c;
       c->urm=NULL;
       bu=c;
       a->urm=NULL;
       i++;
       }
    afisare(bp);

    return 0;
}
