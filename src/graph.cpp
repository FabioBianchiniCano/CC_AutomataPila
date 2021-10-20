#include "../include/graph.h"


Graph::Graph() {}

Graph::Graph(InfoAutomaton infoAut) {
  acceptStatesNames = infoAut.acceptanceStates;
  for (unsigned int i = 0; i < infoAut.statesSet.size(); i++) {
    if (find( acceptStatesNames.begin(), acceptStatesNames.end(),
    infoAut.statesSet[i]) != acceptStatesNames.end())
      states.push_back(State(infoAut.statesSet[i], true));
    else states.push_back(State (infoAut.statesSet[i]));
  }
  
  initialState = infoAut.initialState;
  alphabetBelt = infoAut.conveyorAlph;
  alphabetStack = infoAut.stackAlph;
  graphStack.push(infoAut.initialStack);

  for (auto trans: infoAut.transitions) 
    for (unsigned int i = 0; i < states.size(); i++) 
      if (states[i].getName() == trans[0]) {
        states[i].addTransition(Transition (trans[1], trans[2], vector<string> (trans.begin() + 4, trans.end()), trans[3]));
        break;
      }

  for (auto state: states) 
    if (infoAut.initialState == state.getName())
      initialState = state;

}

Graph::Graph(vector<State> S, vector<string> ASN, vector<string> AB, vector<string> AS, stack<string> GS, Belt CB) {
  states = S;
  acceptStatesNames = ASN;
  alphabetBelt = AB;
  alphabetStack = AS;
  graphStack = GS;
  conveyorBelt = CB;
}

vector<State> Graph::getStates() {
  return states;
}
vector<string> Graph::getAcceptStatesNames() {
  return acceptStatesNames;
}
vector<string> Graph::getAlphabetBelt() {
  return alphabetBelt;
}
vector<string> Graph::getAlphabetStack() {
  return alphabetStack;
}
stack<string> Graph::getGraphStack() {
  return graphStack;
}
State Graph::getInitialState() {
  return initialState;
}
Belt Graph::getConveyorBelt() {
  return conveyorBelt;
}
void Graph::setConveyorBelt(Belt cb) {
  conveyorBelt = cb;
}

void Graph:: doTransition(Transition tr) {
  if (tr.getCharBelt() != ".") conveyorBelt.nextChar();
  graphStack.pop();
  if (tr.getInsertCharsStack()[0] != ".")
    for (int i = tr.getInsertCharsStack().size()-1; i >= 0; i--)
      graphStack.push(tr.getInsertCharsStack()[i]);
  for (auto state: states)
    if (state.getName() == tr.getIdStateTo())
      currentState = state;
  
}

bool Graph::algorithm() {
  currentState = initialState;
  while ((conveyorBelt.getPointer() < conveyorBelt.getBelt().size()) && 
        !graphStack.empty()) {
    for (auto tr: currentState.getTransitions()) {
      if (conveyorBelt.getCurrent() == tr.getCharBelt() && 
      graphStack.top() == tr.getCharStack()) {
        doTransition(tr);
        writeTransition(tr);
      }
    }

  }
  cout << endl;
  return currentState.isAcceptance() ? true : false;
}

/* a escribir */
void Graph::writeTransition(Transition tr) {
  cout << "Estado: " << currentState.getName() << endl;
  cout << "Transición: " << tr;
  cout << "-----------------------\nDescripción instantánea:" << endl;
  cout << "Cinta: " << conveyorBelt.getRemainer() << endl;
  cout << "Pila: " << "mirmanaso" << endl;
  cout << endl;
}