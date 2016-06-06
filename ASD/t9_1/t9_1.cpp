#include <fstream>
#include <iostream>

using namespace std;
ifstream f("matrice.txt");
int a[100][100],n;

int grad(int x)
{
    int s=0,i;
    for(i=1;i<=n;i++) s+=a[x][i];
    return s;

}

int NumarMuchii()
{
    int nr=0,i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) nr+=a[i][j];
    return nr/2;
}

void GradMax()
{
    int max=0,i;
    for(i=1;i<=n;i++) if(grad(i)>max) max=grad(i);
    cout<<endl<<endl<<"Nodurile de grad maxim sunt: ";
    for(i=1;i<=n;i++)
        if(grad(i)==max) cout<<i<<" ";
}

int main()
{
  int i,j,x;
  f>>n;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++) f>>a[i][j];
    cout<<"Carui nod doriti sa ii aflati gradul? "; cin>>x;
    cout<<"Gradul nodului "<<x<<" este: "<<grad(x);
    cout<<endl<<endl<<"Nr total de muchii din graf este: "<<NumarMuchii();
    GradMax();
    return 0;
}
