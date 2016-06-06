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

void creare(nod*&prim,nod*&ultim,int n)
{
    nod*p;
    int i;
    cin>>n;
    prim=new nod;
    cin>>prim->info;
    prim->urm=NULL;
    ultim=prim;

     for(i=1;i<n;i++)
     { p=new nod;
       cin>>p->info;
       ultim->urm=p;
       p->urm=NULL;
       ultim=p;
    }

}

int main()
{
    int na,nb,i;
    nod *pa,*pb,*pc=NULL,*ua,*ub,*uc,*a,*b,*c;
    creare(pa,ua,na);  creare(pb,ub,nb);
    a=pa; b=pb;


    while(a!=NULL && b!= NULL)
    { if(!pc)
        if(a->info<=b->info) { pc=new nod; pc->info=a->info; a=a->urm; pc->urm=NULL; uc=pc;}
    else   { pc=new nod; pc->info=b->info; b=b->urm; pc->urm=NULL; uc=pc;}
    else { c=new nod;
            if(a->info<=b->info) { c->info=a->info; uc->urm=c; c->urm=NULL; uc=c;  a=a->urm; }
              else   { c->info=b->info; uc->urm=c; c->urm=NULL; uc=c; b=b->urm; }
                  }
    }
    afisare(pc);
    return 0;
}
