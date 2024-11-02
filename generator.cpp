#include <generator>
#include <print>

auto integerSquare( int x ) -> std::generator< int >
{
    for( auto i = 1; i <= x; ++i ) {
        co_yield i* i;
    }
}

auto main() -> int
{
    for( auto const& x : integerSquare( 5 ) ) {
        std::println( "{}", x );
    }
}