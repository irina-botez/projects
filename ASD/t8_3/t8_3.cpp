#include <iostream>
#include<fstream>

using namespace std;
ifstream f("input.txt");

int main()
{
   int n,k,b[100],i,c;
   f>>n>>k;
   for(i=1;i<=k;i++) f>>b[i];
   i=1;
   while(n!=0&&i<=k)
   {
      if(i>1) cout<<" + ";
       c=0;
     if(n/b[i]!=0 || n%b[i]==0)
     {
         c=n/b[i];
         n%=b[i];
     }
    cout<<c<<" X "<<"b"<<i;
        i++;
   }

    return 0;
}
