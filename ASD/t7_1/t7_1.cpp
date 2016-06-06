#include <iostream>
#include<string.h>

using namespace std;

struct nod { char info;
              nod *st,*dr;
             };

void insert(nod*&t,char x)
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

void drs(nod *t,char c[100])
{
    if(t)
    {
        drs(t->dr,c);
        c[strlen(c)]=t->info; c[strlen(c)+1]='\0';
        drs(t->st,c);
    }
}

int main()
{
    int i;
    char s[100],c[100];
   nod*rad=NULL;
   cin>>s;

   for(i=0;i<strlen(s);i++) insert(rad,s[i]);

     drs(rad,c); strcpy(s,c);
     cout<<s;
    return 0;
}
