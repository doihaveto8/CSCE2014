/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pokemon.cpp
 * Author: board
 * 
 * Created on January 23, 2018, 6:56 PM
 */

#include "Pokemon.h"

Pokemon::Pokemon() {
    name = "";
    type = "";
    maxhp = 0;
    hp = 0;
    attack = 0;
    defense = 0;
}

Pokemon::Pokemon(const Pokemon& orig) {
}

Pokemon::~Pokemon() {
}

void Pokemon::getattack(int &a) {
    a = attack;
}

void Pokemon::getdefense(int &d) {
    d = defense;
}

void Pokemon::gethp(int &h) {
    h = hp;
}

void Pokemon::getname(string &n) {
    n = name;
}

void Pokemon::gettype(string &t) {
    t = type;
}

void Pokemon::getall(string &n, string &t, int &h, int &a, int &d) {
    getname(n);
    gettype(t);
    gethp(h);
    getattack(a);
    getdefense(d);
}

void Pokemon::setattack(int a) {
    attack = a;
}

void Pokemon::setdefense(int d) {
    defense = d;
}

void Pokemon::sethp(int h) {
    hp = h;
}

void Pokemon::setmaxhp(int mh) {
    maxhp = mh;
}

void Pokemon::setname(string n) {
    name = n;
}

void Pokemon::settype(string t) {
    type = t;
}

void Pokemon::setall(string n, string t, int h, int a, int d) {
    setname(n);
    settype(t);
    setmaxhp(h);
    sethp(h);
    setattack(a);
    setdefense(d);
}

void Pokemon::print() {
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "HP: " << hp << endl;
    cout << "ATK: " << attack << endl;
    cout << "DEF: " << defense << endl;
}

void Pokemon::heal() {
    int newhp = hp + 10;
    int healed;
    if (newhp > maxhp)
    {
        hp = maxhp;
        healed = 10 - (newhp - maxhp);
    }
    else
    {
        hp = newhp;
        healed = 10;
    }
    
    cout << name << " healed " << healed << " HP!" << endl;
}

void Pokemon::damage(int atk) {
    int damage = atk - defense;
    if (hp <= damage) {
        hp = 0;
        cout << name << " has fainted!" << endl;
    }
    else
    {
        hp = hp - damage;
        cout << name << "has lost " << damage << " HP!" << endl;
    }
    
}

void Pokemon::atkup() {
    attack = attack + 2;
}