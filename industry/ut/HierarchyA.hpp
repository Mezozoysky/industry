#include <string>

namespace ut
{

class BaseA
{
public:
    BaseA()
    {
        mControlString = "BaseA";
    }

    virtual ~BaseA() noexcept = default;

    // virtual void abstractMethod() = 0;
    const std::string& getControlString() const noexcept
    {
        return ( mControlString );
    }

    void setControlString( const std::string& str ) noexcept
    {
        mControlString = str;
    }

protected:
    std::string mControlString;
};

class DerivedA0A : public BaseA
{
public:
    DerivedA0A()
    : BaseA()
    {
        mControlString = "DerivedA0A";
    }

    virtual ~DerivedA0A() noexcept = default;
};

class DerivedA0B : public BaseA
{
public:
    DerivedA0B()
    : BaseA()
    {
        mControlString = "DerivedA0B";
    }

    virtual ~DerivedA0B() noexcept = default;
};

} // namespace ut
