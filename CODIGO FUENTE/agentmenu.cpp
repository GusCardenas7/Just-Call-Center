// Esta es la implementacion de la clase 'AgentMenu'
#include "agentmenu.h"

using namespace std;

// Constructor parametrizado
AgentMenu::AgentMenu(AgentList* p) : agentListRef(p) {
  mainMenu();
  }

// Metodo que muestra la pantalla splash y el menu de opciones para los agentes
void AgentMenu::mainMenu() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  int option;
  Name myUserName;
  string myStr;

  cout << "JUST CALL CENTER" << endl << endl;

  cout << "© 2021 CARDENAS Systems" << endl << endl;

  cout << "Por favor, ingrese su nombre (AA, NN): ";
  getline(cin, myStr, ',');
  myUserName.setLastName(myStr);
  getline(cin, myStr);
  myUserName.setFirstName(myStr);

  cout << endl;

  cout << "Nombre capturado" << endl;
  cout << "Entrando al sistema..." << endl << endl;
  enterToContinue();

  do {
    system("cls");
    cout << "JUST CALL CENTER" << endl << endl;

    cout << "Bienvenid@ de nuevo " << myUserName << endl << endl;

    cout << "MENU DE AGENTES" << endl << endl;

    cout << "1.-Mostrar toda la lista de agentes almacenados" << endl;
    cout << "2.-Mostrar la lista de agentes almacenados filtrados por especialidad" << endl;
    cout << "3.-Agregar un agente" << endl;
    cout << "4.-Buscar un agente" << endl;
    cout << "5.-Modificar agente" << endl;
    cout << "6.-Eliminar un agente" << endl;
    cout << "7.-Eliminar todos los agentes" << endl;
    cout << "8.-Ordenar agentes" << endl;
    cout << "9.-Guardar toda la lista de agentes y clientes en almacenamiento secundario" << endl;
    cout << "10.-Leer toda la lista de agentes y clientes desde almacenamiento secundario" << endl;
    cout << "11.-Salir del sistema" << endl << endl;

    cout << "Opcion: ";
    cin >> option;
    cin.ignore();

    cout << endl;

    switch(option) {

      case 1 : showAgentList();
               break;
      case 2 : showAgentListFilteredBySpecialty();
               break;
      case 3 : addAgent();
               break;
      case 4 : searchAgent();
               break;
      case 5 : modifyAgent();
               break;
      case 6 : deleteAgent();
               break;
      case 7 : deleteAllAgents();
               break;
      case 8 : sortAgents();
               break;
      case 9 : writeToDisk();
               break;
      case 10 : readFromDisk();
               break;
      case 11 : system("cls");
               cout << "Saliendo del sistema..." << endl << endl;
               enterToContinue();
               break;
      default : cout << "Opcion invalida" << endl << endl;
                enterToContinue();
      }
    }while(option != 11);
  }

// Metodo que muestra la lista completa
void AgentMenu::showAgentList() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  char option;

  do {
    system("cls");
    cout << "MOSTRAR TODA LA LISTA DE AGENTES ALMACENADOS" << endl << endl;

    if(agentListRef->isEmpty()) {
      cout << "Actualmente esta lista se encuentra vacia" << endl << endl;
      enterToContinue();

      return;
      }

    cout << "¿Desea mostrar la lista de clientes de cada agente en la lista? (S/N): ";
    cin >> option;
    cin.ignore();

    cout << endl;

    option = toupper(option);

    if(option != 'S' and option != 'N') {
      cout << "No es una opcion valida" << endl << endl;
      enterToContinue();
      cout << endl;
      }
    } while(option != 'S' and option != 'N');

  if(option == 'S') {
    cout << agentListRef->toString(true);
    }
  else {
    cout << agentListRef->toString(false);
    }

  enterToContinue();
  }

