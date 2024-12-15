#ifndef COLUMN_H
#define COLUMN_H

#include <string>

class Column
{
private:
  std::string name_;
  std::string type_;

public:
  Column(const std::string &name, const std::string &type);

  virtual std::string get_name();

  virtual std::string get_type();
};

#endif