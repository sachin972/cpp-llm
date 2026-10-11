#include "llm/diagnostics.hpp"

#include <iostream>

using namespace std;

int main()
{
    cout << "====================================\n";
    cout << "  cpp-llm v0.1.0\n";
    cout << "  From-scratch C++ language model\n";
    cout << "====================================\n";

    const double sample_value = 0.5;

    if (!llm::diagnostics::is_finite(sample_value))
    {
        cerr << "Diagnostic check failed.\n";
        return 1;
    }

    cout << "\nPhase 0B: Diagnostics initialized\n";
    cout << "C++ standard: C++20\n";
    cout << "Numerical diagnostics: Ready\n";
    cout << "Next milestone: Tensor engine\n";

    return 0;
}