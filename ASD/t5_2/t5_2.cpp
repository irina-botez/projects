#include <iostream>

using namespace std;

struct nod { int info,pr;
            nod *urm;
           };

 void push(int a,int b,nod*&vf,nod*&sf)
{
    if(!vf){    vf=new nod;
                vf->info=a;
                vf->pr=b;
                vf->urm=NULL;
                sf=vf;
               }
      else          { nod*c=new nod;
                      c->info=a;
                      c->pr=b;
                      sf->urm=c;
                      c->urm=NULL;
                      sf=c;
                              }
}

void pop(nod*&vf,nod *&sf)
{
    if(vf) { nod*c=vf;
             vf=vf->urm;
             delete c;
            }
}

void afisare(nod*vf)
{
    for(nod*c=vf;c!=NULL;c=c->urm) cout<<c->info<<" "<<c->pr<<endl;
}

void punere(nod *&c1,nod *&c2,nod *&u1,nod*& u2)
{
    int a,b;
    cout<<"Informatia+prioritatea nodului ce trebuie adaugat: ";
    cin>>a>>b;
    if(!c1) push(a,b,c1,u1);
       else {  if(b>=u1->pr) push(a,b,c1,u1);
                            else {
            while(c1->pr<=b ) {
                                 push(c1->info,c1->pr,c2,u2);
                                 pop(c1,u1);
                                }
                push(a,b,c2,u2);
               while(c1) {push(c1->info,c1->pr,c2,u2);
                           pop(c1,u1);  }

                 while(c2) { push(c2->info,c2->pr,c1,u1);
                              pop(c2,u2);}
               }
         }
}

void scoatere(nod *&c1,nod *&c2,nod *&u1,nod*& u2)
{
   int a,b;
    cout<<"Informatia+prioritatea nodului ce trebuie scos: ";
    cin>>a>>b;
    while(c1->pr<b)
    {
        push(c1->info,c1->pr,c2,u2);
        pop(c1,u1);
    }
    if(c1->pr>b) cout<<"Nodul acesta nu se afla in coada existenta";
    else { while(c1->info!=a && c1->pr==b)
              { push(c1->info,c1->pr,c2,u2);
                pop(c1,u1);
              }
            if(c1->info==a) { pop(c1,u1);
                              while(c1)
                                { push(c1->info,c1->pr,c2,u2);
                                  pop(c1,u1);
                                }
                              while(c2)
                              { push(c2->info,c2->pr,c1,u1);
                                pop(c2,u2);
                              }
                            }
               else cout<<"Nodul acesta nu se afla in coada existenta";
}
}

int main()
{
   int n,i,a,b;
   nod *c1=NULL,*u1,*c2=NULL,*u2;
   cout<<"Nr. noduri: "; cin>>n;
   for(i=1;i<=n;i++)
   {
       cin>>a>>b;
       if(!c1) push(a,b,c1,u1);
       else {  if(b>=u1->pr) push(a,b,c1,u1);
                            else {
            while(c1->pr<=b ) {
                                 push(c1->info,c1->pr,c2,u2);
                                 pop(c1,u1);
                                }
                push(a,b,c2,u2);
               while(c1) {push(c1->info,c1->pr,c2,u2);
                           pop(c1,u1);  }

                 while(c2) { push(c2->info,c2->pr,c1,u1);
                              pop(c2,u2);}
               }
         }
   }
 punere(c1,c2,u1,u2);
 scoatere(c1,c2,u1,u2);
 afisare(c1);

    return 0;
}
