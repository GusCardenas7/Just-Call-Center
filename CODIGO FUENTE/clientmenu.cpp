// Esta es la implementacion de la clase 'ClientMenu'
#include "clientmenu.h"

using namespace std;

// Constructor parametrizado
ClientMenu::ClientMenu(ClientList* p) : clientListRef(p) {
  mainMenu();
  }

// Metodo que muestra el menu de opciones para los clientes
void ClientMenu::mainMenu() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  int option;

  do {
    system("cls");
    cout << "MENU DE CLIENTES" << endl << endl;

    cout << "1.-Agregar un cliente a la lista de este agente" << endl;
    cout << "2.-Eliminar un cliente de la lista del agente" << endl;
    cout << "3.-Eliminar todos los clientes de la lista del agente" << endl;
    cout << "4.-Modificar la duracion de la llamada de un cliente de la lista de este agente" << endl;
    cout << "5.-Mostrar toda la lista de clientes almacenados de este agente" << endl;
    cout << "6.-Salir del menu de clientes" << endl << endl;

    cout << "Opcion: ";
    cin >> option;
    cin.ignore();

    cout << endl;

    switch(option) {

      case 1 : addClient();
               break;
      case 2 : deleteClient();
               break;
      case 3 : deleteAllClients();
               break;
      case 4 : modifyCallDurationOfAClient();
               break;
      case 5 : showClientList();
               break;
      case 6 : cout << "Saliendo del menu de clientes..." << endl << endl;
               enterToContinue();
               break;
      default : cout << "Opcion invalida" << endl << endl;
                enterToContinue();
      }
    } while(option != 6);
  }

// Metodo que agrega a un cliente
void ClientMenu::addClient() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  Client myClient;
  ClientNode* pos;
  Name myName;
  Time myTime;
  string myStr;

  system("cls");
  cout << "AGREGAR UN CLIENTE A LA LISTA DE ESTE AGENTE" << endl << endl;

  cout << "Nombre (AA, NN): ";
  getline(cin, myStr, ',');
  myName.setLastName(myStr);
  getline(cin, myStr);
  myName.setFirstName(myStr);

  myClient.setName(myName);

  cout << "Hora de atencion (HH:MM): ";
  getline(cin, myStr, ':');
  myTime.setHour(stoi(myStr));
  getline(cin, myStr);
  myTime.setMinute(stoi(myStr));

  myClient.setAttentionTime(myTime);

  pos = clientListRef->findDataByAttentionTime(myClient);

  if(pos != nullptr) {
    cout << endl;
    cout << "No podemos agregar a este cliente porque ya existe otro cliente con esta hora de atencion dentro de la lista de este agente" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Duracion de la llamada (HH:MM): ";
  getline(cin, myStr, ':');
  myTime.setHour(stoi(myStr));
  getline(cin, myStr);
  myTime.setMinute(stoi(myStr));

  myClient.setCallDuration(myTime);

  cout << endl;

  try {
    clientListRef->insertOrderedByAttentionTime(myClient);
    } catch (ListException ex) {
      cout << "Ha ocurrido un problema" << endl;
      cout << "El sistema ha reportado: " << ex.what() << endl;
      cout << "Si esto ocurre a menudo, llame a servicio al cliente" << endl << endl;

      enterToContinue();

      return;
      }

  cout << "El cliente se ha agregado exitosamente a la lista de este agente" << endl << endl;
  enterToContinue();
  }

// Metodo que elimina a un cliente
void ClientMenu::deleteClient() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  Client myClient;
  ClientNode* pos;
  Name myName;
  Time myTime;
  string myStr;
  char option;

  system("cls");
  cout << "ELIMINAR UN CLIENTE DE LA LISTA DEL AGENTE" << endl << endl;

  if(clientListRef->isEmpty()) {
    cout << "No podemos eliminar a ningun cliente porque la lista del agente se encuentra vacia" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Introduzca el nombre del cliente que desee eliminar (AA, NN): ";
  getline(cin, myStr, ',');
  myName.setLastName(myStr);
  getline(cin, myStr);
  myName.setFirstName(myStr);

  myClient.setName(myName);

  cout << "Ahora introduzca su hora de atencion (HH:MM): ";
  getline(cin, myStr, ':');
  myTime.setHour(stoi(myStr));
  getline(cin, myStr);
  myTime.setMinute(stoi(myStr));

  myClient.setAttentionTime(myTime);

  pos = clientListRef->findData(myClient);

  cout << endl;

  if(pos != nullptr) {
    cout << "Se ha encontrado el cliente a eliminar" << endl << endl;

    cout << left;
    cout << setw(40) << "Nombre del cliente";
    cout << setw(30) << "Hora de atencion";
    cout << setw(22) << "Duracion de la llamada" << endl;
    cout << clientListRef->retrieve(pos).toString() << endl << endl;

    do {
      cout << "¿Esta seguro de querer eliminar a este cliente? (S/N): ";
      cin >> option;
      cin.ignore();

      cout << endl;

      option = toupper(option);

      if(option == 'S') {
        clientListRef->deleteData(pos);

        cout << "El cliente se ha eliminado exitosamente de la lista del agente" << endl << endl;
        enterToContinue();
        }

      if(option == 'N') {
        cout << "El cliente no se ha eliminado de la lista del agente" << endl << endl;
        enterToContinue();
        }

      if(option != 'S' and option != 'N') {
        cout << "No es una opcion valida" << endl << endl;
        enterToContinue();
        cout << endl;
        }
      } while(option != 'S' and option != 'N');
    }
  else {
    cout << "No se ha encontrado ningun cliente con estas caracteristicas dentro de la lista del agente" << endl << endl;
    enterToContinue();
    }
  }

