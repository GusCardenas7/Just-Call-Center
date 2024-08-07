// Esta es la implementacion de la clase 'AgentList'
// Dentro de esta tambien se encuentra la implementacion de la clase 'ListException'
#include "agentlist.h"

using namespace std;

// Entregable 07

// Metodo privado que valida si una posicion es valida
bool AgentList::isValidPos(AgentNode* p) {
  AgentNode* aux(header->getNext());

  while(aux != header) {
    if(p == aux) {
      return true;
      }

    aux = aux->getNext();
    }

  return false;
  }

// Constructor base que inicializa la lista
AgentList::AgentList() : header(new AgentNode) {
  if(header == nullptr) {
    throw ListException("Memoria no disponible, inicializando lista");
    }

  header->setPrev(header);
  header->setNext(header);
  }

// Metodo publico que valida si la lista esta vacia
bool AgentList::isEmpty() {
  return header->getNext() == header;
  }

// Metodo publico que inserta un elemento en una posicion dentro de la lista
void AgentList::insertData(AgentNode* p, const Agent& e) {
  if(p != nullptr and !isValidPos(p)) {
    throw ListException("Posicion invalida, insertData");
    }

  if(p == nullptr) {
    p = header;
    }

  AgentNode* aux(new AgentNode(e));
  if(aux == nullptr) {
    throw ListException("Memoria no disponible, insertData");
    }

  // religado, conectamos el nodo a la lista y posteriormente la lista se conecta con el nodo
  aux->setPrev(p);
  aux->setNext(p->getNext());

  p->getNext()->setPrev(aux);
  p->setNext(aux);
  }

// Metodo publico que imprime la lista convirtiendo a cadena todos los elementos que obtenga
string AgentList::toString(const bool& withClientList) {
  AgentNode* aux(header->getNext());
  string result;

  while(aux != header) {
    result += aux->getData().toString(withClientList);
    result += "\n";
    result += "\n";

    aux = aux->getNext();
    }

  return result;
  }

// Metodo que filtra la lista bajo el criterio de especialidad
string AgentList::filterList(const bool& withClientList, const Agent& e) {
  AgentNode* aux(header->getNext());
  string result;

  while(aux != header) {
    if(aux->getData() == e) {
      result += aux->getData().toString(withClientList);
      result += "\n";
      result += "\n";
      }

    aux = aux->getNext();
    }

  return result;
  }

// ******************************************

// Entregable 08

// Destructor de la lista
AgentList::~AgentList() {
  deleteAll();

  delete header;
  }

// Metodo que elimina a un elemento de la lista
void AgentList::deleteData(AgentNode* p) {
  if(!isValidPos(p)) {
    throw ListException("Posicion invalida, deleteData");
    }

  p->getPrev()->setNext(p->getNext());
  p->getNext()->setPrev(p->getPrev());

  delete p;
  }

// Metodo que obtiene la posicion anterior de un nodo
AgentNode* AgentList::getPrevPos(AgentNode* p) {
  if(p == header->getNext() or !isValidPos(p)) {
    return nullptr;
    }

  return p->getPrev();
  }

// Metodo que obtiene la siguiente posicion de un nodo
AgentNode* AgentList::getNextPos(AgentNode* p) {
  if(p == header->getPrev() or !isValidPos(p)) {
    return nullptr;
    }

  return p->getNext();
  }

// Metodo que busca un elemento dentro de la lista
AgentNode* AgentList::findData(const Agent& e) {
  AgentNode* aux(header->getNext());

  while(aux != header) {
    if(aux->getData() == e) {
      return aux;
      }

    aux = aux->getNext();
    }

  return nullptr;
  }

// Metodo que elimina todos los nodos de la lista
void AgentList::deleteAll() {
  AgentNode* aux;

  while(header->getNext() != header) {
    aux = header->getNext();

    header->setNext(aux->getNext());

    delete aux;
    }

  header->setPrev(header);
  }

// ******************************************

// ******************************************

// Metodo privado que copia toda la lista
void AgentList::copyAll(const AgentList& l) {
  AgentNode* aux(l.header->getNext());
  AgentNode* newNode;

  while(aux != l.header) {
    newNode = new AgentNode(aux->getData()); // creamos nodos nuevos y le ponemos el dato

    if(newNode == nullptr) {
      throw ListException("Memoria no disponible, copyAll");
      }

    // religado, el nodo nuevo se conecta primero con la lista y despues la lista se conecta con el nodo
    // este religado siempre se coloca al final de la lista
    newNode->setPrev(header->getPrev());
    newNode->setNext(header);

    header->getPrev()->setNext(newNode);
    header->setPrev(newNode);

    aux = aux->getNext();
    }
  }

// Constructor copia que inicializa la lista y despues hace la copia de esta
AgentList::AgentList(const AgentList& l) : AgentList() {
  copyAll(l);
  }

// Metodo que retorna la direccion del primer elemento de la lista
AgentNode* AgentList::getFirstPos() {
  if(isEmpty()) {
    return nullptr;
    }

  return header->getNext();
  }

// Metodo que retorna la direccion del ultimo elemento de la lista
AgentNode* AgentList::getLastPos() {
  if(isEmpty()) {
    return nullptr;
    }

  return header->getPrev();
  }

// Metodo que retorna el elemento que hay dentro de la posicion que recibimos
Agent AgentList::retrieve(AgentNode* p) {
  if(!isValidPos(p)) {
    throw ListException("Posicion invalida, retrieve");
    }

  return p->getData();
  }

