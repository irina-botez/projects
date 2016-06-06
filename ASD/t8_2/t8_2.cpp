#include <iostream>

using namespace std;

void shell(int a[],int l,int r)
{  int i,j,h,v,k;
   int increments[16]={1391376, 463792, 198768, 86961, 33936,13776, 4592, 1968, 861, 336,112, 48, 21, 7, 3, 1};
   for (k = 0; k < 16; k++)
for (h = increments[k], i = l+h; i <= r; i++) {
v = a[i]; j = i;
while (j > h && a[j-h] > v) {
a[j] = a[j-h]; j = j-h;
}
a[j] = v;
}


}

int main()
{
 int n,a[100],i;
 cin>>n;
 for(i=1;i<=n;i++) cin>>a[i];
 shell(a,1,n);
 for(i=1;i<=n;i++) cout<<a[i]<<" ";     return 0;
}
