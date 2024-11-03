#include <print>

auto main() -> int
{
    [[maybe_unused]] auto value = 2;
    constexpr auto fun = [value = []() { return 3; }()]() { std::println( "{}", value ); };
    fun();
    return 0;
}