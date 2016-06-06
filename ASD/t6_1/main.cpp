#include <iostream>
using namespace std;

struct nod { int info;
             nod*st,*dr;
              }*rad;

nod* creare()
{   nod *t;
     int x;
    cin>>x;
    if(x)
    {
        t=new nod;
        t->info=x;
        t->st=creare();
        t->dr=creare();
        return t;
    }
    else return 0;
}

void rsd(nod *t)
{
    if(t)
    {   if(t->info) cout<<t->info<<" ";
        rsd(t->st);
        rsd(t->dr);
    }
}

void sdr(nod *t)
{
    if(t)
    {
        sdr(t->st);
        sdr(t->dr);
        if(t->info) cout<<t->info<<" ";
    }
}

void srd (nod *t)
{
     if(t)
    {
        sdr(t->st);
        if(t->info) cout<<t->info<<" ";
        sdr(t->dr);

    }
}

void parcurgere(nod *t,int x)
{
    if(t->info != x && t) { parcurgere(t,x);
                            parcurgere(t,x);

                                }

}
void frunza(nod *t)
{   int x,y,a;

    cout<<"Cine va fi tatal noului nod frunza: "; cin>>x;
    cout<<endl<<"Informatia noului nod frunza: "; cin>>y;
    parcurgere(t,x); cout<<t->info;
   /* if(t->st || t->dr || !t) cout<<"Nu se poate insera "<<x<<"ca fiu al lui "<<y;
    else { cout<<endl<<"Nodul fruza se va afla in stanga sau in dreapta tatalui sau? Pt. partea stanga introduceti valoarea 1 iar pt dreapta, valoarea 0";
           cin>>a;
           nod *c=new nod;
           c->info=y;
           c->st=c->dr=0;
           if(a) t->st=c;
           else t->dr=c;

                }*/


}
int main()
{

    rad=creare();
    frunza(rad);
    rsd(rad);

    //rsd(rad); cout<<endl; sdr(rad); cout<<endl; srd(rad);

    return 0;
}
