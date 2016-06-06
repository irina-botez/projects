#include <iostream>

using namespace std;

struct nod { int info;
            nod *urm,*ant;
               };

void ad_i(nod*&p,nod*&u,int a)
{
    cout<<"Elementul ce va fi adaugat: "; cin>>a; cout<<endl;
    if(!p) { p=new nod;
             p->info=a;
             p->urm=p->ant=NULL;
             u=p;
            }
    else { nod*q=new nod;
           q->info=a;
           p->ant=q;
           q->urm=p;
           q->ant=NULL;
           p=q;
        }
}

void creare(nod*&p,nod*&u,int x)
{
   if(!p) { p=new nod;
             p->info=x;
             p->urm=p->ant=NULL;
             u=p;
            }
     else { nod*q=new nod;
            q->info=x;
            q->urm=NULL;
            q->ant=u;
            u->urm=q;
            u=q;
           }
}

void ad_s(nod*&p,nod*&u,int x)
{
    cout<<"Elementul ce va fi adaugat: "; cin>>x; cout<<endl;
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
            u=q;          }
}

void ad_int(nod*&p,int x)
{  cout<<"Elementul va fi adaugat inaintea nodului cu informatia: "; cin>>x; cout<<endl;
    nod*a=p; while(a->urm->info!=x && a!=NULL) a=a->urm;
    if(a) { nod*c=new nod;
           cout<<"Elementul ce va fi adaugat: "; cin>>c->info; cout<<endl;
             a->urm->ant=c;
             c->urm=a->urm;
             a->urm=c;
             c->ant=a;
            }
}

void del_ord(nod*&p,nod *&u,int x,int n)
{
    int i=1;
    nod*a=p,*s;
    cout<<"Numarul de ordine al elementului ce va fi sters ce va fi sters: "; cin>>x; cout<<endl;
    if(x==1){ s=p;
              p=p->urm; p->ant=NULL;
              delete s;
             }
      else if(x==n) { s=u;
                      u=u->ant;
                      u->urm=NULL;
                      delete s;
                      }
         else
    {while(a!=NULL && i!=x) {a=a->urm; i++;}
    s=a;
    a->ant->urm=a->urm;
    a->urm->ant=a->ant;
    delete s;}
}
void del_val(nod*&p,nod *&u,int x)
{
    nod*a=p,*s;
    cout<<"Elementul ce va fi sters: "; cin>>x; cout<<endl;
    if(p->info==x) {
                    s=p;
                    p=p->urm; p->ant=NULL;
                    delete s;
                        }
     else if(u->info==x) {   s=u;
                            u=u->ant;
                            u->urm=NULL;
                            delete s;
                         }
        else {
                    while(a!=NULL && a->info!=x) a=a->urm;
                    s=a;
                    a->ant->urm=a->urm;
                    a->urm->ant=a->ant;
                    delete s;
                    }

}
void afisare (nod *p)
{
    for(nod*a=p;a!=NULL;a=a->urm) cout<<a->info<<" ";
}

void afisare_inv(nod *u)
{
    for(nod*a=u;a!=NULL;a=a->ant) cout<<a->info<<" ";
}

int main()
{
    int n,i,x;
    nod*p=NULL,*u;
    char c;
    cout<<"Numarul de noduri: "; cin>>n; cout<<endl;
    for(i=1;i<=n;i++) { cout<<"Nodul "<<i<<" :" ; cin>>x; cout<<endl;
                        creare(p,u,x);
                            }
      cout<<"Meniu:"<<endl<<"a)Adaugarea unui element la inceput."<<endl<<"b)Adaugarea unui element la sfarsit."<<endl<<"c)Adaugarea unui element in interiorul listei."<<endl<<"d)Afisarea elementelor listei in ordinea introducerii lor."<<endl<<"e)Afisarea elementelor listei in ordine inversa."<<endl<<"f)Stergerea unui element din lista stiind numarul lui de ordine."<<endl<<"g)Stergerea unui element din lista stiind valoarea lui."<<endl<<endl<<endl;
     cout<<"Optiunea dvs. este: "; cin>>c;
      switch(c) { case 'a': ad_i(p,u,x); afisare(p); break;
                  case 'b': ad_s(p,u,x); afisare(p); break;
                  case 'c': ad_int(p,x); afisare(p); break;
                  case 'd': afisare(p); break;
                  case 'e': afisare_inv(u); break;
                  case 'f': del_ord(p,u,x,n); afisare(p); break;
                  case 'g': del_val(p,u,x); afisare(p); break;
                      }


    return 0;
}
