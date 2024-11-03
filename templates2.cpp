#include <print>
#include <type_traits>

template< typename... T >
auto sum( T const&... args ) -> decltype( auto )
{
    return ( args + ... );
}

template< typename... T >
auto sum2( T const&... args ) -> std::common_type_t< T... >
{
    return ( args + ... );
}

auto main() -> int
{
    std::println( "{}", sum( 1, 2, 3 ) );
    std::println( "{}", sum2( 1, 2, 3 ) );
    return 0;
}