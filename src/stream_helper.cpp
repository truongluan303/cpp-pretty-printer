#include <type_traits>
#include <utility>
#include <iostream>
#include <sstream>


template<typename S, typename T>
class _streamable
{
    template<typename SS, typename TT>
    static auto test(int)
    -> decltype(std::declval<SS&>() << std::declval<TT>(), std::true_type());

    template<typename, typename>
    static auto test(...) -> std::false_type;

public:
    static const bool value = decltype(test<S, T>(0))::value;
};


template <typename T>
std::string streamable_to_s(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}


template <typename T>
std::string non_streamable_to_s(const T& obj)
{
    std::stringstream ss;
    ss << &obj;

    std::string type_name = typeid(obj).name();
    std::string addr = ss.str();

    return "<" + type_name + " " + addr + ">";
}


template <typename T>
std::string to_s(const T& obj)
{
    if constexpr (_streamable<std::stringstream, T>::value)
    {
        return streamable_to_s(obj);
    }
    return non_streamable_to_s(obj);
}