// Metodo que elimina todos los clientes
void ClientMenu::deleteAllClients() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  char option;

  do {
    system("cls");
    cout << "ELIMINAR TODOS LOS CLIENTES DE LA LISTA DEL AGENTE" << endl << endl;

    if(clientListRef->isEmpty()) {
      cout << "No podemos eliminar a ningun cliente porque la lista del agente se encuentra vacia" << endl << endl;
      enterToContinue();

      return;
      }

    cout << "¿Esta seguro de querer eliminar a todos los clientes de la lista del agente? (S/N): ";
    cin >> option;
    cin.ignore();

    cout << endl;

    option = toupper(option);

    if(option == 'S') {
      clientListRef->deleteAll();

      cout << "Todos los clientes se han eliminado exitosamente de la lista del agente" << endl << endl;
      enterToContinue();
      }

    if(option == 'N') {
      cout << "No se ha eliminado a ningun cliente de la lista del agente" << endl << endl;
      enterToContinue();
      }

    if(option != 'S' and option != 'N') {
      cout << "No es una opcion valida" << endl << endl;
      enterToContinue();
      cout << endl;
      }
    } while(option != 'S' and option != 'N');
  }

// Metodo que modifica la duracion de la llamada de un cliente
void ClientMenu::modifyCallDurationOfAClient() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  Client myClient;
  ClientNode* pos;
  Name myName;
  Time myTime;
  string myStr;

  system("cls");
  cout << "MODIFICAR LA DURACION DE LA LLAMADA DE UN CLIENTE DE LA LISTA DE ESTE AGENTE" << endl << endl;

  if(clientListRef->isEmpty()) {
    cout << "No podemos modificar la duracion de la llamada de ningun cliente porque la lista del agente se encuentra vacia" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Introduzca el nombre del cliente al que le desee modificar la duracion de su llamada (AA, NN): ";
  getline(cin, myStr, ',');
  myName.setLastName(myStr);
  getline(cin, myStr);
  myName.setFirstName(myStr);

  myClient.setName(myName);

  cout << "Ahora introduzca su hora de atencion (HH:MM): ";
  getline(cin, myStr, ':');
  myTime.setHour(stoi(myStr));
  getline(cin, myStr);
  myTime.setMinute(stoi(myStr));

  myClient.setAttentionTime(myTime);

  pos = clientListRef->findData(myClient);

  cout << endl;

  if(pos == nullptr) {
    cout << "No se ha encontrado a ningun cliente con estas caracteristicas dentro de la lista de este agente" << endl << endl;
    enterToContinue();

    return;
    }

  cout << "Se ha encontrado con exito al cliente" << endl << endl;

  cout << left;
  cout << setw(40) << "Nombre del cliente";
  cout << setw(30) << "Hora de atencion";
  cout << setw(22) << "Duracion de la llamada" << endl;
  cout << clientListRef->retrieve(pos).toString() << endl << endl;

  cout << "Introduzca la nueva duracion de la llamada del cliente (HH:MM): ";
  getline(cin, myStr, ':');
  myTime.setHour(stoi(myStr));
  getline(cin, myStr);
  myTime.setMinute(stoi(myStr));

  myClient.setCallDuration(myTime);

  pos->setData(myClient);

  cout << endl;

  cout << "Los cambios se han aplicado con exito, puedes verificarlos aqui mismo" << endl << endl;

  cout << left;
  cout << setw(40) << "Nombre del cliente";
  cout << setw(30) << "Hora de atencion";
  cout << setw(22) << "Duracion de la llamada" << endl;
  cout << clientListRef->retrieve(pos).toString() << endl << endl;

  enterToContinue();
  }

// Metodo que muestra la lista de clientes
void ClientMenu::showClientList() {
  setlocale(LC_ALL, "Spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);

  system("cls");
  cout << "MOSTRAR TODA LA LISTA DE CLIENTES ALMACENADOS DE ESTE AGENTE" << endl << endl;

  if(clientListRef->isEmpty()) {
    cout << "Actualmente la lista de clientes de este agente se encuentra vacia" << endl << endl;
    enterToContinue();

    return;
    }

  cout << clientListRef->toString() << endl;
  enterToContinue();
  }

// Metodo que sirve para pedir al usuario un ENTER para continuar
void ClientMenu::enterToContinue() {
  cout << "Presione [ENTER] para continuar...";
  getchar();
  }
