#pragma once
#include <string>
#include "Type.h"

class SymbString : public Type {
public:
    std::string a = "";
    std::string b = "";

    void Create1() override;
    void Create2() override;
    void Init() override;
};