// Metodo que muestra la lista filtrada por la especialidad de los agentes
void AgentMenu::showAgentListFilteredBySpecialty() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  Agent myAgent;
  AgentNode* pos;
  char option;
  string myStr;

  do {
    system("cls");
    cout << "MOSTRAR LA LISTA DE AGENTES ALMACENADOS FILTRADOS POR ESPECIALIDAD" << endl << endl;

    if(agentListRef->isEmpty()) {
      cout << "Actualmente esta lista se encuentra vacia" << endl << endl;
      enterToContinue();

      return;
      }

    cout << "Introduzca la especialidad que desee filtar: ";
    getline(cin, myStr);

    myAgent.setSpecialty(myStr);

    pos = agentListRef->findData(myAgent);

    cout << endl;

    if(pos == nullptr) {
      cout << "Actualmente no existen agentes con esta especialidad dentro del sistema" << endl << endl;
      enterToContinue();

      return;
    }

    cout << "¿Desea mostrar la lista de clientes de cada agente en la lista? (S/N): ";
    cin >> option;
    cin.ignore();

    cout << endl;

    option = toupper(option);

    if(option != 'S' and option != 'N') {
      cout << "No es una opcion valida" << endl << endl;
      enterToContinue();
      cout << endl;
      }
    } while(option != 'S' and option != 'N');

  if(option == 'S') {
    cout << agentListRef->filterList(true, myAgent);
    }
  else {
    cout << agentListRef->filterList(false, myAgent);
    }

  enterToContinue();
  }

// Metodo que agrega a un agente
void AgentMenu::addAgent() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  Agent myAgent;
  AgentNode* pos;
  Name myName;
  Time myTime;
  Schedule mySchedule;
  string myStr;
  char option;

  system("cls");
  cout << "AGREGAR AGENTE" << endl << endl;

  cout << "Numero de agente: ";
  getline(cin, myStr);

  myAgent.setAgentNumber(myStr);

  pos = agentListRef->findData(myAgent);

  if(pos != nullptr) {
    cout << endl;
    cout << "No podemos agregar a este agente porque ya existe otro agente con este numero de agente dentro del sistema" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Nombre (AA, NN): ";
  getline(cin, myStr, ',');
  myName.setLastName(myStr);
  getline(cin, myStr);
  myName.setFirstName(myStr);

  myAgent.setName(myName);

  cout << "Especialidad: ";
  getline(cin, myStr);

  myAgent.setSpecialty(myStr);

  cout << "Numero de extension: #";
  getline(cin, myStr);

  myAgent.setExtensionNumber(myStr);

  cout << "Horario (D-D / HH:MM-HH:MM): ";
  getline(cin, myStr, '-');
  mySchedule.setStartDay(myStr);
  getline(cin, myStr, '/');
  mySchedule.setEndDay(myStr);
  getline(cin, myStr, ':');
  myTime.setHour(stoi(myStr));
  getline(cin, myStr, '-');
  myTime.setMinute(stoi(myStr));
  mySchedule.setStartTime(myTime);
  getline(cin, myStr, ':');
  myTime.setHour(stoi(myStr));
  getline(cin, myStr);
  myTime.setMinute(stoi(myStr));
  mySchedule.setEndTime(myTime);

  myAgent.setSchedule(mySchedule);

  cout << "Horas extra: ";
  getline(cin, myStr);

  myAgent.setExtraHours(myStr);

  cout << endl;

  do {
    cout << "¿Desea agregar clientes al agente? (S/N): ";
    cin >> option;
    cin.ignore();

    option = toupper(option);

    cout << endl;

    if(option != 'S' and option != 'N') {
      cout << "No es una opcion valida" << endl << endl;
      enterToContinue();
      cout << endl;
      }
    } while(option != 'S' and option != 'N');

  if(option == 'S') {
    cout << "Sera redireccionado al menu de clientes" << endl;
    cout << "Por favor espere un momento..." << endl << endl;
    enterToContinue();

    new ClientMenu(&myAgent.getClientList());
    cout << endl;
    }

  try {
    agentListRef->insertData(agentListRef->getLastPos(), myAgent);
    } catch (ListException ex) {
      cout << "Ha ocurrido un problema" << endl;
      cout << "El sistema ha reportado: " << ex.what() << endl;
      cout << "Si esto ocurre a menudo, llame a servicio al cliente" << endl << endl;

      enterToContinue();

      return;
      }

  cout << "El agente se ha agregado exitosamente en el sistema" << endl << endl;
  enterToContinue();
  }

