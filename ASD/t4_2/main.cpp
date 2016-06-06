#include <iostream>

using namespace std;

struct nod { char info;
               nod *urm;
                };

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

int main()
{
    int n,i;
    nod *stiva=NULL;
    char x;

    cin>>n;
    for(i=1;i<=n;i++) { cin>>x;
                        if(stiva==NULL || x==stiva->info)  push(x,stiva);
                        else pop(stiva); }

    if(!stiva) cout<<" acelasi numar de 'a' si 'b' ";
    else if(stiva->info=='a') cout<<" mai multi 'a' decat 'b' ";
           else cout<<" mai multi 'b' decat 'a' ";
    return 0;
}
