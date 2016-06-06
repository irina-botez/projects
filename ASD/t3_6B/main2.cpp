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

nod*invers(nod*&prim)
{ nod*p1,*p2,*p3;
  p1=prim;
  p2=prim->urm;
  prim->urm=NULL;
  while(p2)
  {
      p3=p2->urm;
      p2->urm=p1;
      p1=p2;
      p2=p3;
  }
    return p1;
}

int main()
{
    int n,i;
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
   nod*x=invers(prim);
    afisare((x));
        return 0;
}
