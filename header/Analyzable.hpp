#pragma once

class Analyzable {
public:
    virtual ~Analyzable() = default;
    virtual void analyze() = 0;
};