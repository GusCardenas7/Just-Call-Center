// Esta es la implementacion de la clase 'AgentNode'
#include "agentnode.h"

using namespace std;

// Constructor base inicializando los 3 apuntadores con nullptr
AgentNode::AgentNode() : dataPtr(nullptr), prev(nullptr), next(nullptr) { }

// Constructor parametrizado con delegaciones de constructores
AgentNode::AgentNode(const Agent& e) : dataPtr(new Agent(e)), prev(nullptr), next(nullptr) {
  if(dataPtr == nullptr) {
    throw AgentNodeException("Memoria no disponible, creando AgentNode");
    }
  }

// Destructor
AgentNode::~AgentNode() {
  delete dataPtr;
  }

// getter que obtiene el apuntador
Agent* AgentNode::getDataPtr() {
  return dataPtr;
  }

// getter que obtiene el dato que hay detras del apuntador
Agent AgentNode::getData() const {
  if(dataPtr == nullptr) {
    throw AgentNodeException("Error, el dato que desea obtener no existe, getData");
    }

  return *dataPtr;
  }

// getter que obtiene el apuntador prev
AgentNode* AgentNode::getPrev() {
  return prev;
  }

// getter que obtiene el apuntador next
AgentNode* AgentNode::getNext() {
  return next;
  }

// setter que le asigna un apuntador al dato
void AgentNode::setDataPtr(Agent* p) {
  dataPtr = p;
  }

// setter que le asigna el dato que estamos recibiendo al agente mismo
void AgentNode::setData(const Agent& e) {
  delete dataPtr;

  dataPtr = new Agent(e);

  if(dataPtr == nullptr) {
    throw AgentNodeException("Memoria no disponible, setData");
    }
  }

// setter que le asigna un apuntador a prev
void AgentNode::setPrev(AgentNode* p) {
  prev = p;
  }

// setter que le asigna un apuntador a next
void AgentNode::setNext(AgentNode* p) {
  next = p;
  }
