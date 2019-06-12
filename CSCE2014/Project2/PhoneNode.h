/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PhoneNode.h
 * Author: board
 *
 * Created on February 5, 2018, 5:00 PM
 */

#ifndef PHONENODE_H
#define PHONENODE_H
#include <iostream>
using namespace std;

class PhoneNode {
public:
    // Constructors
    PhoneNode();
    PhoneNode(int id, string num, string own, string make);
    PhoneNode(const PhoneNode& orig);
    virtual ~PhoneNode();
    
    // Set Methods
    void setid(int id);
    void setphonenum(string num);
    void setowner(string own);
    void setmaker(string make);
    void setNext(PhoneNode *next);
    
    // Get Methods
    int getid();
    string getphonenum();
    string getowner();
    string getmaker();
    PhoneNode *getNext();
    
    // Other
    void printnode() const;
    PhoneNode *Next;
    
private:
    int ID;
    string phonenum;
    string owner;
    string maker;
};

#endif /* PHONENODE_H */

