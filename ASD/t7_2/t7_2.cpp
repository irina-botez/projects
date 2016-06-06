#include <iostream>

using namespace std;

struct nod { int info,ec;
             nod *st,*dr;
                  };

void inaltime(nod* rad,int &h,int l)
{
 if (rad){
           inaltime(rad->dr,h,l+1);
           if ((rad->st==NULL)&&(rad->dr==NULL)&&(h<l))
           h=l;
        inaltime(rad->st,h,l+1);
         }
}
void echilibrat(nod *t)
{
    int hst=0,hdr=0;
    if(t->st) inaltime(t->st,hst,0);
    else hst=-1;
    if(t->dr) inaltime(t->dr,hdr,0);
    else hdr=-1;
    t->ec=hdr-hst;
}
nod *rot_dr(nod *t)
{
    nod *q;
    q=t->st;
    t->st=q->dr;
    q->dr=t;
    echilibrat(t);
    echilibrat(q);
    t=q;
    return t;
}

nod *rot_st(nod *t)
{
    nod *q;
    q=t->dr;
    t->dr=q->st;
    q->st=t;
    echilibrat(t);
    echilibrat(q);
    t=q;
    return t;
}

nod *drot_dr(nod *t)
{
    t->st=rot_st(t->st);
    t=rot_dr(t);
    return t;
}

nod *drot_st(nod *t)
{
    t->dr=rot_dr(t->dr);
    t=rot_st(t);
    return t;
}





nod *echil(nod *t)
{
    nod *q;
    echilibrat(t);
    if(t->ec==-2)
       {
           q=t->st;
           if(q->ec==1) t=drot_dr(t);
           else t=rot_dr(t);
       }
       else if(t->ec==2)
        {
            q=t->dr;
            if (q->ec==-1)
              t = drot_st(t);
            else
 t = rot_st(t);
 }

 return t;
}


void adauga(nod*&t,int x)
{
    if(!t) { t=new nod;
            t->info=x;
            t->st=NULL;
            t->dr=NULL;
            //cout<<t->info<<" ";
                }
      else  if(x < t->info) adauga(t->st,x);
              else if(x > t->info) adauga(t->dr,x);
       t=echil(t);

}

int cauta(nod *t,int x)
{
   if(t==NULL) return 0;
   if(t->info == x) return 1;
    else
        if(x > t->info) cauta(t->dr,x);
          else cauta(t->st,x);

}

int maxim(nod *t)
{
    if(t->dr==NULL) return t->info;
    else maxim(t->dr);
}

void schimba(nod* &c,nod* &f)
{nod *aux;
 if(f->dr)
    schimba(c,f->dr);
 else
     {c->info=f->info;
      aux=f;
      f=f->st;
      delete aux;
      }
}

void delet(nod*&t,int x)
{    nod *aux;
    if(t)
     if(t->info==x)
        if(t->st==NULL && t->dr==NULL) //frunza
        {delete t; t=0;}
           else if(t->st==NULL) //are numai subordonat stang
       { aux=t->dr;
         delete t;
         t=aux;
       }
        else
        if(t->dr==NULL)    //are numai subordonat drept
           {aux=t->st;
            delete t;
            t=aux;}
          else
         schimba(t,t->st);  //are ambii subordonati
          else
     if(t->info<x)
            delet(t->dr,x);
     else
            delet(t->st,x);

 else
      cout<<"Valoarea de sters nu se gaseste in arbore ";

}

void afiseaza(nod *t)
{
    if(t)
    {
        afiseaza(t->st);
        cout<<t->info<<" ";
        afiseaza(t->dr);
    }
}




int main()
{
     int n,i,x,h=0,l=0;
   nod*rad=NULL;
   cout<<"Numarul cheilor ce vor fi inserate: "; cin>>n;
   for(i=1;i<=n;i++) { cin>>x;
                       adauga(rad,x);
                      }

     cin>>x; delet(rad,x);
     afiseaza(rad);
    return 0;
}
