// Esta es la implementacion de la clase 'ClientList'
// Dentro de esta tambien se encuentra la implementacion de la clase 'ListException'
#include "clientlist.h"

using namespace std;

// Entregable 04

// Metodo privado que valida si una posicion es valida
bool ClientList::isValidPos(ClientNode* p) {
  ClientNode* aux(anchor);

  while(aux != nullptr) {
    if(aux == p) {
      return true;
      }

    aux = aux->getNext();
    }

  return false;
  }

// Constructor base que inicializa la lista
ClientList::ClientList() : anchor(nullptr) { }

// Metodo que valida si la lista esta vacia
bool ClientList::isEmpty() {
  return anchor == nullptr;
  }

// Metodo publico que imprime la lista convirtiendo a cadena todos los elementos que obtenga
string ClientList::toString() const {
  ClientNode* aux(anchor);
  string result;
  ostringstream flow;

  flow << left;
  flow << setw(40) << "Nombre del cliente";
  flow << setw(30) << "Hora de atencion";
  flow << setw(22) << "Duracion de la llamada";
  flow << "\n";

  while(aux != nullptr) {
    flow << aux->getData().toString();
    flow << "\n";

    aux = aux->getNext();
    }

  result = flow.str();

  return result;
  }

// Metodo publico que inserta un elemento en una posicion dentro de la lista
void ClientList::insertData(ClientNode* p, const Client& e) {
  if(p != nullptr and ! isValidPos(p)) {
    throw ListException("Posicion invalida, tratando de insertar");
    }

  ClientNode* aux(new ClientNode(e));

  if(aux == nullptr) {
    throw ListException("Memoria no disponible, tratando de insertar");
    }

  // religado
  if(p == nullptr) {
    aux->setNext(anchor);

    anchor = aux;
    }
  else {
    aux->setNext(p->getNext());

    p->setNext(aux);
    }
  }

// Metodo que inserta de manera ordenada un elemento en la lista, mandando a llamar el metodo que inserta en la lista
void ClientList::insertOrderedByAttentionTime(const Client& e) {
  ClientNode* aux(anchor);
  ClientNode* p(nullptr);

  while(aux != nullptr and e.getAttentionTime() > aux->getData().getAttentionTime()) {
    p = aux;
    aux = aux->getNext();
    }

  insertData(p, e);
  }

// ******************************************

// Entregable 05

// Metodo que obtiene la posicion anterior de un nodo
ClientNode* ClientList::getPrevPos(ClientNode* p) {
  if(p == anchor or !isValidPos(p)) {
    return nullptr;
    }

  ClientNode* aux(anchor);

  while(aux->getNext() != p) {
    aux = aux->getNext();
    }

  return aux;
  }

// Metodo que elimina a un elemento de la lista
void ClientList::deleteData(ClientNode* p) {
  if(!isValidPos(p)) {
    throw ListException("Posicion invalida, deleteData");
    }

  // religado
  if(p == anchor) {
    anchor = p->getNext();
    }
  else{
    getPrevPos(p)->setNext(p->getNext());
    }

  delete p;
  }

// Metodo que busca un elemento dentro de la lista
ClientNode* ClientList::findData(const Client& e) {
  ClientNode* aux(anchor);

  while(aux != nullptr) {
    if(aux->getData().getName() == e.getName() and aux->getData().getAttentionTime() == e.getAttentionTime()) {
      return aux;
      }

    aux = aux->getNext();
    }

  return nullptr;
  }

// Metodo que busca un elemento dentro de la lista por medio de su hora de atencion
ClientNode* ClientList::findDataByAttentionTime(const Client& e) {
  ClientNode* aux(anchor);

  while(aux != nullptr) {
    if(aux->getData().getAttentionTime() == e.getAttentionTime()) {
      return aux;
      }

    aux = aux->getNext();
    }

  return nullptr;
  }

// Metodo que elimina todos los nodos de la lista
void ClientList::deleteAll() {
  ClientNode* aux(anchor);

  while(anchor != nullptr) {
    anchor = aux->getNext();
    delete aux;

    aux = aux->getNext();
    }
  }

// Destructor
ClientList::~ClientList() {
  deleteAll();
  }

// ******************************************

// ******************************************

// Metodo que copia toda la lista
void ClientList::copyAll(const ClientList& l) {
  ClientNode* aux(l.anchor);
  ClientNode* last(nullptr);
  ClientNode* newNode;

  while(aux != nullptr) {
    newNode = new ClientNode(aux->getData()); // creamos nodos nuevos y le ponemos el dato

    if(newNode == nullptr) {
      throw ListException("Memoria no disponible, copyAll");
      }

    if(last == nullptr) {
      anchor = newNode;
      }
    else{
      last->setNext(newNode);
      }

    last = newNode;

    aux = aux->getNext();
    }
  }

// Constructor copia que inicializa la lista y despues hace la copia de esta
ClientList::ClientList(const ClientList& l) : ClientList() {
  copyAll(l);
  }

// Metodo que retorna la direccion del primer elemento de la lista
ClientNode* ClientList::getFirstPos() {
  return anchor;
  }

// Metodo que retorna la direccion del ultimo elemento de la lista
ClientNode* ClientList::getLastPos() {
  if(isEmpty()) {
    return nullptr;
    }

  ClientNode* aux(anchor);

  while(aux->getNext() != nullptr) {
    aux = aux->getNext();
    }

  return aux;
  }

// Metodo que obtiene la siguiente posicion de un nodo
ClientNode* ClientList::getNextPos(ClientNode* p) {
  if(!isValidPos(p)) {
    return nullptr;
    }

  return p->getNext();
  }

// Metodo que retorna el elemento que hay dentro de la posicion que recibimos
Client ClientList::retrieve(ClientNode* p) {
  if(!isValidPos(p)) {
    throw ListException("Posicion invalida, retrieve");
    }

  return p->getData();
  }

// Operador de asignacion que recibe una lista y la intencion es reemplazar lo que tiene la lista
// con lo que recibimos de la otra
ClientList& ClientList::operator = (const ClientList& l) {
  deleteAll(); // limpiamos la lista

  copyAll(l); // copiamos la lista que recibimos como parametro en la lista local

  return *this;
  }

// ******************************************

// Entregable 11

// Metodo que escribe la lista en el disco
void ClientList::writeToDisk(const std::string& fileName) {
  ofstream myFile;

  myFile.open(fileName, myFile.trunc);

  if(!myFile.is_open()) {
    string message;
    message = "Error al intentar abrir el archivo ";
    message += fileName;
    message += " para escritura del mismo";

    throw ListException(message);
    }

  ClientNode* aux(anchor);

  while(aux != nullptr) {
    myFile << aux->getData() << endl;

    aux = aux->getNext();
    }

  myFile.close();
  }

// Metodo que lee la lista desde el disco
void ClientList::readFromDisk(const std::string& fileName) {
  ifstream myFile;

  myFile.open(fileName);

  if(!myFile.is_open()) {
    string message;
    message = "Error al intentar abrir el archivo ";
    message += fileName;
    message += " para lectura del mismo";

    throw ListException(message);
    }

  deleteAll();

  Client myClient;
  ClientNode* last(nullptr);
  ClientNode* newNode;

  while(myFile >> myClient) {
    if((newNode = new ClientNode(myClient)) == nullptr) {
      myFile.close();

      throw ListException("Memoria no disponible, readFromDisk");
      }

    if(last == nullptr) {
      anchor = newNode;
      }
    else {
      last->setNext(newNode);
      }

    last = newNode;
    }

  myFile.close();
  }
