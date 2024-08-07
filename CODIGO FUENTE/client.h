// Esta definicion es de la clase 'Client'
#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "name.h"
#include "time.h"

class Client {
private:
  Name name;
  Time attentionTime;
  Time callDuration;

public:
  Client();
  Client(const Client&);

  Name getName() const;
  Time getAttentionTime() const;
  Time getCallDuration() const;

  std::string toString() const;

  void setName(const Name&);
  void setAttentionTime(const Time&);
  void setCallDuration(const Time&);

  Client& operator = (const Client&);
  bool operator == (const Client&) const;
  bool operator != (const Client&) const;
  bool operator < (const Client&) const;
  bool operator <= (const Client&) const;
  bool operator > (const Client&) const;
  bool operator >= (const Client&) const;

  friend std::ostream& operator << (std::ostream&, const Client&);
  friend std::istream& operator >> (std::istream&, Client&);
};

#endif
