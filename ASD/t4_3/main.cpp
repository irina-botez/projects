#include <iostream>

using namespace std;
struct nod { char info;
               nod *urm;
                }stiva;

void push (char a,nod *&stiva)
{  if(!stiva) { stiva=new nod;
                stiva->info=a;
                stiva->urm=NULL;
                }
      else {    nod *s=new nod;
                s->info=a;
                s->urm=stiva;
                stiva=s;
           }

}

void pop(nod*&stiva)
{
    nod*s=stiva;
    stiva=stiva->urm;
    delete s;
}

int paranteze()
{
   int n,i;
    nod *stiva=NULL;
    char x;

    cin>>n;
    for(i=1;i<=n;i++) { cin>>x;
                        if(x=='(') push(x,stiva);
                        else if(stiva) pop(stiva);
                               else  return 0;
                        }
        if(!stiva) return 1;
        else return 0;

}
int main()
{
     if(paranteze()==1) cout<<"Parantezele sunt inchise corect";
     else cout<<"Parantezele NU sunt inchise corect";
    return 0;
}
