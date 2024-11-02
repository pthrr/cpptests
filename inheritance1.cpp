#include <print>

struct Base
{
    virtual auto do_thing() -> void = 0;
    virtual auto do_another_thing() -> void;

    virtual ~Base() = default;
    Base() = default;

    Base( Base const& ) = default;
    auto operator=( Base const& ) -> Base& = default;

    Base( Base&& ) noexcept = default;
    auto operator=( Base&& ) noexcept -> Base& = default;
};

auto Base::do_another_thing() -> void
{
    std::println( "doing another {} thing", 1 );
}

struct Derived : protected Base
{
    auto do_same_thing() -> void
    {
        do_another_thing();
    };

    void do_thing() override;

    ~Derived() = default;
    Derived() = default;

    Derived( Derived const& ) = default;
    auto operator=( Derived const& ) -> Derived& = default;

    Derived( Derived&& ) noexcept = default;
    auto operator=( Derived&& ) noexcept -> Derived& = default;
};

auto Derived::do_thing() -> void
{
    std::println( "doing {} thing", 1 );
}

auto main() -> int
{
    auto d = new Derived();
    d->do_thing();
    d->do_same_thing();
    delete d;
    return 0;
}