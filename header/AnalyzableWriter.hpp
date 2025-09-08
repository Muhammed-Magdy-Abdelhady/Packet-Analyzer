#pragma once

#include <ostream>
#include "Analyzable.hpp"

class AnalyzableWriter {
public:
    static void writeAnalyzable(std::ostream &os, const Analyzable &analyzable);
};