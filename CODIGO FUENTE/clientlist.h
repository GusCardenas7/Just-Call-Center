// Esta definicion es de la clase 'ClientList'
#ifndef CLIENTLIST_H_INCLUDED
#define CLIENTLIST_H_INCLUDED

#include <string>
#include <fstream>

#include "clientnode.h"
#include "listexception.h"

class ClientList {
private:
  ClientNode* anchor;

  bool isValidPos(ClientNode*);
  void copyAll(const ClientList&);

public:
  ClientList();
  ClientList(const ClientList&);
  ~ClientList();

  bool isEmpty();
  void insertData(ClientNode*, const Client&);
  void insertOrderedByAttentionTime(const Client&);
  void deleteData(ClientNode*);

  ClientNode* getFirstPos();
  ClientNode* getLastPos();
  ClientNode* getPrevPos(ClientNode*);
  ClientNode* getNextPos(ClientNode*);
  ClientNode* findData(const Client&);
  ClientNode* findDataByAttentionTime(const Client&);
  Client retrieve(ClientNode*);

  std::string toString() const;

  void deleteAll();
  void writeToDisk(const std::string&);
  void readFromDisk(const std::string&);

  ClientList& operator = (const ClientList&);
};

#endif
