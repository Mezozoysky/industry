#include <string>

namespace ut
{

class BaseA
{
public:
    BaseA() = default;
    virtual ~BaseA() noexcept = default;

    // virtual std::string getControlString() = 0;
    virtual std::string getControlString()
    {
        return ( "BaseA" );
    }
};

class DerivedA0A : public BaseA
{
public:
    DerivedA0A() = default;
    virtual ~DerivedA0A() noexcept = default;

    virtual std::string getControlString() override
    {
        return ( "DerivedA0A" );
    }
};

class DerivedA0B : public BaseA
{
public:
    DerivedA0B() = default;
    virtual ~DerivedA0B() noexcept = default;

    virtual std::string getControlString() override
    {
        return ( "DerivedA0B" );
    }
};

} // namespace ut
