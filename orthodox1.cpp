#include <concepts>
#include <print>

template< typename T >
concept Loggable = requires( T t, const std::string& msg ) {
    { t.log( msg ) } -> std::same_as< void >;
};

struct LoggerMixin
{
    template< Loggable Self >
    void logAndPrint( this Self&& self, const std::string& msg )
    {
        self.log( msg );
        std::println( "Printed: {}", msg );
    }
};

struct MyClass : public LoggerMixin
{
    void log( const std::string& msg )
    {
        std::println( "Logging: {}", msg );
    }

    void doSomething()
    {
        logAndPrint( "Doing something important" );
    }
};

int main()
{
    MyClass obj;
    obj.doSomething();
    return 0;
}
