#include "llm/diagnostics.hpp"

#include <cmath>
#include <stdexcept>
#include <string>

namespace llm::diagnostics
{

    bool is_finite(double value) noexcept
    {
        return std::isfinite(value);
    }

    void require_finite(
        double value,
        std::string_view description)
    {
        if (!is_finite(value))
        {
            throw std::domain_error(
                std::string(description) +
                " must be a finite number");
        }
    }

} // namespace llm::diagnostics