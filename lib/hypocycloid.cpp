//
//  hypocycloid.cpp
//  cpplab
//
//  Created by Артамонов Степан on 17.09.2021.
//

#include "hypocycloid.hpp"

Hypocycloid::Hypocycloid (float R, float r, float d) {
    this->R = R;
    this->r = r;
    this->d = d;
}

Hypocycloid::Hypocycloid () {
    this->R = 0;
    this->r = 0;
    this->d = 0;
}

float Hypocycloid::get_r () {return this->r;}
float Hypocycloid::get_d () {return this->d;}
float Hypocycloid::get_R () {return this->R;}
void Hypocycloid::set_r (float r) {if (r <= this->R) this->r = r;}
void Hypocycloid::set_d (float d) {this->d = d;}
void Hypocycloid::set_R (float R) {if (R >= this->r) this->R = R;}

float Hypocycloid::x (float phi) {
    return (this->R - this->r) * std::cos(phi) + this->d * std::cos((this->R - this->r) * phi / this->r);
}
float Hypocycloid::y (float phi) {
    return (this->R - this->r) * std::sin(phi) - this->d * std::sin((this->R - this->r) * phi / this->r);
}

float Hypocycloid::radius_of_curvature (float phi) {
    float dx = (this->r - this->R) * (std::sin(phi) + ( this->d / this->r ) * std::sin((this->R - this->r) * phi / this->r));
    float dy = (this->R - this->r) * (std::cos(phi) - ( this->d / this->r ) * std::cos((this->R - this->r) * phi / this->r));

    float ddx = (this->r - this->R) * (std::cos(phi) + ( this->d / this->r ) * std::cos((this->R - this->r) * phi / this->r) * (this->R - this->r) / this->r);
    float ddy = (this->r - this->R) * (std::sin(phi) - ( this->d / this->r ) * std::sin((this->R - this->r) * phi / this->r) * (this->R - this->r) / this->r);

    float pv = std::fabs(dx * ddy - ddx * dy);

    float speed = std::sqrt(dx * dx + dy * dy);

    return speed * speed * speed / pv;
}

float Hypocycloid::sector_area (float phi) {
    return 0.5 * (this->R - this->r) * (this->R - this->r) * phi +
        0.5 * this->d * this->d * phi + (this->R - this->r) * this->r * this->d *
        std::sin(this->R * phi /  this->r) / this->R;
}


int Hypocycloid::type() {
    if (this->d > this->r) return 1;
    if (this->d < this->r) return -1;
    return 0;
}
