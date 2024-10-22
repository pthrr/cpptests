#include <array>
#include <print>

namespace my_ns {

constexpr std::array< int, 3 > g_MY_ARR1 = { 1, 2, 3 }; // global, compile-time, compound
std::array< int, 3 > const g_MY_ARR2 = { 4, 5, 6 };     // global, run-time, compound

constexpr int g_MY_INT1 = 7; // global, compile-time, integral
int const g_MY_INT2 = 8;     // global, run-time, integral

struct MyClass
{
    static constexpr std::array< int, 3 > s_MY_ARR1 = { 1, 2, 3 }; // class, compile-time, compound
    static std::array< int, 3 > const s_MY_ARR2;                   // class, run-time, compound

    static constexpr int s_MY_INT1 = 7; // class, compile-time, integral
    static int const s_MY_INT2 = 8;     // class, run-time, integral

    auto print() -> void
    {
        for( auto const x : s_MY_ARR1 ) {
            std::printf( "%d\n", x );
        }

        for( auto const x : s_MY_ARR2 ) {
            std::printf( "%d\n", x );
        }

        std::printf( "%d\n", s_MY_INT1 );
        std::printf( "%d\n", s_MY_INT2 );
    }
};

std::array< int, 3 > const MyClass::s_MY_ARR2 = { 4, 5, 6 };

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
    m.print();
}