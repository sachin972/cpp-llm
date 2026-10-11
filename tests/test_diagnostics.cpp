
#include "llm/diagnostics.hpp"

#include <cmath>
#include <exception>
#include <iostream>
#include <limits>
#include <string_view>

namespace
{

    int tests_passed = 0;
    int tests_failed = 0;

    void expect(bool condition, std::string_view description)
    {
        if (condition)
        {
            ++tests_passed;
            std::cout << "[PASS] " << description << '\n';
        }
        else
        {
            ++tests_failed;
            std::cerr << "[FAIL] " << description << '\n';
        }
    }

    template <typename Function>
    void expect_domain_error(
        Function &&function,
        std::string_view description)
    {
        try
        {
            function();
            expect(false, description);
        }
        catch (const std::domain_error &)
        {
            expect(true, description);
        }
        catch (const std::exception &)
        {
            expect(false, "Unexpected exception type");
        }
    }

    void test_finite_values()
    {
        expect(
            llm::diagnostics::is_finite(0.0),
            "Zero is finite");

        expect(
            llm::diagnostics::is_finite(-12.5),
            "Negative decimal is finite");

        expect(
            llm::diagnostics::is_finite(
                std::numeric_limits<double>::max()),
            "Maximum finite double is finite");
    }

    void test_non_finite_values()
    {
        expect(
            !llm::diagnostics::is_finite(
                std::numeric_limits<double>::infinity()),
            "Infinity is not finite");

        expect(
            !llm::diagnostics::is_finite(
                std::numeric_limits<double>::quiet_NaN()),
            "NaN is not finite");
    }

    void test_require_finite()
    {
        llm::diagnostics::require_finite(
            0.25,
            "test value");

        expect_domain_error(
            []
            {
                llm::diagnostics::require_finite(
                    std::numeric_limits<double>::quiet_NaN(),
                    "test value");
            },
            "Invalid numerical input throws domain_error");
    }

} // namespace

int main()
{
    test_finite_values();
    test_non_finite_values();
    test_require_finite();

    std::cout << "\nTests passed: " << tests_passed << '\n';
    std::cout << "Tests failed: " << tests_failed << '\n';

    return tests_failed == 0 ? 0 : 1;
}