// Metodo que busca a un agente
void AgentMenu::searchAgent() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  Agent myAgent;
  AgentNode* pos;
  Name myName;
  string myStr;

  system("cls");
  cout << "BUSCAR AGENTE" << endl << endl;

  if(agentListRef->isEmpty()) {
    cout << "No podemos buscar nada porque la lista actualmente se encuentra vacia" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Introduzca el nombre del agente que desee buscar (AA, NN): ";
  getline(cin, myStr, ',');
  myName.setLastName(myStr);
  getline(cin, myStr);
  myName.setFirstName(myStr);

  myAgent.setName(myName);

  pos = agentListRef->findData(myAgent);

  cout << endl;

  if(pos == nullptr) {
    cout << "No se encontro a ningun agente con este nombre dentro del sistema" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "El agente ha sido encontrado con exito" << endl << endl;
  cout << agentListRef->retrieve(pos).toString(true) << endl << endl;
  enterToContinue();
  }

// Metodo que modifica a un agente
void AgentMenu::modifyAgent() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  Agent myAgent;
  Agent myAgent2;
  AgentNode* pos;
  AgentNode* pos2;
  Name myName;
  Schedule mySchedule;
  Time myTime;
  string myStr;
  int option;

  system("cls");
  cout << "MODIFICAR AGENTE" << endl << endl;

  if(agentListRef->isEmpty()) {
    cout << "No podemos modificar nada porque la lista actualmente se encuentra vacia" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Introduzca el nombre del agente que desee modificar (AA, NN): ";
  getline(cin, myStr, ',');
  myName.setLastName(myStr);
  getline(cin, myStr);
  myName.setFirstName(myStr);

  myAgent.setName(myName);

  pos = agentListRef->findData(myAgent);

  cout << endl;

  if(pos == nullptr) {
    cout << "No se encontro a ningun agente con este nombre dentro del sistema" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Se ha encontrado con exito al agente" << endl << endl;
  cout << agentListRef->retrieve(pos).toString(true) << endl << endl;

  cout << "Sera redireccionado al menu de modificaciones" << endl;
  cout << "Por favor espere un momento..." << endl << endl;
  enterToContinue();

  do {
    system("cls");
    cout << "MODIFICAR AGENTE" << endl << endl;

    // Aqui mostramos el menu con todas las opciones para modificar agentes (Menu de modificaciones)
    cout << "MENU DE MODIFICACIONES" << endl << endl;

    cout << agentListRef->retrieve(pos).toString(true) << endl << endl;

    cout << "¿Que desea modificarle a este agente?" << endl << endl;
    cout << "1.-Numero de agente" << endl;
    cout << "2.-Nombre" << endl;
    cout << "3.-Especialidad" << endl;
    cout << "4.-Numero de extension" << endl;
    cout << "5.-Horario" << endl;
    cout << "6.-Horas extra" << endl;
    cout << "7.-Lista de clientes atendidos" << endl;
    cout << "8.-Salir hacia el menu principal" << endl << endl;

    cout << "Opcion: ";
    cin >> option;
    cin.ignore();

    cout << endl;

    switch(option) {

      case 1 : system("cls");
               cout << "MODIFICAR AGENTE" << endl << endl;

               cout << "Numero de agente: ";
               getline(cin, myStr);
               myAgent2.setAgentNumber(myStr);

               pos2 = agentListRef->findData(myAgent2);

               if(pos2 != nullptr) {
                 cout << endl;
                 cout << "No podemos modificar este dato del agente porque ya existe otro agente con este numero de agente dentro del sistema" << endl << endl;
                 cout << "Volviendo hacia el menu de agentes..." << endl << endl;
                 enterToContinue();
                 break;
                 }

               myAgent2 = pos->getData();
               myAgent2.setAgentNumber(myStr);

               pos->setData(myAgent2);

               cout << endl;

               cout << "Los cambios se han aplicado con exito" << endl << endl;

               cout << "Saliendo hacia el menu de agentes..." << endl << endl;
               enterToContinue();
               break;
      case 2 : system("cls");
               cout << "MODIFICAR AGENTE" << endl << endl;

               myAgent = pos->getData();
               cout << "Nombre (AA, NN): ";
               getline(cin, myStr, ',');
               myName.setLastName(myStr);
               getline(cin, myStr);
               myName.setFirstName(myStr);

               myAgent.setName(myName);

               pos->setData(myAgent);

               cout << endl;

               cout << "Los cambios se han aplicado con exito" << endl << endl;

               cout << "Saliendo hacia el menu de agentes..." << endl << endl;
               enterToContinue();
               break;
      case 3 : system("cls");
               cout << "MODIFICAR AGENTE" << endl << endl;

               myAgent = pos->getData();
               cout << "Especialidad: ";
               getline(cin, myStr);
               myAgent.setSpecialty(myStr);

               pos->setData(myAgent);

               cout << endl;

               cout << "Los cambios se han aplicado con exito" << endl << endl;

               cout << "Saliendo hacia el menu de agentes..." << endl << endl;
               enterToContinue();
               break;
      case 4 : system("cls");
               cout << "MODIFICAR AGENTE" << endl << endl;

               myAgent = pos->getData();
               cout << "Numero de extension: #";
               getline(cin, myStr);
               myAgent.setExtensionNumber(myStr);

               pos->setData(myAgent);

               cout << endl;

               cout << "Los cambios se han aplicado con exito" << endl << endl;

               cout << "Saliendo hacia el menu de agentes..." << endl << endl;
               enterToContinue();
               break;
      case 5 : system("cls");
               cout << "MODIFICAR AGENTE" << endl << endl;

               myAgent = pos->getData();
               cout << "Horario (D-D / HH:MM-HH:MM): ";
               getline(cin, myStr, '-');
               mySchedule.setStartDay(myStr);
               getline(cin, myStr, '/');
               mySchedule.setEndDay(myStr);
               getline(cin, myStr, ':');
               myTime.setHour(stoi(myStr));
               getline(cin, myStr, '-');
               myTime.setMinute(stoi(myStr));
               mySchedule.setStartTime(myTime);
               getline(cin, myStr, ':');
               myTime.setHour(stoi(myStr));
               getline(cin, myStr);
               myTime.setMinute(stoi(myStr));
               mySchedule.setEndTime(myTime);

               myAgent.setSchedule(mySchedule);

               pos->setData(myAgent);

               cout << endl;

               cout << "Los cambios se han aplicado con exito" << endl << endl;

               cout << "Saliendo hacia el menu de agentes..." << endl << endl;
               enterToContinue();
               break;
      case 6 : system("cls");
               cout << "MODIFICAR AGENTE" << endl << endl;

               myAgent = pos->getData();
               cout << "Horas extra: ";
               getline(cin, myStr);
               myAgent.setExtraHours(myStr);

               pos->setData(myAgent);

               cout << endl;

               cout << "Los cambios se han aplicado con exito" << endl << endl;

               cout << "Saliendo hacia el menu de agentes..." << endl << endl;
               enterToContinue();
               break;
      case 7 : myAgent = pos->getData();
               new ClientMenu(&myAgent.getClientList());

               pos->setData(myAgent);

               cout << endl;

               cout << "Saliendo hacia el menu de agentes..." << endl << endl;
               enterToContinue();
               break;
      case 8 : cout << "Saliendo hacia el menu de agentes..." << endl << endl;
               enterToContinue();
               break;
      default : cout << "Opcion invalida" << endl << endl;
                enterToContinue();
      }
    } while(option != 1 and option != 2 and option != 3 and option != 4 and option != 5 and option != 6 and option != 7 and option != 8);
  }

// Metodo que elimina a un agente
void AgentMenu::deleteAgent() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  Agent myAgent;
  AgentNode* pos;
  Name myName;
  string myStr;
  char option;

  system("cls");
  cout << "ELIMINAR AGENTE" << endl << endl;

  if(agentListRef->isEmpty()) {
    cout << "No podemos eliminar nada porque la lista actualmente se encuentra vacia" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Introduzca el nombre del agente que desee eliminar (AA, NN): ";
  getline(cin, myStr, ',');
  myName.setLastName(myStr);
  getline(cin, myStr);
  myName.setFirstName(myStr);

  myAgent.setName(myName);

  pos = agentListRef->findData(myAgent);

  cout << endl;

  if(pos == nullptr) {
    cout << "No se encontro a ningun agente con este nombre dentro del sistema" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Se ha encontrado con exito al agente" << endl << endl;
  cout << agentListRef->retrieve(pos).toString(true) << endl << endl;

  do {
    cout << "¿Esta seguro de querer eliminar a este agente? (S/N): ";
    cin >> option;

    cout << endl;

    option = toupper(option);

    if(option == 'S') {
      agentListRef->deleteData(pos);

      cout << "El agente se ha eliminado exitosamente del sistema" << endl << endl;
      enterToContinue();
      cin.ignore();
      }

    if(option == 'N') {
      cout << "El agente no se ha eliminado del sistema" << endl << endl;
      enterToContinue();
      cin.ignore();
      }

    if(option != 'S' and option != 'N') {
      cout << "No es una opcion valida" << endl << endl;
      enterToContinue();
      cin.ignore();
      cout << endl;
      }
    } while(option != 'S' and option != 'N');
  }

// Metodo que elimina a todos los agentes
void AgentMenu::deleteAllAgents() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  char option;

  do {
    system("cls");
    cout << "ELIMINAR TODOS LOS AGENTES" << endl << endl;

    if(agentListRef->isEmpty()) {
      cout << "No podemos eliminar a ningun agente porque la lista se encuentra vacia" << endl << endl;
      enterToContinue();

      return;
      }

    cout << "¿Esta seguro de querer eliminar a todos los agentes del sistema? (S/N): ";
    cin >> option;

    cout << endl;

    option = toupper(option);

    if(option == 'S') {
      agentListRef->deleteAll();

      cout << "Todos los agentes se han eliminado exitosamente del sistema" << endl << endl;
      enterToContinue();
      cin.ignore();
      }

    if(option == 'N') {
      cout << "No se ha eliminado a ningun agente del sistema" << endl << endl;
      enterToContinue();
      cin.ignore();
      }

    if(option != 'S' and option != 'N') {
      cout << "No es una opcion valida" << endl << endl;
      enterToContinue();
      cin.ignore();
      }
    } while(option != 'S' and option != 'N');
  }

// Metodo que ordena a los agentes por especialidad o por nombre
void AgentMenu::sortAgents() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  int option;

  do {
    system("cls");
    cout << "ORDENAR AGENTES" << endl << endl;

    if(agentListRef->isEmpty()) {
      cout << "No podemos ordenar nada porque la lista actualmente se encuentra vacia" << endl << endl;
      enterToContinue();

      return;
      }

    cout << "¿Bajo que criterio desea ordenar a los agentes?" << endl << endl;
    cout << "1.-Nombre" << endl;
    cout << "2.-Especialidad" << endl << endl;

    cout << "Opcion: ";
    cin >> option;
    cin.ignore();

    cout << endl;

    if(option == 1) {
      agentListRef->sortByName();

      cout << "La lista se ha ordenado exitosamente bajo el criterio de nombre" << endl << endl;
      enterToContinue();
      }

    if(option == 2) {
      agentListRef->sortBySpecialty();

      cout << "La lista se ha ordenado exitosamente bajo el criterio de especialidad" << endl << endl;
      enterToContinue();
      }

    if(option != 1 and option != 2) {
      cout << "No es una opcion valida" << endl << endl;
      enterToContinue();
      }
    } while(option != 1 and option != 2);
  }

// Metodo que guarda la lista de agentes y clientes en el disco
void AgentMenu::writeToDisk() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  char option;
  string fileName;

  do {
    system("cls");
    cout << "GUARDAR TODA LA LISTA DE AGENTES Y CLIENTES EN ALMACENAMIENTO SECUNDARIO" << endl << endl;

    if(agentListRef->isEmpty()) {
      cout << "No podemos guardar nada porque la lista actualmente se encuentra vacia" << endl << endl;
      enterToContinue();

      return;
      }

    cout << "¿Desea guardar toda la lista de agentes y clientes en almacenamiento secundario? (S/N): ";
    cin >> option;
    cin.ignore();

    option = toupper(option);

    cout << endl;

    if(option == 'S') {
      cout << "Introduzca un nombre para guardar el archivo: ";
      getline(cin, fileName);

      cout << endl;

      cout << "Guardando toda la lista de agentes y clientes en el almacenamiento secundario..." << endl << endl;

      try {
        agentListRef->writeToDisk(fileName + ".list");
        } catch(ListException ex) {
          cout << "Ocurrio un problema" << endl;
          cout << ex.what() << endl << endl;

          enterToContinue();

          return;
          }

      cout << "Toda la lista de agentes y clientes se ha guardado exitosamente en el almacenamiento secundario" << endl << endl;
      enterToContinue();
      }

    if(option == 'N') {
      cout << "No se ha guardado nada en el almacenamiento secundario" << endl << endl;
      enterToContinue();
      }

    if(option != 'S' and option != 'N') {
      cout << "No es una opcion valida" << endl << endl;
      enterToContinue();
      }
    } while(option != 'S' and option != 'N');
  }

