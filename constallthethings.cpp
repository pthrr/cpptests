#include <string>

using namespace std::literals::string_literals;

struct Squeezer
{
    auto squeeze( std::string const& inp, std::string* outp ) const -> void
    {
        *outp = *outp + inp + std::string( 1, m_sep );
    }

    constexpr auto getSep() const -> char
    {
        return m_sep;
    }

private:
    char m_sep = ';';
};

auto main() -> int
{
    std::string s;
    constexpr Squeezer m;
    m.squeeze( "1"s, &s );
    m.squeeze( "2"s, &s );
    std::printf( "%s\n", s.c_str() );
}