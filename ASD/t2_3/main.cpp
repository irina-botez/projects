#include <iostream>

using namespace std;

 void Traversare(int A[100],int k,int n)
 { int mn,mx,poz=1;
     mn=mx=A[1];
     while(k<=n)
     { if(A[k]>mx) mx=A[k];
       if(A[k]<mn) { mn=A[k];
                     poz=k;
                     }
        k++;
     }
     cout<<"maximul="<<mx<<endl;
     cout<<"pozitia minimului="<<poz;

 }

int main()
{
  int n,A[100],k;
  cin>>n;
  for(k=1;k<=n;k++) cin>>A[k];
  Traversare(A,1,n);
    return 0;
}
