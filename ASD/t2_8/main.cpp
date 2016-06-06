#include <iostream>
#include <math.h>

using namespace std;

struct nod { int info;
            nod *urm;
           };

int main()
{
   int n,i,x,s=0,k;
    nod*p;
    cin>>n;
    nod*prim=new nod;
    cin>>prim->info;
    prim->urm=NULL;
    nod*ultim=prim;

     for(i=0;i<n;i++)
     { p=new nod;
       cin>>p->info;
       ultim->urm=p;
       p->urm=NULL;
       ultim=p;
    }

    cout<<"x="; cin>>x;
    p=prim;k=0;
   while(p!=NULL)
   {
      s+=p->info*pow(x,k);
      p=p->urm;
      k++;
   }
   cout<<endl<<"P("<<x<<")="<<s;

    return 0;
}
