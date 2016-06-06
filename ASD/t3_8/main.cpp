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

void creare(nod*&prim,nod*&ultim,int n)
{
    nod*p;
    int i;
    cin>>n;
    prim=new nod;
    cin>>prim->info;
    prim->urm=NULL;
    ultim=prim;

     for(i=1;i<n;i++)
     { p=new nod;
       cin>>p->info;
       ultim->urm=p;
       p->urm=NULL;
       ultim=p;
    }

}


int main()
{
    int n,i;
    nod*pc,*uc,*pa=NULL,*pb=NULL,*ua,*ub,*a,*b,*c;
    creare(pc,uc,n);
    c=pc; i=1;
    while(c!=NULL)
    {  if(i%2==1)
         {
             if(!pa) {  pa=new nod; pa->info=c->info; pa->urm=NULL; ua=pa;
                  }
            else { a=new nod; a->info=c->info; a->urm=NULL; ua->urm=a; ua=a;
                  }
         }
        else {if(!pb){pb=new nod; pb->info=c->info; pb->urm=NULL; ub=pb;}
               else { b=new nod; b->info=c->info; b->urm=NULL; ub->urm=b; ub=b;
                    }
        }
        i++;c=c->urm;

    }
    afisare(pa);
    cout<<endl;
    afisare(pb);

    return 0;
}
