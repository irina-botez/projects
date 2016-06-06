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
    int s,n;
    pol *p,*u;
    cin>>n; creare(p,u,n);
    cin>>s;
    for(pol*a=p;a!=NULL;a=a->urm)
        if(a->coef!=0) a->coef*=s;

       for(pol*a=p;a!=NULL;a=a->urm)
        if(a->coef!=0) cout<<a->coef<<"X^"<<a->gr<<"+";



    return 0;
}
