//***** Tomas de Camino Beck
//***** tomasdecamino.com

//structure for pointers to functions
struct node {
  //pointer to action function, returns new state
  uint8_t (*actionDef)();//pointer to action function

};

//State Machine Objet

class TStateMachine {
  public:
    uint8_t currentState = 0; //state of thee machine
    node *nodeSet; //array where actions are stored
 
  //object constructor with n states 
  TStateMachine(uint8_t n) {
      nodeSet = new node[n];//creates the list of functions
    }

  //function to associate state and functions
  void add(uint8_t i,  uint8_t f()) {
      nodeSet[i].actionDef = f;
    }
  
   //function thata executes current state functions
   uint8_t execute() {
      currentState = nodeSet[currentState].actionDef();
      return currentState;
    }

};