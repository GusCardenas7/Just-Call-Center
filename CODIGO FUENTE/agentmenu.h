// Esta definicion es de la clase 'AgentMenu'
#ifndef AGENTMENU_H_INCLUDED
#define AGENTMENU_H_INCLUDED

#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>

#include "agent.h"
#include "agentlist.h"
#include "agentnode.h"
#include "name.h"
#include "schedule.h"
#include "time.h"
#include "clientlist.h"
#include "clientmenu.h"

class AgentMenu {
private:
  AgentList* agentListRef;

  void mainMenu();
  void showAgentList();
  void showAgentListFilteredBySpecialty();
  void addAgent();
  void searchAgent();
  void modifyAgent();
  void deleteAgent();
  void deleteAllAgents();
  void sortAgents();
  void writeToDisk();
  void readFromDisk();
  void enterToContinue();

public:
  AgentMenu(AgentList*);
};

#endif
