#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Belt {
  private:
    string belt;
    int pointer = 0;
    
  public:
    Belt();
    Belt(string);
    string getBelt();
    int getPointer();
    string getCurrent();
    string getRemainer();
    string nextChar();
    void operator=(Belt);
};