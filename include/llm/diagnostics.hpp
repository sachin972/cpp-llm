#pragma once

#include <string_view>

namespace llm::diagnostics
{

    [[nodiscard]] bool is_finite(double value) noexcept;

    void require_finite(
        double value,
        std::string_view description);

} // namespace llm::diagnostics