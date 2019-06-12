/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pokemon.h
 * Author: board
 *
 * Created on January 23, 2018, 6:56 PM
 */

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
using namespace std;

class Pokemon {
public:
    Pokemon();
    Pokemon(const Pokemon& orig);
    virtual ~Pokemon();
    void getattack(int &a);
    void getdefense(int &d);
    void gethp(int &h);
    void gettype(string &t);
    void getname(string &n);
    void getall(string &n, string &t, int &h, int &a, int &d);
    void setattack(int a);
    void setdefense(int d);
    void setmaxhp(int mh);
    void sethp(int h);
    void settype(string t);
    void setname(string n);
    void setall(string n, string t, int h, int a, int d);
    void print();
    void heal();
    void damage(int atk);
    void atkup();
private:
    int attack;
    int defense;
    int maxhp;
    int hp;
    string type;
    string name;

};

#endif /* POKEMON_H */

