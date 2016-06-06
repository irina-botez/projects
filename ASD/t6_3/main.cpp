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

void srd(nod *rad)
{
    if(rad)
    {
        srd(rad->st);
        cout<<rad->info<<" ";
        srd(rad->dr);

    }
}
int main()
{ int n,i,x;
  nod*rad=NULL;
  cin>>n;
   for(i=1;i<=n;i++) { cin>>x;
                       insert(rad,x);
                      }
    srd(rad);
    return 0;
}
