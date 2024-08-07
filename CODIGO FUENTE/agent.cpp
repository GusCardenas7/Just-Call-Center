// Esta es la implementacion de la clase 'Agent'
#include "agent.h"

using namespace std;

// Constructor base
Agent::Agent() { }

// Constructor copia con delegaciones de constructores
Agent::Agent(const Agent& a) : agentNumber(a.agentNumber), name(a.name), specialty(a.specialty), extensionNumber(a.extensionNumber), schedule(a.schedule), extraHours(a.extraHours), clientList(a.clientList) { }

// getter que obtiene lo que contenga el atributo agentNumber
string Agent::getAgentNumber() const {
  return agentNumber;
  }

// getter que obtiene lo que contenga el atributo name
Name Agent::getName() const {
  return name;
  }

// getter que obtiene lo que contenga el atributo specialty
string Agent::getSpecialty() const {
  return specialty;
  }

// getter que obtiene lo que contenga el atributo extensionNumber
string Agent::getExtensionNumber() const {
  return extensionNumber;
  }

// getter que obtiene lo que contenga el atributo schedule
Schedule Agent::getSchedule() const {
  return schedule;
  }

// getter que obtiene lo que contenga el atributo extraHours
string Agent::getExtraHours() const {
  return extraHours;
  }

// getter que obtiene lo que contenga el atributo clientList por referencia
ClientList& Agent::getClientList() {
  return clientList;
  }

// Metodo para convertir a cadena un objeto de la clase Agent
string Agent::toString(const bool& subList = false) const {
  string result;
  ostringstream flow;

  flow << left;
  flow << "| ";
  flow << "Numero de empleado: ";
  flow << setw(6) << agentNumber;
  flow << " | ";
  flow << "Nombre del agente: ";
  flow << setw(40) << name.toString();
  flow << " | ";
  flow << "Especialidad: ";
  flow << setw(15) << specialty;
  flow << " | ";
  flow << "Numero de extension: #";
  flow << setw(5) << extensionNumber;
  flow << "\n";
  flow << "| ";
  flow << "Horario: ";
  flow << setw(17) << schedule.toString();
  flow << " | ";
  flow << "Horas extras: ";
  flow << setw(5) << extraHours;

  if(subList) {
    flow << "\n";
    flow << "--------------------------------------------------------------------------------------------";
    flow << "\n";
    flow << "                                LISTA DE CLIENTES ATENDIDOS                                 ";
    flow << "\n";
    flow << "--------------------------------------------------------------------------------------------";
    flow << "\n";
    flow << clientList.toString();
    flow << "--------------------------------------------------------------------------------------------";
    }

  result = flow.str();

  return result;
  }

// setter que le asigna un numero de agente a un objeto de tipo Agent
void Agent::setAgentNumber(const string& a) {
  agentNumber = a;
  }

// setter que le asigna un nombre a un objeto de tipo Agent
void Agent::setName(const Name& n) {
  name = n;
  }

// setter que le asigna una especialidad a un objeto de tipo Agent
void Agent::setSpecialty(const string& s) {
  specialty = s;
  }

// setter que le asigna un numero de extension a un objeto de tipo Agent
void Agent::setExtensionNumber(const string& e) {
  extensionNumber = e;
  }

// setter que le asigna un horario a un objeto de tipo Agent
void Agent::setSchedule(const Schedule& s) {
  schedule = s;
  }

// setter que le asigna horas extra a un objeto de tipo Agent
void Agent::setExtraHours(const string& e) {
  extraHours = e;
  }

// setter que le asigna una lista de clientes a un objeto de tipo Agent
void Agent::setClientList(const ClientList& l) {
  clientList = l;
  }

// Operador de asignacion
Agent& Agent::operator = (const Agent& a) {
  agentNumber = a.agentNumber;
  name = a.name;
  specialty = a.specialty;
  extensionNumber = a.extensionNumber;
  schedule = a.schedule;
  extraHours = a.extraHours;
  clientList = a.clientList;

  return *this;
  }

// A partir de aqui son puros operadores relacionales
bool Agent::operator == (const Agent& a) const {
  if(name == a.name) {
    return name == a.name;
    }

  if(specialty == a.specialty) {
    return specialty == a.specialty;
    }

  return agentNumber == a.agentNumber;
  }

bool Agent::operator != (const Agent& a) const {
  if(name != a.name) {
    return name != a.name;
    }

  if(specialty != a.specialty) {
    return specialty != a.specialty;
    }

  return agentNumber != a.agentNumber;
  }

bool Agent::operator < (const Agent& a) const {
  if(name < a.name) {
    return name < a.name;
    }

  if(specialty < a.specialty) {
    return specialty < a.specialty;
    }

  return agentNumber < a.agentNumber;
  }

bool Agent::operator <= (const Agent& a) const {
  if(name <= a.name) {
    return name <= a.name;
    }

  if(specialty <= a.specialty) {
    return specialty <= a.specialty;
    }

  return agentNumber <= a.agentNumber;
  }

bool Agent::operator > (const Agent& a) const {
  if(name > a.name) {
    return name > a.name;
    }

  if(specialty > a.specialty) {
    return specialty > a.specialty;
    }

  return agentNumber > a.agentNumber;
  }

bool Agent::operator >= (const Agent& a) const {
  if(name >= a.name) {
    return name >= a.name;
    }

  if(specialty >= a.specialty) {
    return specialty >= a.specialty;
    }

  return agentNumber >= a.agentNumber;
  }

// Estos dos ultimos metodos o funciones son operadores de flujo
ostream& operator << (ostream& os, const Agent& a) {
  os << a.agentNumber << endl;
  os << a.name << endl;
  os << a.specialty << endl;
  os << a.extensionNumber << endl;
  os << a.schedule << endl;
  os << a.extraHours;

  return os;
  }

istream& operator >> (istream& is, Agent& a) {
  getline(is, a.agentNumber);
  is >> a.name;
  getline(is, a.specialty);
  getline(is, a.extensionNumber);
  is >> a.schedule;
  getline(is, a.extraHours);

  return is;
  }
