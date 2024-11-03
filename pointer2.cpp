#include <memory>
#include <print>

auto main() -> int
{
    std::weak_ptr< int > wk;
    std::shared_ptr< int > ptr2;

    {
        auto ptr = std::shared_ptr< int >( new int( 5 ) );
        std::println( "{}", *ptr );
        ptr2 = ptr; // copied
        std::println( "{} {}", *ptr, *ptr2 );
        wk = ptr2;
    }

    if( std::shared_ptr< int > spt = wk.lock() ) {
        std::println( "{}", *spt );
    }
    else {
        std::println( "wk expired" );
    }

    return 0;
}