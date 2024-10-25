
#include <experimental/propagate_const>
#include <print>

struct My
{
    explicit My( int* x )
        : x( x )
    {
    }

    auto getX() const -> int
    {
        return *x;
    }

    auto setX( int v ) -> void
    {
        *x = v;
    }

    std::experimental::propagate_const< int* > x = nullptr;
    //int* x = nullptr;
};

auto main() -> int
{
    int y = 1;
    auto z = My( &y );
    std::printf( "%d\n", z.getX() );

    z.setX( 2 );
    std::printf( "%d\n", y );

    auto const& u = z;
    //*u.x = 3;
    std::printf( "%d\n", u.getX() );

    auto& o = z;
    auto* c = &o;
    *c->x = 4;
    std::printf( "%d\n", *c->x );

    [[maybe_unused]] auto& k = *c;
    return 0;
}