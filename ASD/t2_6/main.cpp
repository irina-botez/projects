#include <iostream>

using namespace std;

int main()
{
    int n,i,j,k,v[100];
    cin>>n;
    for(i=1;i<=n;i++) cin>>v[i];
    for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)
    if(v[i]==v[j]) { for(k=i;k<=n;k++) v[k]=v[k+1];
                      n--;
                       }

     for(i=1;i<=n;i++) cout<<v[i]<<" ";
    return 0;
}