// Metodo que lee la lista de agentes y clientes desde el disco
void AgentMenu::readFromDisk() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  char option;
  string fileName;

  do {
    system("cls");
    cout << "LEER TODA LA LISTA DE AGENTES Y CLIENTES DESDE ALMACENAMIENTO SECUNDARIO" << endl << endl;

    cout << "¿Desea leer toda la lista de agentes y clientes desde el almacenamiento secundario? (S/N): ";
    cin >> option;
    cin.ignore();

    option = toupper(option);

    cout << endl;

    if(option == 'S') {
      cout << "Introduzca el nombre del archivo a leer: ";
      getline(cin, fileName);

      cout << endl;

      cout << "Leyendo archivo..." << endl << endl;

      try {
        agentListRef->readFromDisk(fileName + ".list");
        } catch(ListException ex) {
          cout << "Ocurrio un problema" << endl;
          cout << ex.what() << endl << endl;

          enterToContinue();

          return;
          }

      cout << "El archivo se ha leido exitosamente" << endl;
      cout << "Toda la lista de agentes y clientes se ha leido desde el almacenamiento secundario" << endl << endl;
      enterToContinue();
      }

    if(option == 'N') {
      cout << "No se ha leido nada desde el almacenamiento secundario" << endl << endl;
      enterToContinue();
      }

    if(option != 'S' and option != 'N') {
      cout << "No es una opcion valida" << endl << endl;
      enterToContinue();
      }
    } while(option != 'S' and option != 'N');
  }

// Metodo que sirve para pedir al usuario un ENTER para continuar
void AgentMenu::enterToContinue() {
  cout << "Presione [ENTER] para continuar...";
  getchar();
  }
