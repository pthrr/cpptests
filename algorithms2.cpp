#include <algorithm>
#include <print>
#include <vector>

auto main() -> int
{
    auto vec = std::vector< int >{ 1, 2, 3, 3 };
    std::println( "== 2: {}", std::count( vec.begin(), vec.end(), 2 ) );
    std::println(
        "< 3: {}", std::count_if( vec.begin(), vec.end(), []( auto i ) -> bool { return i < 3; } ) );
    return 0;
}