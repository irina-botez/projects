#include <iostream>

using namespace std;

struct nod { int info;
               nod *urm;
                };

void push (int a,nod *&stiva)
{  if(!stiva) { stiva=new nod;
                stiva->info=a;
                stiva->urm=NULL;
                }
      else {    nod *s=new nod;
                s->info=a;
                s->urm=stiva;
                stiva=s;
           }



}

int pop(nod*&stiva)
{
    nod*s=stiva;
    stiva=stiva->urm;
    return s->info;
}

int peek(nod*&stiva)
{ nod*s=stiva;
  return s->info;
}

bool empty(nod*&stiva)
{ if(!stiva) return true;
  return false;
    }

int search(int a,nod*&stiva)
{ int c=0;
  nod*s=stiva;
  while(s->info!=a && s!=NULL) { s=s->urm; c++; }
   if(!s) return -1;
   else return c+1;

}

void afiseaza(nod*stiva)
{
    for(nod*a=stiva;a!=NULL;a=a->urm)     cout<<a->info<<" ";
}

int main()
{   int i,n,x,a;
    nod*stiva=NULL;
    //if(empty(stiva)==true) cout<<1;
    cin>>n;
    for(i=1;i<=n;i++) {  cin>>x;
                         push(x,stiva);
                               }
    //pop(stiva);
    cin>>a; cout<<search(a,stiva);
    //afiseaza(stiva);

    return 0;
}

