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

void inserare(nod*p,nod*&u)
{

    nod*a,*q;
    q=new nod;
     cout<<"Informatia inserata:"; cin>>q->info;
    if(u==p) {
               p->urm=q;
               q->ant=p;
               q->urm=p;
               u=q;
                }
     else { int k; cout<<"Inaintea cui inseram:"; cin>>k; a=p->urm;
            while(a!=p&&a->info!=k) a=a->urm;
            if(a!=p) {
                       q->ant=a->ant;
                       a->ant->urm=q;
                       q->urm=a;
                       a->ant=q;  }
                else { p->ant=q;
                       q->urm=p;
                       u->urm=q;
                       q->ant=u;
                       u=q;
                      }
         }
}

void stergere(nod*p)
{   int k;cin>>k;
    nod*a=p->urm;
    while(a!=p&&a->info!=k)a=a->urm;
    if(a!=p) { a->urm->ant=a->ant;
               a->ant->urm=a->urm;
               delete a;
             }
}
int main()
{
    nod*p,*u;
    creare(p,u);
//    inserare(p,u);
//    stergere(p);
    afisare(p);
    return 0;
}
