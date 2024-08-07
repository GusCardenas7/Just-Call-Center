// Esta definicion es de la clase 'Name'
#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <iostream>
#include <string>

class Name {
private:
  std::string lastName;
  std::string firstName;

public:
  Name();
  Name(const Name&);
  Name(const std::string&, const std::string&);

  std::string getLastName() const;
  std::string getFirstName() const;

  void setLastName(const std::string&);
  void setFirstName(const std::string&);

  std::string toString() const;

  Name& operator = (const Name&);
  bool operator == (const Name&) const;
  bool operator != (const Name&) const;
  bool operator < (const Name&) const;
  bool operator <= (const Name&) const;
  bool operator > (const Name&) const;
  bool operator >= (const Name&) const;

  friend std::ostream& operator << (std::ostream&, const Name&);
  friend std::istream& operator >> (std::istream&, Name&);
};

#endif
