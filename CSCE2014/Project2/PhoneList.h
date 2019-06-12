/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PhoneList.h
 * Author: board
 *
 * Created on February 5, 2018, 5:04 PM
 */

#ifndef PHONELIST_H
#define PHONELIST_H
#include "PhoneNode.h"
#include <time.h>
#include <iostream>
using namespace std;

class PhoneList {
public:
    PhoneList();
    PhoneList(const PhoneList& list);
    virtual ~PhoneList();
    
    void insertHead(int ID, string phonenum, string owner, string maker);
    void insertTail(int ID, string phonenum, string owner, string maker);
    void print() const;
    PhoneNode *searchID(int id);
    PhoneNode *del(int id);
    
private:
    PhoneNode * Head;
};

#endif /* PHONELIST_H */

