#include <iostream>

using namespace std;

void Insert(int A[100],int i,int &n,int k,int Elem)
{
  for(i=n+1;i>k;i--) A[i]=A[i-1];
  n++;
  A[k]=Elem;
}

int main()
{
  int n,A[100],i,k,Elem;
  cin>>n;
  for(i=1;i<=n;i++) cin>>A[i];
  cout<<"k="; cin>>k;
  cout<<endl<<"Elem="; cin>>Elem;
  Insert(A,1,n,k,Elem);
  cout<<endl;
  for(i=1;i<=n;i++) cout<<A[i]<<" ";

  return 0;
}
