// Esta definicion es de la clase 'ClientMenu'
#ifndef CLIENTMENU_H_INCLUDED
#define CLIENTMENU_H_INCLUDED

#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>

#include "client.h"
#include "clientlist.h"
#include "clientnode.h"
#include "name.h"
#include "time.h"

class ClientMenu {
private:
  ClientList* clientListRef;

  void mainMenu();
  void addClient();
  void deleteClient();
  void deleteAllClients();
  void modifyCallDurationOfAClient();
  void showClientList();
  void enterToContinue();

public:
  ClientMenu(ClientList*);
};

#endif
