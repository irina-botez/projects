#include <iostream>

using namespace std;

struct punct
{
    float x,y;
}A,B,C,D;

/*int secante(punct A,punct B,punct C,punct D)
{
     return 1;
    return 0;
}*/



int main()
{
    cout<<"\nCoordonatele punctului A: "; cin>>A.x>>A.y;
    cout<<"\nCoordonatele punctului B: "; cin>>B.x>>B.y;
    cout<<"\nCoordonatele punctului C: "; cin>>C.x>>C.y;
    cout<<"\nCoordonatele punctului D: "; cin>>D.x>>D.y;

    float a1,a2,b1,b2,c1,c2,X,Y;

    a1=A.y-B.y;
    b1=B.x-A.x;
    c1=(A.x*B.y)-(B.x*A.y);

    a2=C.y-D.y;
    b2=D.x-C.x;
    c2=(C.x*D.y)-(D.x*C.y);

    if( ((a1*b2)-(b1*a2)) != 0 )
      {
        X=((-c1*b2)-(b1*-c2))/((a1*b2)-(b1*a2));
        Y=((a1*-c2)-(-c1*a2))/((a1*b2)-(b1*a2));
        if(X>=C.x && X<=D.x && X>=A.x && X<=B.x)
        cout<<"\nSegmentele sunt secante! Coordonatele intersectiei sunt: X="<<X<<" si Y="<<Y;
        else cout<<"Intersectia este multimea vida!";
      }

    else
      {
        if( (a1*b2-b1*a2)==0 && (a1*c2-a2*c1)==0 && (b1*c2-c1*b2)==0 )
        {
            cout<<"\nAB=CD!";
            if( (D.x<A.x && D.x<B.x && C.x<A.x && C.x<B.x) || (A.x<C.x && A.x<D.x && B.x<C.x && B.x<D.x) )
                cout<<" Intersectia lor este multimea vida!";

            else if( (C.x>=A.x && C.x<=B.x && D.x>=A.x && D.x<=B.x) )
                   cout<<" Intersectia lor este segmentul CD cu coordonatele C("<<C.x<<","<<C.y<<") si D("<<D.x<<","<<D.y<<")";

                   else if( (A.x>=C.x && A.x<=D.x && B.x>=C.x && B.x<=D.x) )
                    cout<<" Intersectia lor este segmentul AB cu coordonatele A("<<A.x<<","<<A.y<<") si B("<<B.x<<","<<B.y<<")";

            else if (C.x>=A.x && C.x<=B.x && D.x>=A.x && D.x>=B.x)
                     cout<<" Intersectia lor este segmentul CB cu coordonatele C("<<C.x<<","<<C.y<<") si B("<<B.x<<","<<B.y<<")";
            else if (A.x>=C.x && A.x<=D.x && B.x>=C.x && B.x>=D.x)
                     cout<<" Intersectia lor este segmentul AD cu coordonatele A("<<A.x<<","<<A.y<<") si D("<<D.x<<","<<D.y<<")";

        }

        else
        {
            cout<<"AB||CD! Intersectia lor este multimea vida.";
        }
      }

    return 0;
}
