#include <iostream>

#include <stack> 
#include <vector>
#include <string>
#include <set>

#include "../include/readfile.h"
#include "../include/belt.h"
#include "../include/state.h"
#include "../include/transition.h"
#include "../include/graph.h"

using namespace std;


int main() {
  Graph g1(readFile("APf"));
  string belt;


  cout << "Write the conveyor belt you want to test: ";
  cin >> belt;
  g1.setConveyorBelt(belt);
  g1.algorithm() ? 
    cout << "¡Cadena aceptada!" << endl :
    cout << "Cadena no aceptada..." << endl;
  cout << endl;
}

