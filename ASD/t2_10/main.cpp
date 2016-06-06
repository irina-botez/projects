#include <iostream>

using namespace std;

struct pol { int gr,coef;
             pol *urm;
               };

void creare(pol *&prim,pol *&ultim,int n)
{
    int i;
    pol*a;

    prim=new pol;
    cin>>prim->gr>>prim->coef;
    prim->urm=NULL;
    ultim=prim;

     for(i=1;i<n;i++)
     { a=new pol;
       cin>>a->gr>>a->coef;
       ultim->urm=a;
       a->urm=NULL;
       ultim=a;
    }
}
int main()
{
    int p,q;
    pol *P,*Q,*up,*uq,*a,*b;
    cout<<"p="; cin>>p; creare(P,up,p);
    cout<<endl<<"q="; cin>>q; creare(Q,uq,q);
    a=P; b=Q;
    while(a!=NULL&&b!=NULL)
    { if(a->gr<b->gr) { if(b->coef !=1) cout<<b->coef<<"X^"<<b->gr<<"+";
                         else cout<<"X^"<<b->gr<<"+";
                         b=b->urm;
                        }

       else if(b->gr<a->gr) { if(a->coef !=1) cout<<a->coef<<"X^"<<a->gr<<"+";
                                else cout<<"X^"<<a->gr<<"+";
                               a=a->urm;
                             }
         else { cout<<b->coef+a->coef<<"X^"<<b->gr;
                 if(a->urm !=NULL || b->urm !=NULL) cout<<"+";
                  a=a->urm; b=b->urm;
               }
    }

   if(a==NULL)
    while(b!=NULL)
   { if(b->coef !=1) cout<<b->coef<<"X^"<<b->gr;
       else cout<<"X^"<<b->gr;
      if(b->urm !=NULL) cout<<"+";
      b=b->urm;
   }
   else if(b==NULL)
        while(a!=NULL)
   { if(a->coef !=1) cout<<a->coef<<"X^"<<a->gr<<"+";
         else cout<<"X^"<<a->gr<<"+";
     if(a->urm!=NULL) cout<<"+";
      a=a->urm;
   }
    return 0;
}
