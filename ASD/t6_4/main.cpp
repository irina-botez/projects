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

void cautare(nod *rad,int a,int b)
{    if(rad)
    {if(rad->info >=a && rad->info <=b) cout<<rad->info<<" ";
     cautare(rad->st,a,b);
     cautare(rad->dr,a,b);}
}

int main()
{
    int n,i,x,k1,k2;
   nod*rad=NULL;
   cout<<"Numarul cheilor ce vor fi inserate: "; cin>>n;
   for(i=1;i<=n;i++) { cin>>x;
                       insert(rad,x);
                      }
    cout<<endl<<"Introduceti valorile pt k1 si k2: ";
    cin>>k1>>k2;
    cautare(rad,k1,k2);
        return 0;
}
