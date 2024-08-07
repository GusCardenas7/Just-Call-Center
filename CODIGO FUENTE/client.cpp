// Esta es la implementacion de la clase 'Client'
#include "client.h"

using namespace std;

// Contructor base
Client::Client() { }

// Constructor copia
Client::Client(const Client& c) : name(c.name), attentionTime(c.attentionTime), callDuration(c.callDuration) { }

// getter que obtiene el nombre del cliente
Name Client::getName() const {
  return name;
  }

// getter que obtiene la hora de atencion del cliente
Time Client::getAttentionTime() const {
  return attentionTime;
  }

// getter que obtiene la duracion de la llamada del cliente
Time Client::getCallDuration() const {
  return callDuration;
  }

// Metodo para convertir a cadena un objeto de la clase Client
string Client::toString() const {
  string result;
  ostringstream flow;

  flow << left;
  flow << setw(40) << name.toString();
  flow << setw(30) << attentionTime.toString();
  flow << setw(22) << callDuration.toString();

  result = flow.str();

  return result;
  }

// setter que le asigna un nombre al cliente
void Client::setName(const Name& n) {
  name = n;
  }

// setter que le asigna una hora de atencion al cliente
void Client::setAttentionTime(const Time& t) {
  attentionTime = t;
  }

// setter que le asigna una duracion de la llamada al cliente
void Client::setCallDuration(const Time& t) {
  callDuration = t;
  }

// Operador de asignacion
Client& Client::operator = (const Client& c) {
  name = c.name;
  attentionTime = c.attentionTime;
  callDuration = c.callDuration;

  return *this;
  }

// Desde aqui son puros operadores relacionales
bool Client::operator == (const Client& c) const {
  if(name == c.name) {
    return name == c.name;
    }

  return attentionTime == c.attentionTime;
  }

bool Client::operator != (const Client& c) const {
  if(name == c.name) {
    return name == c.name;
    }

  return attentionTime != c.attentionTime;
  }

bool Client::operator < (const Client& c) const {
  if(name == c.name) {
    return name == c.name;
    }

  return attentionTime < c.attentionTime;
  }

bool Client::operator <= (const Client& c) const {
  if(name == c.name) {
    return name == c.name;
    }

  return attentionTime <= c.attentionTime;
  }

bool Client::operator > (const Client& c) const {
  if(name == c.name) {
    return name == c.name;
    }

  return attentionTime > c.attentionTime;
  }

bool Client::operator >= (const Client& c) const {
  if(name == c.name) {
    return name == c.name;
    }

  return attentionTime >= c.attentionTime;
  }

// Estos dos ultimos metodos son operadores de flujo
ostream& operator << (ostream& os, const Client& c) {
  os << c.name << endl;
  os << c.attentionTime << endl;
  os << c.callDuration;

  return os;
  }

istream& operator >> (istream& is, Client& c) {
  is >> c.name;
  is >> c.attentionTime;
  is >> c.callDuration;

  return is;
  }
