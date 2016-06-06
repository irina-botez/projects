#include <iostream>

using namespace std;

struct nod { int info;
            nod *urm,*ant;
               };

void creare(nod*&p,nod*&u)
{
   int n,i;

   p=new nod;
   p->info=1234;
   p->urm=p->ant=p;
   u=p;

   cin>>n;
   for(i=1;i<=n;i++)
     { nod*q=new nod;
       cin>>q->info;
       u->urm=q;
       q->ant=u;
       q->urm=p;
       u=q;
           }
}

void afisare(nod*p)
{
    for(nod*a=p->urm;a!=p;a=a->urm) cout<<a->info<<" ";
}

void inserare(nod *p)
{
    nod *q=new nod;
    cin>>q->info;
    q->urm=p->urm;
    p->urm->ant=q;
    p->urm=q;
    q->ant=p;

}
void stergere (nod*&u,nod *p)
{
    nod*s=u;
    p->ant=u->ant;
    u->ant->urm=p;
    delete s;
}
int main()
{
    nod *p,*u;
    creare(p,u);
    //inserare(p);
   // stergere(u,p);
    afisare(p);
    return 0;
}
