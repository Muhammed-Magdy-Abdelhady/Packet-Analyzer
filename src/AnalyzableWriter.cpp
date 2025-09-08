#include "AnalyzableWriter.hpp"

void AnalyzableWriter::writeAnalyzable(std::ostream &os, const Analyzable &analyzable) {
    auto result = analyzable.analyze();
    for (const auto& [key, value] : result) {
        os << key << ": " << value << "\n";
    }
}