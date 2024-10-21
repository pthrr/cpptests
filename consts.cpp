#include <array>
#include <print>

namespace my_ns {

constexpr std::array< int, 3 > g_MY_ARR1 = { 1, 2, 3 }; // global, compile-time, compound
const std::array< int, 3 > g_MY_ARR2 = { 4, 5, 6 };     // global, run-time, compound

constexpr int g_MY_INT1 = 7; // global, compile-time, integral
const int g_MY_INT2 = 8;     // global, run-time, integral

struct MyClass
{
    static constexpr std::array< int, 3 > s_MY_ARR1 = { 1, 2, 3 }; // class, compile-time, compound
    static const std::array< int, 3 > s_MY_ARR2;                   // class, run-time, compound

    static constexpr int s_MY_INT1 = 7; // class, compile-time, integral
    static const int s_MY_INT2 = 8;     // class, run-time, integral
};

const std::array< int, 3 > MyClass::s_MY_ARR2 = { 4, 5, 6 };

}

auto main() -> int
{
    for( auto const x : my_ns::g_MY_ARR1 ) {
        std::printf( "%d\n", x );
    }

    for( auto const x : my_ns::g_MY_ARR2 ) {
        std::printf( "%d\n", x );
    }

    std::printf( "%d\n", my_ns::g_MY_INT1 );
    std::printf( "%d\n", my_ns::g_MY_INT2 );

    my_ns::MyClass m;

    for( auto const x : m.s_MY_ARR1 ) {
        std::printf( "%d\n", x );
    }

    for( auto const x : m.s_MY_ARR2 ) {
        std::printf( "%d\n", x );
    }

    std::printf( "%d\n", m.s_MY_INT1 );
    std::printf( "%d\n", m.s_MY_INT2 );
}