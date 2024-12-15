#ifndef IDCOLUMN_H
#define IDCOLUMN_H

#include "column.h"

const std::string IDENTITY_STR = "id";

class IdentityColumn : public Column {
public:
  IdentityColumn(const std::string &type);
};

#endif