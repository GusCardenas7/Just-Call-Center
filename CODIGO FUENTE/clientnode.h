// Esta definicion es de la clase 'ClientNode'
#ifndef CLIENTNODE_H_INCLUDED
#define CLIENTNODE_H_INCLUDED

#include "client.h"

class ClientNode {
private:
  Client data;
  ClientNode* next;

public:
  ClientNode();
  ClientNode(const Client&);

  Client getData() const;
  ClientNode* getNext();

  void setData(const Client&);
  void setNext(ClientNode*);
};

#endif
