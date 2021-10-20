#include "../include/belt.h"

Belt::Belt() {
  belt = "";
}

Belt::Belt(string newString) {
  belt = newString;
}

string Belt::getBelt() {
  return belt;
}

int Belt::getPointer() {
  return pointer;
}

string Belt::getCurrent() {
  return string{belt[pointer]};
}

string Belt::getRemainer() {
  return belt.substr(pointer, belt.size() - pointer);
}


string Belt::nextChar() {
  return belt.substr(pointer++, 1);
}

void Belt::operator= (Belt newBelt) {
  belt = newBelt.getBelt();
  pointer = newBelt.getPointer();
}