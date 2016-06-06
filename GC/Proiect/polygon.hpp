//
//  line.hpp
//  convex_hull
//
//  Created by Vladimir Voinea on 12/20/15.
//  Copyright © 2015 Vladimir Voinea. All rights reserved.
//

#ifndef line_hpp
#define line_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include "point.hpp"

struct polygon {
    sf::VertexArray vertices;
    
    polygon(const std::vector<point>& points) : vertices(sf::LinesStrip, points.size()) {
        for(auto index = 0u; index < points.size(); ++index) {
            vertices[index].position = sf::Vector2f(points[index].x, points[index].y);
            vertices[index].color = sf::Color::Cyan;
        }
    }
    
};

#endif /* line_hpp */
