// Esta definicion es de la clase 'AgentList'
#ifndef AGENTLIST_H_INCLUDED
#define AGENTLIST_H_INCLUDED

#include <string>
#include <fstream>

#include "agent.h"
#include "agentnode.h"

class AgentList {
private:
  AgentNode* header;

  bool isValidPos(AgentNode*);
  void copyAll(const AgentList&);
  void swapPtr(AgentNode*, AgentNode*);
  void sortByName(AgentNode*, AgentNode*);
  void sortBySpecialty(AgentNode*, AgentNode*);

public:
  AgentList();
  AgentList(const AgentList&);
  ~AgentList();

  bool isEmpty();
  void insertData(AgentNode*, const Agent&);
  void deleteData(AgentNode*);

  AgentNode* getFirstPos();
  AgentNode* getLastPos();
  AgentNode* getPrevPos(AgentNode*);
  AgentNode* getNextPos(AgentNode*);
  AgentNode* findData(const Agent&);
  Agent retrieve(AgentNode*);

  void sortByName();
  void sortBySpecialty();

  std::string toString(const bool&);
  std::string filterList(const bool&, const Agent&);

  void deleteAll();
  void writeToDisk(const std::string&);
  void readFromDisk(const std::string&);

  AgentList& operator = (const AgentList&);
};

#endif
