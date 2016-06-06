//
//  point.cpp
//  convex_hull
//
//  Created by Vladimir Voinea on 12/20/15.
//  Copyright © 2015 Vladimir Voinea. All rights reserved.
//

#include "point.hpp"

double cross(const point &O, const point &A, const point &B) {
    
    return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}
