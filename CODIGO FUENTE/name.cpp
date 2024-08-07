// Esta es la implementacion de la clase 'Name'
#include "name.h"

using namespace std;

// Constructor base
Name::Name() { }

// Contructor copia
Name::Name(const Name& n) : lastName(n.lastName), firstName(n.firstName) { }

// Constructor parametrizado
Name::Name(const std::string& l, const std::string& f) : Name() {
  lastName = l;
  firstName = f;
  }

// getter que obtiene el apellido del objeto Name
string Name::getLastName() const {
  return lastName;
  }

// getter que obtiene el nombre del objeto Name
string Name::getFirstName() const {
  return firstName;
  }

// setter que asigna el apellido a un objeto de tipo Name
void Name::setLastName(const std::string& l) {
  lastName = l;
  }

// setter que asigna el nombre a un objeto de tipo Name
void Name::setFirstName(const std::string& f) {
  firstName = f;
  }

// Metodo que convierte a cadena un objeto de tipo Name
string Name::toString() const {
  string result;

  result = lastName;
  result += ",";
  result += firstName;

  return result;
  }

// Operador de asignacion
Name& Name::operator = (const Name& n) {
  lastName = n.lastName;
  firstName = n.firstName;

  return *this;
  }

// Desde aqui son puros operadores relacionales
bool Name::operator == (const Name& n) const {
  return toString() == n.toString();
  }

bool Name::operator != (const Name& n) const {
  return toString() != n.toString();
  }

bool Name::operator < (const Name& n) const {
  return toString() < n.toString();
  }

bool Name::operator <= (const Name& n) const {
  return toString() <= n.toString();
  }

bool Name::operator > (const Name& n) const {
  return toString() > n.toString();
  }

bool Name::operator >= (const Name& n) const {
  return toString() >= n.toString();
  }

// Estos dos ultimos metodos son operadores de flujo
ostream& operator << (ostream& os, const Name& n) {
  os << n.toString();

  return os;
  }

istream& operator >> (istream& is, Name& n) {
  getline(is, n.lastName, ',');
  getline(is, n.firstName);

  return is;
  }
