#include <cstdint>
#include <print>
#include <stdexcept>
#include <string>
#include <utility> // for std::to_underlying

enum struct Permission : uint8_t
{
    NONE = 0,
    READ = 1 << 0,
    WRITE = 1 << 1,
    EXECUTE = 1 << 2,
    ALL = READ | WRITE | EXECUTE,
};

constexpr auto operator|( Permission lhs, Permission rhs ) -> Permission
{
    return static_cast< Permission >( std::to_underlying( lhs ) | std::to_underlying( rhs ) );
}

constexpr auto operator|=( Permission& lhs, Permission rhs ) -> Permission&
{
    lhs = lhs | rhs;
    return lhs;
}

constexpr auto operator==( Permission lhs, Permission rhs ) -> bool
{
    return std::to_underlying( lhs ) == std::to_underlying( rhs );
}

constexpr std::array< std::pair< Permission, std::string_view >, 5 > permission_to_string = {
    { { Permission::NONE, "None" }, { Permission::READ, "Read" }, { Permission::WRITE, "Write" },
        { Permission::EXECUTE, "Execute" }, { Permission::ALL, "All" } } };

auto toString( Permission perm ) -> std::string
{
    std::string result;
    bool first = true;

    for( const auto& pair : permission_to_string ) {
        if( pair.first != Permission::ALL && std::to_underlying( perm ) & std::to_underlying( pair.first ) ) {
            if( not first ) {
                result += " | ";
            }

            result += pair.second;
            first = false;
        }
    }

    return result.empty() ? "Unknown" : result;
}

constexpr auto fromStr( char const* name ) -> Permission
{
    for( auto const& pair : permission_to_string ) {
        if( pair.second == std::string_view( name ) ) {
            return pair.first;
        }
    }

    throw std::invalid_argument( "Unknown enum value" );
}

auto main() -> int
{
    constexpr Permission perm = fromStr( "Read" ) | fromStr( "Write" );
    std::printf( "%s\n", toString( perm ).c_str() );
    return 0;
}
