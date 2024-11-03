#include <print>
#include <string>
#include <vector>

using namespace std::literals::string_literals;

struct Widget
{
    template< typename T >
        requires std::is_same_v< std::decay_t< T >, std::string >
    Widget( T&& name, float price, int quantity )
        : m_quantity( quantity )
        , m_price( price )
        , m_name( std::forward< T >( name ) )
    {
    }

    auto getName() const -> std::string
    {
        return m_name;
    }

private:
    int m_quantity;
    float m_price;
    std::string m_name;
};

struct Container
{
    int a;
    std::string b;
};

auto main() -> int
{
    auto i = 0;
    auto v = std::vector< int >{ 1, 2, 3, 4 };
    auto c = Container{ .a = 1, .b = "abcde" };

    auto [name, price, quantity] = std::make_tuple( "abc"s, 3.2f, i );
    auto w1 = Widget( name, price, quantity );
    std::printf( "%s\n", w1.getName().c_str() );

    name = "changed"s;
    auto w2 = Widget( std::move( name ), price, quantity );
    std::printf( "%s\n", w2.getName().c_str() );

    auto w3 = Widget( std::string( "new" ), price, quantity );
    std::printf( "%s\n", w3.getName().c_str() );

    return 0;
}