// Operador de asignacion que recibe una lista y la intencion es reemplazar lo que tiene la lista
// con lo que recibimos de la otra
AgentList& AgentList::operator = (const AgentList& l) {
  deleteAll(); // limpiamos la lista

  copyAll(l); // copiamos la lista que recibimos como parametro en la lista local

  return *this;
  }

// ******************************************

// Entregable 10

// Este metodo intercambia apuntadores a nodo
void AgentList::swapPtr(AgentNode* a, AgentNode* b) {
  if(a != b) {
    Agent* aux(a->getDataPtr());
    a->setDataPtr(b->getDataPtr());
    b->setDataPtr(aux);
    }
  }

// Este metodo ordena por nombre y lo hace por medio del ordenamiento Quicksort
void AgentList::sortByName(AgentNode* leftEdge, AgentNode* rightEdge) {
  // Este if es para cuando solamente es un elemento
  if(leftEdge == rightEdge) {
    return;
    }

  // Este if es para cuando son nada mas dos elementos
  if(leftEdge->getNext() == rightEdge) {
    if(leftEdge->getData().getName() > rightEdge->getData().getName()) {
      swapPtr(leftEdge, rightEdge);
      }

    return;
    }

  AgentNode* i(leftEdge);
  AgentNode* j(rightEdge);

  while(i != j) {
    while(i != j and i->getData().getName() <= rightEdge->getData().getName()) {
      i = i->getNext();
      }

    while(i != j and j->getData().getName() >= rightEdge->getData().getName()) {
      j = j->getPrev();
      }

    swapPtr(i, j);
    }

  swapPtr(i, rightEdge);

  if(i != leftEdge) {
    sortByName(leftEdge, i->getPrev());
    }

  if(i != rightEdge) {
    sortByName(i->getNext(), rightEdge);
    }
  }

// Este metodo ordena por especialidad y lo hace por medio del ordenamiento Quicksort
void AgentList::sortBySpecialty(AgentNode* leftEdge, AgentNode* rightEdge) {
  // Este if es para cuando solamente es un elemento
  if(leftEdge == rightEdge) {
    return;
    }

  // Este if es para cuando son nada mas dos elementos
  if(leftEdge->getNext() == rightEdge) {
    if(leftEdge->getData().getSpecialty() > rightEdge->getData().getSpecialty()) {
      swapPtr(leftEdge, rightEdge);
      }

    return;
    }

  AgentNode* i(leftEdge);
  AgentNode* j(rightEdge);

  while(i != j) {
    while(i != j and i->getData().getSpecialty() <= rightEdge->getData().getSpecialty()) {
      i = i->getNext();
      }

    while(j != i and j->getData().getSpecialty() >= rightEdge->getData().getSpecialty()) {
      j = j->getPrev();
      }

    swapPtr(i, j);
    }

  swapPtr(i, rightEdge);

  if(i != leftEdge) {
    sortBySpecialty(leftEdge, i->getPrev());
    }

  if(i != rightEdge) {
    sortBySpecialty(i->getNext(), rightEdge);
    }
  }

// Este metodo publico manda a llamar al metodo privado que ordena la lista bajo el criterio de nombre
void AgentList::sortByName() {
  sortByName(getFirstPos(), getLastPos());
  }

// Este metodo publico manda a llamar al metodo privado que ordena la lista bajo el criterio de especialidad
void AgentList::sortBySpecialty() {
  sortBySpecialty(getFirstPos(), getLastPos());
  }

// ******************************************

// Entregable 11

// Este metodo escribe la lista en el disco
void AgentList::writeToDisk(const std::string& fileName) {
  ofstream myFile;

  myFile.open(fileName, myFile.trunc);

  if(!myFile.is_open()) {
    string message;
    message = "Error al intentar abrir el archivo ";
    message += fileName;
    message += " para escritura del mismo";

    throw ListException(message);
    }

  AgentNode* aux(header->getNext());

  while(aux != header) {
    myFile << aux->getData() << endl;

    try {
      aux->getData().getClientList().writeToDisk(aux->getData().getAgentNumber() + ".clients");
      } catch(ListException ex) {
        cout << ex.what() << endl;
        }

    aux = aux->getNext();
    }

  myFile.close();
  }

// Este metodo lee la lista desde el disco
void AgentList::readFromDisk(const std::string& fileName) {
  ifstream myFile;

  myFile.open(fileName);

  if(!myFile.is_open()) {
    string message;
    message = "Error al intentar abrir el archivo ";
    message += fileName;
    message += " para lectura del mismo";

    throw ListException(message);
    }

  Agent myAgent;
  AgentNode* aux;

  deleteAll(); // limpiamos la lista para despues leerla desde el disco

  while(myFile >> myAgent) {
    try {
      myAgent.getClientList().readFromDisk(myAgent.getAgentNumber() + ".clients");
      } catch(ListException ex) {
        cout << ex.what() << endl;
        }

    if((aux = new AgentNode(myAgent)) == nullptr) {
      myFile.close();

      throw ListException("Memoria no disponible, readFromDisk");
      }

    // religado
    aux->setPrev(header->getPrev());
    aux->setNext(header);

    header->getPrev()->setNext(aux);
    header->setPrev(aux);
    }

  myFile.close();
  }
