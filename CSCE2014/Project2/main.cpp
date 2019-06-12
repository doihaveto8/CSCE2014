/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: board
 *
 * Created on February 6, 2018, 10:13 PM
 */
#include "PhoneList.h"
#include "PhoneNode.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const int SIZE = 10;
    string firstname[SIZE] = { "Goku", "Sora", "Roxas", "Soap", "Mario", "Luigi",
                              "Zelda", "Edward", "Samus", "Ratchet" };
    string lastname[SIZE] = { "Mario", "Elric", "and Clank", "Metroid", "Link",
                            "Norris", "sucks", "Board", "Killmonger", "Stark"};
    string makers[SIZE] = { "Samsung", "Apple", "Huawei", "Oppo", "Vivo",
                          "OnePlus", "Xiaomi", "Lenovo", "LG", "Sony" };
    PhoneList list;
    
    const int COUNT = 100;
    cout << "Test" << endl;
    for (int i = 0; i < COUNT; i++)
    {
        int id = rand() % 1000;
        cout << "ID: " << id << endl;
        
        stringstream sout;
        sout << 100 + rand() % 900 << "-" << 100 + rand() % 900 << "-" << 1000 + rand() % 9000;
        string num = sout.str();
        cout << "Number: " << num << endl;
        
        string owner = firstname[rand() % 10] + " " + lastname[rand() % 10];
        cout << "Owner: " << owner << endl;
        
        int ran = rand() % 10;
        string maker = makers[ran];
        cout << "Maker: " << maker << endl;
        
        list.insertHead(id, num, owner, maker);
        
    }
    
    list.print();
    
    cout << "\nTesting Search\n";
    for (int count = 0; count < COUNT/5; count++)
    {
        int id = rand() % 1000;
        cout << "ID: " << id << endl;
        list.searchID(id);
    }
    
    cout << "\nTesting Delete\n";
    for (int count = 0; count < COUNT/5; count++)
    {
        int id = rand() % 1000;
        cout << "ID: " << id << endl;
        list.del(id);
    }
    
    cout << "\nFINAL PRINT\n" << endl;
    
    //These quoted out lines were just something i made to test my delete function
    //list.insertTail(9999, "999-999-9999", "SOMEONE ELSE", "TEST");
    //list.del(9999);
    
    list.print();
    
    
    return 0;
}

