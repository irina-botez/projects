#include <iostream>

using namespace std;

void sort_ins (int v[100],int i,int n)
{
    int j,x;
    for(i=2;i<=n;i++)
    {
        x=v[i];
        j=i-1;
        while(j>0 && x< v[j])
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=x;
    }
}

int partition( int v[100], int li, int ls )
{
 int st, dr,piv_el,aux;
 int pi = st = li;
 piv_el = v[li];
 dr = ls;
 while ( st < dr )
 {
  while( v[st] <= piv_el )
   st++;
  while( v[dr] > piv_el )
   dr--;
  if ( st < dr )
  {
      aux=v[st]; v[st]=v[dr]; v[dr]=aux;
  }

 }
 v[li] = v[dr];
 v[dr] = piv_el;
 return dr;
}





void quick(int v[100],int li,int ls)
{
    int piv;
 if ( ls > li && ls-li+1 >11 )
 {
  piv = partition( v, li, ls );
  quick( v,li, piv-1 );
  quick( v, piv+1, ls);

 }
 else if(ls>li) sort_ins(v,li,ls);
}

int main()
{
    int n,i,v[100];
    cin>>n;
    for(i=1;i<=n;i++) cin>>v[i];

    quick(v,1,n);

    for(i=1;i<=n;i++) cout<<v[i]<<" ";
    return 0;
}
