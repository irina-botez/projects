//
//  convex_hull.cpp
//  convex_hull
//
//  Created by Vladimir Voinea & Irina Botez on 12/20/15.
//  Copyright © 2015 Vladimir Voinea. All rights reserved.
//

#include "convex_hull.hpp"

vector<point> acoperire_convexa(vector<point> P){
    int n = P.size(), k = 0;
    vector<point> H(2*n);
    
    sort(P.begin(), P.end(), [](const point& a, const point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    
    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    
    H.resize(k);
    return H;
}