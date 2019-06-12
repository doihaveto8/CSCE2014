/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: board
 *
 * Created on January 23, 2018, 6:43 PM
 */

#include <cstdlib>
#include "Pokemon.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string n;
    string t;
    int mh;
    int h;
    int a;
    int d;
    int c;
    
    Pokemon p[10];
    
    p[0].setall("Pikachu", "ELECTRIC", 52, 16, 9);
    p[1].setall("Blastoise", "WATER", 78, 25, 26);
    p[2].setall("Charizard", "FIRE", 64, 37, 19);
    p[3].setall("Venusaur", "GRASS", 92, 18, 34);
    p[4].setall("Onyx", "ROCK", 64, 19, 28);
    p[5].setall("Pidgeot", "FLYING", 54, 42, 16);
    p[6].setall("Snorlax", "NORMAL", 152, 18, 32);
    p[7].setall("Machamp", "FIGHTING", 75, 54, 19);
    p[8].setall("Alakazam", "PSYCHIC", 67, 32, 21);
    p[9].setall("Sandslash", "GROUND", 74, 23, 23);
    
    for (c = 0, c < 10, c++)
    {
        p[c].print();
    }
    return 0;
}

