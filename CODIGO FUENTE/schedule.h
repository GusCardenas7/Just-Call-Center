// Esta definicion es de la clase 'Schedule'
#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include <iostream>
#include <string>

#include "time.h"

class Schedule {
private:
  std::string startDay;
  std::string endDay;
  Time startTime;
  Time endTime;

public:
  Schedule();
  Schedule(const Schedule&);

  std::string getStartDay() const;
  std::string getEndDay() const;
  Time getStartTime() const;
  Time getEndTime() const;

  void setStartDay(const std::string&);
  void setEndDay(const std::string&);
  void setStartTime(const Time&);
  void setEndTime(const Time&);

  std::string toString() const;

  Schedule& operator = (const Schedule&);
  bool operator == (const Schedule&) const;
  bool operator != (const Schedule&) const;
  bool operator < (const Schedule&) const;
  bool operator <= (const Schedule&) const;
  bool operator > (const Schedule&) const;
  bool operator >= (const Schedule&) const;

  friend std::ostream& operator << (std::ostream&, const Schedule&);
  friend std::istream& operator >> (std::istream&, Schedule&);
};

#endif
