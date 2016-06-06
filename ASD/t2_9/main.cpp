#include <iostream>

using namespace std;

struct nod { int info;
            nod *urm;
           };
void creare(nod *&prim,nod *&ultim,int n)
{
    int i;
    nod*a;

    prim=new nod;
    cin>>prim->info;
    prim->urm=NULL;
    ultim=prim;

     for(i=1;i<n;i++)
     { a=new nod;
       cin>>a->info;
       ultim->urm=a;
       a->urm=NULL;
       ultim=a;
    }
}

void afisare(nod *&prim)
{
    nod *p=prim;
     while(p!=NULL) { cout<<p->info<<" "; p=p->urm; }
}

int main()
{
    int n1,n2,ok=0,v[100],i,n;
    nod *p1,*p2,*p3,*u1,*u2,*u3,*a,*b;

    cout<<"n1="; cin>>n1;
     creare(p1,u1,n1);
    cout<<endl<<"n2="; cin>>n2;
    creare(p2,u2,n2);



    a=p1; b=p2; i=1;
    while(a!=NULL && b!=NULL)
    {
          v[i]=(a->info+b->info+ok)%10;
          ok=(a->info+b->info+ok)/10;
          i++;
          a=a->urm;
          b=b->urm;
    }

        while(b!=NULL)
                 {

                 v[i]=(b->info+ok)%10;
          ok=(b->info+ok)/10;
                     i++; b=b->urm;
                   }

           while(a!=NULL)
                 {

                 v[i]=(a->info+ok)%10;
          ok=(a->info+ok)/10;
                     i++; a=a->urm;
                   }
                   if(ok==1) v[i]=ok;

    n=i-1;
    for(i=1;i<=n;i++) cout<<v[i]<<" ";




    return 0;
}
