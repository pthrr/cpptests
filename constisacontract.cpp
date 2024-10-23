#include <concepts>
#include <print>
#include <string>

struct Elem
{
    int i;
    char const c;

    auto getString() const -> std::string
    {
        return std::string( 1, c );
    }
};

template< typename T >
concept Elementable = requires( T a ) {
    requires std::integral< decltype( a.i ) >;
    { a.getString() } -> std::same_as< std::string >;
};

static_assert( Elementable< Elem > );

template< Elementable T, std::size_t N >
auto myFun( std::array< T, N > const& arr ) -> void
{
    for( auto const& elem : arr ) {
        std::printf( "%i : %s\n", elem.i, elem.getString().c_str() );
    }
}

auto main() -> int
{
    std::array< Elem, 2 > my_arr = { { { 1, 'a' }, { 2, 'b' } } };
    myFun( my_arr );
    my_arr.at( 0 ).i = 4;
    myFun( my_arr );
    return 0;
}