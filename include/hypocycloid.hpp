//
//  hypocycloid.hpp
//  cpplab
//
//  Created by Артамонов Степан on 17.09.2021.
//

#ifndef HYPOCYCLOID_H
#define HYPOCYCLOID_H

#include <iostream>
#include <cmath>

class Hypocycloid {
private:
    float R, r, d;
public:
    Hypocycloid ();
    Hypocycloid (float R, float r, float d);
    float get_d ();
    float get_r ();
    float get_R ();
    void set_d (float d);
    void set_r (float r);
    void set_R (float R);
    float x (float phi);
    float y (float phi);
    float radius_of_curvature (float phi);
    float sector_area (float phi);
    int type();
};

#endif
