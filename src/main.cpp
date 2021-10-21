#include <iostream>

#include <stack> 
#include <vector>
#include <string>
#include <set>
#include <sstream>

#include "../include/readfile.h"
#include "../include/belt.h"
#include "../include/state.h"
#include "../include/transition.h"
#include "../include/graph.h"

using namespace std;

void usage() {
  cout << "--------------------------------------------------------------------------------" << endl;
  cout << "\tUsage" << endl;
  cout << "\t./automata writeMode nameFile" << endl;
  cout << "\tBoth are mandatory arguments" << endl;
  cout << "\twriteMode -> 1: enabled, 2: disabled" << endl;
  cout << "\tIs not necesary to put the extension in the file name passed" << endl;
  cout << "--------------------------------------------------------------------------------" << endl;
}


int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Incorrect number of arguments" << endl;
    usage();
    cout << "Exiting..." << endl;
    exit(1);
  } 

  Graph g1(readFile(argv[2]));
  bool otherBelt = false;
  string belt;

  do {

  cout << "Write the conveyor belt you want to test: ";
  cin >> belt;
  g1.setConveyorBelt(belt);

  bool writeMode;
  istringstream(argv[1]) >> writeMode;

  g1.algorithm(g1.getConveyorBelt(), g1.getGraphStack(), g1.getInitialState(), writeMode) ? 
    cout << "String accepted!" << endl :
    cout << "String not accepted..." << endl;
  cout << endl;
  cout << "Do you want to test another string? (1->yes):  ";
  cin >> otherBelt;

  } while (otherBelt);
  cout << "Bye!" << endl; 
}

