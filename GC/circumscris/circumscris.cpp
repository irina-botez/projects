#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

struct Punct
{
    double x,y;
} A,B,C,D;

#define PI 3.14159265

double lung(Punct A,Punct B)
{
    return sqrt( pow(B.x-A.x,2) + pow(B.y-A.y,2) );
}

int main()
{
    cout<<"\nCoordonatele punctului A: "; cin>>A.x>>A.y;
    cout<<"\nCoordonatele punctului B: "; cin>>B.x>>B.y;
    cout<<"\nCoordonatele punctului C: "; cin>>C.x>>C.y;
    cout<<"\nCoordonatele punctului D: "; cin>>D.x>>D.y;


    Punct BA,BC,DA,DC;

    BA.x=A.x-B.x; BA.y=A.y-B.y;
    BC.x=C.x-B.x; BC.y=C.y-B.y;

    DA.x=A.x-D.x; DA.y=A.y-D.y;
    DC.x=C.x-D.x; DC.y=C.y-D.y;


    double cosb,cosd,arcb,arcd;

    cosb=(BA.x*BC.x+BA.y*BC.y) / ( lung(B,A)* lung(B,C) );
    cosd=(DA.x*DC.x+DA.y*DC.y) / ( lung(D,A)* lung(D,C) );

    arcb=(acos(cosb)*180)/PI;
    arcd=(acos(cosd)*180)/PI;

    cout<<arcb+arcd;


    double s=arcb+arcd;

    if(abs(s-180)<0.001) cout<<"\nPunctul D se afla PE cercul circumscris triunghiului ABC\n\n";
        else if(arcb+arcd<180) cout<<"\nPunctul D se afla in EXTERIOR cercului circumscris triunghiului ABC\n\n";
            else cout<<"\nPunctul D se afla in INTERIOR cercului circumscris triunghiului ABC\n\n";


 if( lung(A,B)+lung(C,D) == lung(A,D)+lung(B,C) ) cout<<"\nPatrulaterul este circumscrisibil";
    else cout<<"\nPatrulaterul NU este circumscrisibil\n\n\n";




    return 0;
}
