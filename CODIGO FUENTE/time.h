// Esta definicion es de la clase 'Time'
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <cstdlib>

class Time {
private:
  int hour;
  int minute;

  bool isValid(const int&, const int&) const;
  int toInt() const;

public:
  Time();
  Time(const Time&);
  Time(const int&, const int&);

  int getHour() const;
  int getMinute() const;

  void setHour(const int&);
  void setMinute(const int&);

  std::string toString() const;

  Time& operator = (const Time&);
  bool operator == (const Time&) const;
  bool operator != (const Time&) const;
  bool operator < (const Time&) const;
  bool operator <= (const Time&) const;
  bool operator > (const Time&) const;
  bool operator >= (const Time&) const;

  friend std::ostream& operator << (std::ostream&, const Time&);
  friend std::istream& operator >> (std::istream&, Time&);
};

#endif
