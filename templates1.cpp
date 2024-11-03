#include <concepts>
#include <ranges>
#include <string>
#include <vector>

template< typename T >
concept Indexable = std::ranges::random_access_range< T >;

auto x( Indexable auto a ) -> decltype( a[0] )
{
    return a[0];
}

auto main() -> int
{
    auto vec = std::vector< int >{ 1, 2, 3 };
    std::printf( "%s\n", std::to_string( x( vec ) ).c_str() );
    return 0;
}