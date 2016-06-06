#include <iostream>

using namespace std;

int main()
{
    float x1,y1,z1,x2,y2,z2,x3,y3,z3;
    float a,b;
    int sw=1;

    cout<<"Coordonate A:"; cin>>x1>>y1>>z1;
    cout<<"Coordonate B:"; cin>>x2>>y2>>z2;
    cout<<"Coordonate C:"; cin>>x3>>y3>>z3;

    if( x1==x3 && y1==y3 && z1==z3)
        cout<<"A=C, A=1*C+0*B";
    else
    {
        float xcb,ycb,zcb,xca,yca,zca;
        xcb=x2-x3; ycb=y2-y3; zcb=z2-z3;
        xca=x1-x3; yca=y1-y3; zca=z1-z3;
        if(xcb!=0 && xca!=0)
            { a=xcb/xca;
              if(yca*a!=ycb || zca*a!=zcb)
              { sw=0; cout<<"Nu sunt coliniari!"; }
            }
        else if(ycb!=0 && yca!=0)
           {  a=float(ycb/yca);
              if(xca*a!=xcb || zca*a!=zcb)
              { sw=0; cout<<"Nu sunt coliniari!"; }}
        else if(zcb!=0 && zca!=0)
            { a=float(zcb/zca);
              if(yca*a!=ycb || xca*a!=xcb)
              { sw=0; cout<<"Nu sunt coliniari!"; }}

        if(sw==1)
            {
                b=1-a;
                if(b>0)
                    cout<<"B="<<a<<"*A+"<<b<<"*C";
                else
                    cout<<"B="<<a<<"*A"<<b<<"*C";
            }
        }
    return 0;
}
