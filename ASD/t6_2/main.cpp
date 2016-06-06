#include <iostream>

using namespace std;

struct nod { int info;
              nod *st,*dr;
             };

void insert(nod*&t,int x)
{
    if(!t) { t=new nod;
            t->info=x;
            t->st=NULL;
            t->dr=NULL;
            //cout<<t->info<<" ";
                }
      else  if(x < t->info) insert(t->st,x);
              else if(x > t->info) insert(t->dr,x);

}

int search(nod *t,int x)
{
   if(t==NULL) return 0;
   if(t->info == x) return 1;
    else
        if(x > t->info) search(t->dr,x);
          else search(t->st,x);



}

int findMax(nod *t)
{
    if(t->dr==NULL) return t->info;
    else findMax(t->dr);
}

void schimba(nod* &c,nod* &f)
{nod *aux;
 if(f->dr)
    schimba(c,f->dr);
 else
     {c->info=f->info;
      aux=f;
      f=f->st;
      delete aux;
      }
}

void delet(nod*&t,int x)
{    nod *aux;
    if(t)
     if(t->info==x)
        if(t->st==NULL && t->dr==NULL) //frunza
        {delete t; t=0;}
           else if(t->st==NULL) //are numai subordonat stang
       { aux=t->dr;
         delete t;
         t=aux;
       }
        else
        if(t->dr==NULL)    //are numai subordonat drept
           {aux=t->st;
            delete t;
            t=aux;}
          else
         schimba(t,t->st);  //are ambii subordonati
          else
     if(t->info<x)
            delet(t->dr,x);
     else
            delet(t->st,x);

 else
      cout<<"Valoarea de sters nu se gaseste in arbore ";

}


int main()
{
   int n,i,x,z;
   nod*rad=NULL;
   cout<<"Numarul cheilor ce vor fi inserate: "; cin>>n;
   for(i=1;i<=n;i++) { cin>>x;
                       insert(rad,x);
                      }

   cout<<"Nodul ce va fi cautat: "; cin>>z;
   if(search(rad,z)==1) cout<<"Nodul a fost gasit.";
   else cout<<"Nodul NU a fost gasit.";

   cout<<endl<<"Elementul maxim din arbore este: "<<findMax(rad);

   cout<<endl<<"Introduceti nodul ce va fi sters: "; cin>>x;
   delet(rad,x);



    return 0;
}
