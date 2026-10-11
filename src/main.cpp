
#include <iostream>
#include <string_view>

namespace llm
{

    constexpr std::string_view kProjectName = "cpp-llm";
    constexpr std::string_view kVersion = "0.1.0";

    void print_banner()
    {
        std::cout << "====================================\n";
        std::cout << "  " << kProjectName << " v" << kVersion << '\n';
        std::cout << "  From-scratch C++ language model\n";
        std::cout << "====================================\n";
    }

    void print_status()
    {
        std::cout << "\nPhase 0: Environment initialized\n";
        std::cout << "Language: C++20\n";
        std::cout << "Backend: CPU\n";
        std::cout << "Pretrained weights: None\n";
        std::cout << "Next milestone: Tensor engine\n";
    }

} // namespace llm

int main()
{
    llm::print_banner();
    llm::print_status();

    return 0;
}
