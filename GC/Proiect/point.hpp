//
//  point.hpp
//  convex_hull
//
//  Created by Vladimir Voinea on 12/20/15.
//  Copyright © 2015 Vladimir Voinea. All rights reserved.
//

#ifndef point_hpp
#define point_hpp

struct point {
    float x, y;
    point() = default;
    point(float x, float y) : x(x), y(y) {}
};
double cross(const point &O, const point &A, const point &B);

#endif /* point_hpp */
