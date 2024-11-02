#include <algorithm>
#include <compare>
#include <execution>
#include <print>
#include <vector>

struct Int
{
    Int( int i )
        : i( i )
    {
    }

    auto operator<=>( Int const& other ) const -> std::strong_ordering
    {
        return i <=> other.i;
    }

    int i{};
};

auto main() -> int
{
    auto vec = std::vector< Int >{ 1, 3, 2, 6, 5 };
    std::sort( std::execution::par, vec.begin(), vec.end() );

    for( auto const& x : vec ) {
        std::println( "{}", x.i );
    }

    return 0;
}