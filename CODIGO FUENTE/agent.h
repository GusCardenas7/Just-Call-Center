// Esta definicion es de la clase 'Agent'
#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include <iostream>
#include <string>

#include "name.h"
#include "schedule.h"
#include "time.h"
#include "clientlist.h"

class Agent {
private:
  std::string agentNumber;
  Name name;
  std::string specialty;
  std::string extensionNumber;
  Schedule schedule;
  std::string extraHours;
  ClientList clientList;

public:
  Agent();
  Agent(const Agent&);

  std::string getAgentNumber() const;
  Name getName() const;
  std::string getSpecialty() const;
  std::string getExtensionNumber() const;
  Schedule getSchedule() const;
  std::string getExtraHours() const;
  ClientList& getClientList();

  std::string toString(const bool&) const;

  void setAgentNumber(const std::string&);
  void setName(const Name&);
  void setSpecialty(const std::string&);
  void setExtensionNumber(const std::string&);
  void setSchedule(const Schedule&);
  void setExtraHours(const std::string&);
  void setClientList(const ClientList&);

  Agent& operator = (const Agent&);
  bool operator == (const Agent&) const;
  bool operator != (const Agent&) const;
  bool operator < (const Agent&) const;
  bool operator <= (const Agent&) const;
  bool operator > (const Agent&) const;
  bool operator >= (const Agent&) const;

  friend std::ostream& operator << (std::ostream&, const Agent&);
  friend std::istream& operator >> (std::istream&, Agent&);
};

#endif
