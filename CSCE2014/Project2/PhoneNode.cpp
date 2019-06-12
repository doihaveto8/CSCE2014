/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PhoneNode.cpp
 * Author: board
 * 
 * Created on February 5, 2018, 5:00 PM
 */

#include "PhoneNode.h"

PhoneNode::PhoneNode() {
    ID = 0;
    phonenum = "";
    owner = "";
    maker = "";
    Next = NULL;
}

PhoneNode::PhoneNode(int id, string num, string own, string make) {
    ID = id;
    phonenum = num;
    owner = own;
    maker = make;
    Next = NULL;
}

PhoneNode::PhoneNode(const PhoneNode& orig) {
    ID = orig.ID;
    phonenum = orig.phonenum;
    owner = orig.owner;
    maker = orig.maker;
    Next = orig.Next;
}

PhoneNode::~PhoneNode() {
}

void PhoneNode::setid(int id) {
    ID = id;
}

void PhoneNode::setphonenum(string num) {
    phonenum = num;
}

void PhoneNode::setowner(string own) {
    owner = own;
}

void PhoneNode::setmaker(string make) {
    maker = make;
}

void PhoneNode::setNext(PhoneNode *next) {
    Next = next;
}

int PhoneNode::getid() {
    return ID;
}

string PhoneNode::getphonenum() {
    return phonenum;
}

string PhoneNode::getmaker() {
    return maker;
}

string PhoneNode::getowner() {
    return owner;
}

PhoneNode *PhoneNode::getNext() {
    return Next;
}

void PhoneNode::printnode() const {
    cout << "ID: " << ID << endl;
    cout << "Owner: " << owner << endl;
    cout << "Phone #: " << phonenum << endl;
    cout << "Maker: " << maker << endl;
}
