// Esta es la implementacion de la clase 'Schedule'
#include "schedule.h"

using namespace std;

// Constructor base
Schedule::Schedule() { }

// Constructor copia con delegaciones de constructores
Schedule::Schedule(const Schedule& s) : startDay(s.startDay), endDay(s.endDay), startTime(s.startTime), endTime(s.endTime) { }

// getter para obtener lo que contenga el atributo startDay
string Schedule::getStartDay() const {
  return startDay;
  }

// getter para obtener lo que contenga el atributo endDay
string Schedule::getEndDay() const {
  return endDay;
  }

// getter para obtener lo que contenga el atributo startTime
Time Schedule::getStartTime() const {
  return startTime;
  }

// getter para obtener lo que contenga el atributo endTime
Time Schedule::getEndTime() const {
  return endTime;
  }

// setter que le asigna un valor a el atributo startDay
void Schedule::setStartDay(const std::string& s) {
  startDay = s;
  }

// setter que le asigna un valor a el atributo endDay
void Schedule::setEndDay(const std::string& e) {
  endDay = e;
  }

// setter que le asigna un valor a el atributo startTime
void Schedule::setStartTime(const Time& t) {
  startTime = t;
  }

// setter que le asigna un valor a el atributo endTime
void Schedule::setEndTime(const Time& t) {
  endTime = t;
  }

// Metodo que convierte a cadena un objeto de la clase Schedule
string Schedule::toString() const {
  string result;

  result = startDay;
  result += "-";
  result += endDay;
  result += "/ ";
  result += startTime.toString();
  result += "-";
  result += endTime.toString();

  return result;
  }

// Operador de asignacion
Schedule& Schedule::operator = (const Schedule& s) {
  startDay = s.startDay;
  endDay = s.endDay;
  startTime = s.startTime;
  endTime = s.endTime;

  return *this;
  }

// A partir de aqui son puros operadores relacionales
bool Schedule::operator == (const Schedule& s) const {
  return toString() == s.toString();
  }

bool Schedule::operator != (const Schedule& s) const {
  return toString() != s.toString();
  }

bool Schedule::operator < (const Schedule& s) const {
  return toString() < s.toString();
  }

bool Schedule::operator <= (const Schedule& s) const {
  return toString() <= s.toString();
  }

bool Schedule::operator > (const Schedule& s) const {
  return toString() > s.toString();
  }

bool Schedule::operator >= (const Schedule& s) const {
  return toString() >= s.toString();
  }

// Estos dos ultimos metodos o funciones son operadores de flujo
ostream& operator << (ostream& os, const Schedule& s) {
  os << s.toString();

  return os;
  }

istream& operator >> (istream& is, Schedule& s) {
  string myStr;

  getline(is, s.startDay, '-');
  getline(is, s.endDay, '/');
  getline(is, myStr, ':');
  s.startTime.setHour(atoi(myStr.c_str()));
  getline(is, myStr, '-');
  s.startTime.setMinute(atoi(myStr.c_str()));
  getline(is, myStr, ':');
  s.endTime.setHour(atoi(myStr.c_str()));
  getline(is, myStr);
  s.endTime.setMinute(atoi(myStr.c_str()));

  return is;
  }
