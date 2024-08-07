// Esta es la implementacion de la clase 'Time'
#include "time.h"

using namespace std;

// Este metodo privado valida si una hora es valida
bool Time::isValid(const int& h, const int& m) const {
  return h >= 0 and h < 24 and m >=0 and m < 60;
  }

// Este metodo privado convierte en entero un objeto de tipo Time
int Time::toInt() const {
  return hour * 100 + minute;
  }

// Constructor base
Time::Time() {
  chrono::system_clock::time_point today = chrono::system_clock::now();
  time_t tt;
  tt = chrono::system_clock::to_time_t (today);
  struct tm* timeinfo;
  timeinfo = localtime(&tt);

  hour = timeinfo->tm_hour;
  minute = timeinfo->tm_min;
  }

// Constructor copia
Time::Time(const Time& t) : hour(t.hour), minute(t.minute) { }

// Constructor parametrizado
Time::Time(const int& h, const int& m) : Time() {
  if(isValid(h, m)){
    hour = h;
    minute = m;
    }
  }

// getter que obtiene la hora de un objeto de tipo Time
int Time::getHour() const {
  return hour;
  }

// getter que obtiene el minuto o los minutos de un objeto de tipo Time
int Time::getMinute() const {
  return minute;
  }

// setter que asigna una hora a un objeto de tipo Time
void Time::setHour(const int& h) {
  if(isValid(h, minute)){
    hour = h;
    }
  }

// setter que asigna un minuto o minutos a un objeto de tipo Time
void Time::setMinute(const int& m) {
  if(isValid(hour, m)){
    minute = m;
    }
  }

// Metodo que convierte a cadena un objeto de tipo Time
string Time::toString() const {
  char result[6];

  sprintf(result, "%02i:%02i", hour, minute);

  return result;
  }

// Operador de asignacion
Time& Time::operator = (const Time& t) {
  hour = t.hour;
  minute = t.minute;

  return *this;
  }

// A partir de aqui son puros operadores relacionales
bool Time::operator == (const Time& t) const {
  return toInt() == t.toInt();
  }

bool Time::operator != (const Time& t) const {
  return toInt() != t.toInt();
  }

bool Time::operator < (const Time& t) const {
  return toInt() < t.toInt();
  }

bool Time::operator <= (const Time& t) const {
  return toInt() <= t.toInt();
  }

bool Time::operator > (const Time& t) const {
  return toInt() > t.toInt();
  }

bool Time::operator >= (const Time& t) const {
  return toInt() >= t.toInt();
  }

// Estos dos ultimos metodos son operadores de flujo
ostream& operator << (ostream& os, const Time& t) {
  os << t.toString();

  return os;
  }

istream& operator >> (istream& is, Time& t) {
  string myStr;

  getline(is, myStr, ':');
  t.hour = atoi(myStr.c_str());

  getline(is, myStr);
  t.minute = atoi(myStr.c_str());

  return is;
  }
