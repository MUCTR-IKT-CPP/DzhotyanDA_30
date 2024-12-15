#include "identity_column.h"

IdentityColumn::IdentityColumn(const std::string &type) : Column(IDENTITY_STR, type) {}
