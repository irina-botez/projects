#include <iostream>

using namespace std;int partition( int v[100], int li, int ls )
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
 if ( ls > li )
 {
  piv = partition( v, li, ls );
  quick( v,li, piv-1 );
  quick( v, piv+1, ls);
 }
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
