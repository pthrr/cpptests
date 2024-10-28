#include <future>
#include <print>
#include <string>
#include <thread>
#include <vector>

using namespace std::literals::string_literals;

auto main() -> int
{
    using Fut = std::future< std::string >;
    using Prom = std::promise< std::string >;

    std::vector< std::jthread > threads;
    std::vector< Fut > futures;

    auto const msg = "Printed from thread";
    constexpr auto num_threads = 3;

    auto fun = [&msg]( int id, Prom result ) {
        auto res = std::format( "{} {}", msg, id );
        return result.set_value( res );
    };

    for( auto i = 1; i <= num_threads; ++i ) {
        Prom result;
        futures.push_back( result.get_future() );
        threads.emplace_back( fun, i, std::move( result ) );
    }

    for( auto& fut : futures ) {
        std::printf( "%s\n", fut.get().c_str() );
    }

    return 0;
}