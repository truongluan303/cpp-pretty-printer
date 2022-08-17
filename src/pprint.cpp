#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>

#include "stream_helper.h"


template <typename T>
std::string PrettyPrinter::str_repr(const T& obj)
{
    return str_repr(obj, 0);
}


template <typename Iter>
std::string PrettyPrinter::str_repr(Iter begin, Iter end)
{
    return str_repr(begin, end, "[", "]");
}


template <typename T>
std::string PrettyPrinter::pretty_str_repr(const T& obj)
{
    return str_repr(obj, 1);
}


template <typename T>
void PrettyPrinter::puts(const T& obj)
{
    std::cout << str_repr(obj, 0) << std::endl;
}


template <typename T>
void PrettyPrinter::pretty_puts(const T& obj)
{
    std::cout << str_repr(obj, 1) << std::endl;
}


template <typename T>
std::string PrettyPrinter::str_repr(const T& obj, const bool& should_prettify)
{
    if constexpr (_streamable<std::stringstream, T>::value)
    {
        return streamable_to_s(obj);
    }
    return non_streamable_to_s(obj);
}


template <typename T>
std::string PrettyPrinter::str_repr(
    const std::vector<T>& vec,
    const bool& should_prettify
)
{
    return iter_to_s(vec, should_prettify, "[", "]");
}


template <class Key,
          class T,
          class Hash,
          class Pred,
          class Alloc>
std::string PrettyPrinter::str_repr(
    const std::unordered_map<Key, T, Hash, Pred, Alloc>& umap,
    const bool& should_prettify
)
{
    return generic_map_to_s(umap, should_prettify);
}


template <class Key,
            class T,
            class Compare,
            class Alloc>
std::string PrettyPrinter::str_repr(
    const std::map<Key, T, Compare, Alloc>& omap,
    const bool& should_prettify
)
{
    return generic_map_to_s(omap, should_prettify);
}


template <typename MAP>
std::string PrettyPrinter::generic_map_to_s(
    const MAP& m,
    const bool& should_prettify
)
{
    if (m.size() == 0) return "{}";

    std::string res = "{";
    size_t i = 0;

    for (auto kvp : m)
    {
        auto k = kvp.first;
        auto v = kvp.second;

        std::string key_repr = str_repr(k, should_prettify);
        std::string val_repr = str_repr(v, should_prettify);

        res += key_repr + "=>" + val_repr;
        res += (i++ == m.size() - 1) ? "" : ", ";
    }
    return res + "}";
}


template <class Key,
          class Hash,
          class Pred,
          class Alloc>
std::string PrettyPrinter::str_repr(
    const std::unordered_set<Key, Hash, Pred, Alloc>& uset,
    const bool& should_prettify
)
{
    return iter_to_s(uset, should_prettify, "{", "}");
}


template <class T,
          class Compare,
          class Alloc>
std::string PrettyPrinter::str_repr(
    const std::set<T, Compare, Alloc>& oset,
    const bool& should_prettify
)
{
    return iter_to_s(oset, should_prettify, "{", "}");
}


template <typename ITER>
std::string PrettyPrinter::iter_to_s(
    const ITER& iter,
    const bool& should_prettify,
    const std::string& open,
    const std::string& close
)
{
    std::string res = open;
    size_t i = 0;

    for (auto val : iter)
    {
        res += str_repr(val, should_prettify);
        res += (i++ != iter.size() - 1) ? ", " : "";
    }
    return res + close;
}
