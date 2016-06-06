#include <iostream>
#include <string.h>

using namespace std;

struct nod { int info;
            nod *urm,*ant;
               };

void ins_jos(nod *&p,nod *&u,int a)
{

     cin>>a;
    if(!p) {p=new nod;
             p->info=a;
             p->urm=p->ant=NULL;
             u=p;}
      else {
             nod*q=new nod;
           q->info=a;
           p->ant=q;
           q->urm=p;
           q->ant=NULL;
           p=q;
               }

}

void ins_sus(nod*&p,nod*&u,int x)
{
     cin>>x;
    if(!p) { p=new nod;
             p->info=x;
             p->urm=p->ant=NULL;
             u=p;
            }
     else { nod*q=new nod;
            q->info=x;
            u->urm=q;
            q->ant=u;
            q->urm=NULL;
            u=q;
          }
}

void del_p(nod *&p)
{
   nod *s=p;
   p=p->urm; p->ant=NULL;
   delete s;
}

void del_u(nod *&u)
{
   nod *s=u;
   u=u->ant; u->urm=NULL;
   delete s;
}

void afisare(nod *u)
{
    for(nod*a=u;a!=NULL;a=a->ant) cout<<a->info<<" ";
}

int main()
{
   int n,i,x;
   char c[4],a;
   nod *p=NULL,*u;
   cout<<"Numarul de noduri: "; cin>>n;
   cout<<endl<<"Nodurile pot fi inserate in partea de sus sau de jos a listei.Introduceti optiunea dvs. (sus/jos) urmata de informatia pe care doriti sa o adaugati."<<endl<<endl<<endl;
   for(i=1;i<=n;i++) { cin>>c;
                       if(strcmp(c,"jos")==0) ins_jos(p,u,x);
                       else ins_sus(p,u,x);
                      }
    cout<<endl<<endl<<endl<<"Meniu:"<<endl<<"a)Stergerea elementului de pe cea mai inalta pozitie."<<endl<<"b)Stergerea elementului de pe cea mai joasa pozitie."<<endl<<"Optiunea dvs. : "; cin>>a;
  if(a=='a') del_u(u);
   else del_p(p);
        afisare(u);
    return 0;
}
