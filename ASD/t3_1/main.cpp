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

void ins_u(nod*&p,nod*&u,int x)
{
    nod*c=new nod;
    c->info=x;
    c->urm=NULL;
    u->urm=c;
    u=c;


}

void ins_p (nod*&p,int x)
{
    nod *c=new nod;
    c->info=x;
    c->urm=p;
    p=c;
}

int main()
{  int n,i,x;
   nod*p=NULL,*a,*u,*c;
   cin>>n;


   for(i=1;i<=n;i++)
   {   cin>>x;
       if(p==NULL)
          { p=new nod;
            p->info=x;
            p->urm=NULL;
            u=p; }
         else  if(x<=p->info) ins_p(p,x);
                 else
                    if(x>u->info) ins_u(p,u,x);
                else {   a=p;
                     while(x>a->urm->info) a=a->urm;
                           c=new nod;
                           c->info=x;
                           c->urm=a->urm;
                           a->urm=c;

                          }


   }

     afisare(p);



    return 0;
}
