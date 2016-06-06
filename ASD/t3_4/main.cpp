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

void sterg(nod*&prim,int k)
{
  nod*r=prim; int i=1;
  if(k==1){ prim=prim->urm;
                  delete r;
                }
    else
   {
      while(i<k-1) {   r=r->urm;
                       i++;
                     }
        nod*q=r->urm;
        r->urm=q->urm;
        delete q;
   }


}

int main()
{
    int n,i,k;
    nod*p;
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
    cout<<"k=";cin>>k;
    sterg(prim,k); afisare(prim);
    return 0;
}
