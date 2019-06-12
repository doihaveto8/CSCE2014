/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PhoneList.cpp
 * Author: board
 * 
 * Created on February 5, 2018, 5:04 PM
 */

#include "PhoneList.h"

PhoneList::PhoneList() {
    Head = NULL;
}

PhoneList::PhoneList(const PhoneList& list) {
    PhoneNode *copy = new PhoneNode();
    Head = copy;
    
    PhoneNode *ptr = list.Head;
    while (ptr != NULL)
    {
        copy->setNext(new PhoneNode());
        copy = copy->getNext();
        copy->setphonenum(ptr->getphonenum());
        copy->setid(ptr->getid());
        copy->setmaker(ptr->getmaker());
        copy->setowner(ptr->getowner());
        copy->setNext(NULL);
        ptr = ptr->getNext();
    }
    
    copy = Head;
    Head = copy->getNext();
    delete copy;
}

PhoneList::~PhoneList() {
}

void PhoneList::insertHead(int ID, string phonenum, string owner, string maker)
{
    PhoneNode *ptr = new PhoneNode(ID, phonenum, owner, maker);
    ptr->setNext(Head);
    Head = ptr;
}

void PhoneList::insertTail(int ID, string phonenum, string owner, string maker)
{
    PhoneNode *ptr = Head;
    while ((ptr != NULL) && (ptr->getNext() != NULL))
        ptr = ptr->getNext();
    
    if (ptr != NULL)
        ptr->setNext(new PhoneNode(ID, phonenum, owner, maker));
    else
        Head = new PhoneNode(ID, phonenum, owner, maker);
    
}

void PhoneList::print() const
{
    PhoneNode *ptr = Head;
    while (ptr != NULL)
    {
        ptr->printnode();
        ptr = ptr->getNext();
    }
}

PhoneNode *PhoneList::searchID(int id)
{
    PhoneNode *ptr = Head;
    while ((ptr != NULL) && (ptr->getid() != id))
    {
        ptr = ptr->getNext();
    }
    if (ptr == NULL) {
        cout << "ID not found" << endl;
    }
    else {
        ptr->printnode();
    }
}

PhoneNode *PhoneList::del(int id)
{
    PhoneNode *prev = Head;
    PhoneNode *curr = Head;
    while ((curr != NULL) && (curr->getid() != id))
    {
        prev = curr;
        curr = curr->Next;
    }
    if (curr == NULL) {
        cout << "ID not found" << endl;
    }
    else if (curr == Head) {
        Head = curr->Next;
        cout << "ID: " << id << " deleted" << endl;
    }
    else {
        prev->Next = curr->Next;
        cout << "ID: " << id << " deleted" << endl;
    }
    delete curr;
    
}