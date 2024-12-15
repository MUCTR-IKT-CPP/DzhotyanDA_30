#ifndef VALUE_HASH_H
#define VALUE_HASH_H

#include <bits/c++config.h>
#include "value.h"
#include <cstdint>

struct KeyHash
{
    std::size_t operator()(const Value &k) const
    {
        return std::hash<std::int64_t>()(reinterpret_cast<intptr_t>(k.column_.get())) ^
               (std::hash<std::string>()(k.data_) << 1);
    }
};

struct KeyEqual
{
    bool operator()(const Value& lhs, const Value& rhs) const
    {
        return lhs.column_.get() == rhs.column_.get() && lhs.data_ == rhs.data_;
    }
};

#endif
