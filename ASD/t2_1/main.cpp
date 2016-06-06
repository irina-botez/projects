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

void ins(nod*&prim)
{
   nod *p=new nod;
    cin>>p->info;
    p->urm=prim;
    prim=p;
}

void ins2(nod*&prim,nod*&ultim)
{   int x;
    cout<<"x="; cin>>x;
    nod*r=prim;
    while(r!=NULL&&r->info!=x) r=r->urm;
    if(r==NULL) { cout<<"NU exista   ";
                   nod*a=new nod;
                   cin>>a->info;
                   ultim->urm=a;
                   a->urm=NULL;
                   ultim=a;
                  }

      else { cout<<"Exista  ";
             nod*a=new nod;
             cin>>a->info;
             nod*q=r->urm;
             r->urm=a;
             a->urm=q;
                  }

}

void sterg(nod*&prim)
{ int x;
  cout<<"x="; cin>>x;
  nod*r=prim;
  if(r->info==x){ prim=prim->urm;
                  delete r;
                }
 while(r!=NULL && r->urm->info!=x) r=r->urm;
 if(r!=NULL) { nod*q=r->urm;
               r->urm=q->urm;
               delete q;
               }


}

void sterg2(nod*&prim,nod*&ultim)  //tutorialeplusplus.blogspot.ro
{ nod*r=prim;
  while(r!=NULL)
  { nod*a=r;
    r=r->urm;
    delete a;
   }
  prim=ultim=NULL;
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

    //ins(prim);
    //ins2(prim,ultim);
    //sterg(prim);
    sterg2(prim,ultim);
    afisare(prim);
    return 0;
}
