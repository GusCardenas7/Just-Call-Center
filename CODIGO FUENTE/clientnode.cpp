// Esta es la implementacion de la clase 'ClientNode'
#include "clientnode.h"

using namespace std;

// Constructor base
ClientNode::ClientNode() : next(nullptr) { }

// Constructor parametrizado
ClientNode::ClientNode(const Client& e) : data(e), next(nullptr) { }

// getter que obtiene el dato de un nodo
Client ClientNode::getData() const {
  return data;
  }

// getter que obtiene el apuntador hacia el siguiente nodo
ClientNode* ClientNode::getNext() {
  return next;
  }

// setter que le asigna el elemento a un nodo
void ClientNode::setData(const Client& e) {
  data = e;
  }

// setter que le asigna un apuntador a un nodo
void ClientNode::setNext(ClientNode* p) {
  next = p;
  }
