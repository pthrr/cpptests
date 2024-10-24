#include <concepts>
#include <string>

template< typename T >
concept Interface = requires( T a ) {
    { a.myFun() } -> std::same_as< bool >;
};

template< class Derived >
struct Base
{
    auto myFun() -> bool
    {
        return static_cast< Derived* >( this )->myFunImpl();
    }
};

struct Derived : Base< Derived >
{
    auto myFunImpl() const -> bool
    {
        return true;
    }
};

static_assert( Interface< Derived >, "Derived must satisfy the InterfaceDerived concept" );

auto main() -> int
{
    Derived d;
    std::printf( "%s\n", std::to_string( d.myFun() ).c_str() );
}
