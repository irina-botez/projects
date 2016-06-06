#include <iostream>

using namespace std;

struct nod { int info;
               nod *urm;
                };
void push(int a,nod*&vf,nod*&sf)
{
    if(!vf){    vf=new nod;
                vf->info=a;
                vf->urm=NULL;
                sf=vf;
               }
      else          { nod*c=new nod;
                      c->info=a;
                      sf->urm=c;
                      c->urm=NULL;
                      sf=c;
                              }
}

int pop(nod*&vf)
{
    nod*c=vf;
    vf=vf->urm;
    return c->info;
}

int peek(nod*&vf)
{ nod*c=vf;
  return c->info;
    }

bool empty (nod*&vf)
{
    if(!vf) return true;
    return false;
}

int search(int a,nod*&vf)
{
   int k=0;
   nod*c=vf;
   while(c->info!=a && c!=NULL) { c=c->urm; k++; }
   if(!c) return -1;
   else return k;
}

void afisare(nod*vf)
{
    for(nod*c=vf;c!=NULL;c=c->urm) cout<<c->info<<" ";
}
int main()
{
    int n,i,x,a;
    nod *vf=NULL,*sf;
    cin>>n;
    //if(empty(vf)==true) cout<<"vida";
    for(i=1;i<=n;i++) { cin>>x; push(x,vf,sf); //cout<<sf->info;
                        }
     cin>>a; cout<<search(a,vf);
    //cout<<peek(vf);
    //pop(vf);
    //afisare(vf);
    return 0;
}
