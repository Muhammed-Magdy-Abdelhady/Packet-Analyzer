#pragma once

#include <string>
#include <utility>
#include <vector>

typedef std::vector<std::pair<std::string, std::string>> AnalysisResult;

class Analyzable {
public:
    virtual ~Analyzable() = default;
    virtual AnalysisResult analyze() const = 0;
};