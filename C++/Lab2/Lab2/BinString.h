#pragma once
#include <string>
#include "Type.h"

class BinString : public Type {
public:
    std::string c;
    std::string d;

    void Create1() override;
    void Create2() override;
    bool IsBinaryString(const std::string& str);
    void Init() override;
};
