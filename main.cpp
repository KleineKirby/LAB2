//
//  main.cpp
//  cpplab
//
//  Created by Артамонов Степан on 17.09.2021.
//

#include <iostream>
#include <cmath>
#include "hypocycloid.hpp"
#include <string>


void process_command(std::string& command, Hypocycloid& hypocycloid) {

    float phi;
    float R,r,d;


    if (command ==  "get_R") {
        std::cout << "R = " << hypocycloid.get_R() <<"\n";
    } else if (command ==  "get_r") {
        std::cout << "r = " << hypocycloid.get_r() <<"\n";
    } else if (command ==  "get_d") {
        std::cout << "d = " << hypocycloid.get_d() <<"\n";
    } else if (command ==  "set_R") {
        std::cin >> R;
        hypocycloid.set_R(R);
    } else if (command ==  "set_r") {
        std::cin >> r;
        hypocycloid.set_r(r);
    } else if (command ==  "set_d") {
        std::cin >> d;
        hypocycloid.set_d(d);
    } else if (command ==  "curr") {
        std::cin >> phi;
        std::cout << "curr = " << hypocycloid.radius_of_curvature (phi) << "\n";
    } else if (command ==  "xpoint") {
        std::cin >> phi;
        std::cout << "x = " << hypocycloid.x (phi) << "\n";
    } else if (command ==  "ypoint") {
        std::cin >> phi;
        std::cout << "y = " << hypocycloid.y (phi) << "\n";
    } else if (command ==  "sector") {
        std::cin >> phi;
        std::cout << "sector priz = " << hypocycloid.sector_area(phi) << "\n";
    } else if (command ==  "type") {
        std::cout << "type:  " << hypocycloid.type () << "\n";
    } else if (command ==  "help"){
        std::cout <<  "Supported commands: \n"
                "get_R/r/d : get the value \n"
                "set_R/r/d : set the value \n"
                "curr      : returns the radius of curvature \n"
                "xpoint/ypoint : returns the coordinates of the point belonging to the hypocycloid\n"
                "sector : returns the sectorial area of the hypocycloid\n"
                "type : type of hypocycloid \n";
    } else std::cout << "Syntax error: no such command.\n";

}

int main () {
    //Hypocycloid hypocycloid(10, 3, 2);
    Hypocycloid hypocycloid(12, 4, 5);
    std::string command;
    int working = 1;

    while (working) {
        std::cout <<  ">> ";
        std::cin >> command;
        if (command == "exit") working = 0;
        else process_command(command, hypocycloid);
    }
    return 0;
}
