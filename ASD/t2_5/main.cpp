#include <iostream>

using namespace std;

void Delete(int A[100],int i,int &n,int k,int X)
{
    X=A[k];
    for(i=k;i<n;i++) A[i]=A[i+1];
    n--;
}

int main()
{
  int n,A[100],i,k,X;
  cin>>n;
  for(i=1;i<=n;i++) cin>>A[i];
  cout<<"k="; cin>>k;
  Delete(A,1,n,k,X);
   cout<<endl;
  for(i=1;i<=n;i++) cout<<A[i]<<" ";
    return 0;
}
