#include <vector>

struct CopyMove
{
    void set_data( std::vector< int > x )
    {
        m_data = std::move( x );
    }

private:
    std::vector< int > m_data{};
};

struct DefaultDtor // copied
{
    ~DefaultDtor() {}

private:
    std::vector< int > m_data{};
};

struct RuleOfZero
{
    explicit RuleOfZero( std::vector< int > data )
        : m_data( std::move( data ) )
    {
    }

private:
    std::vector< int > m_data;
};

auto main() -> int
{
    auto x = std::vector< int >{ 1, 2, 3, 4 };

    auto a1 = RuleOfZero( x );
    auto a2 = RuleOfZero( std::move( x ) );
    return 0;
}