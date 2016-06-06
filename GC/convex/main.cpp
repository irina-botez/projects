#include <iostream>


using namespace std;

struct Punct
{
    int x,y;
} A,B,C,D,M;

int ecuatie (Punct A,Punct B,Punct Z)
{

 return Z.x*A.y+Z.y*B.x+A.x*B.y-B.x*A.y-Z.x*B.y-A.x*Z.y;

}

float arie (Punct A,Punct B,Punct C)
{
    int x=A.x*B.y+C.x*A.y+B.x*C.y-C.x*B.y-A.x*C.y-B.x*A.y;

    if(x>0) return 0.5*x;
    else return -0.5*x;
}

int main()
{
    int ok=0;

    cout<<"\nCoordonatele punctului A: "; cin>>A.x>>A.y;
    cout<<"\nCoordonatele punctului B: "; cin>>B.x>>B.y;
    cout<<"\nCoordonatele punctului C: "; cin>>C.x>>C.y;
    cout<<"\nCoordonatele punctului D: "; cin>>D.x>>D.y;

    if(ecuatie(A,B,C)*ecuatie(A,B,D)>0 && ecuatie(B,C,D)*ecuatie(B,C,A)>0 && ecuatie(C,D,B)*ecuatie(C,D,A)>0 && ecuatie(D,A,B)*ecuatie(D,A,C)>0) cout<<"\n\nPoligonul este CONVEX!";
    else cout<<"\n\nPoligonul este CONCAV!";

    cout<<"\nCoordonatele punctului M: "; cin>>M.x>>M.y;

    if(arie(A,B,C)==arie(A,B,M)+arie(A,M,C)+arie(M,C,B)  ||  arie(A,C,D)==arie(A,C,M)+arie(M,C,D)+arie(A,M,D)) cout<<"\n\nM se afla in acoperirea convexa a multimii {A,B,C,D}";
    else cout<<"\n\nM nu se afla in acoperirea convexa";

    return 0;
}
