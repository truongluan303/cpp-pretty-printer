#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>


class PrettyPrinter
{
public:

    template <typename T>
    /**************************************************************************
     * @brief   Get a string representation of an object.
     * 
     * @param obj
     * @return const std::string
     *************************************************************************/
    static std::string str_repr(const T& obj);


    template <typename Iter>
    /**************************************************************************
     * @brief   Get a string representation for an iterator.
     *
     * @param begin             Pointer to the front of the range.
     * @param end               Pointer to the end of the range.
     * @return std::string 
     *************************************************************************/
    static std::string str_repr(Iter begin, Iter end);


    template <typename T>
    /**************************************************************************
     * @brief   Get a pretty string representation of an object. This is only
     *          useful if you are trying to pass in a nested data structure.
     * 
     * @param obj 
     * @return const std::string
     *************************************************************************/
    static std::string pretty_str_repr(const T& obj);


    template <typename T>
    /**************************************************************************
     * @brief   Print an object to the console output.
     * 
     * @param obj
     *************************************************************************/
    static void puts(const T& obj);


    template <typename T>
    /**************************************************************************
     * @brief   Print a prettified object "prettily" to the console output.
     * 
     * @param obj 
     *************************************************************************/
    static void pretty_puts(const T& obj);


private:

    template <typename T>
    static std::string str_repr(const T&, const bool&);


    template <typename T>
    static std::string str_repr(const std::vector<T>&, const bool&);


    template <class Key,
              class T,
              class Hash,
              class Pred,
              class Alloc>
    static std::string str_repr(
        const std::unordered_map<Key, T, Hash, Pred, Alloc>&,
        const bool&
    );


    template <class Key,
              class T,
              class Compare,
              class Alloc>
    static std::string str_repr(
        const std::map<Key, T, Compare, Alloc>&,
        const bool&
    );


    template <typename MAP>
    static std::string generic_map_to_s(const MAP&, const bool&);


    template <class Key,
              class Hash,
              class Pred,
              class Alloc>
    static std::string str_repr(
        const std::unordered_set<Key, Hash, Pred, Alloc>&,
        const bool&
    );


    template <class T,
              class Compare,
              class Alloc>
    static std::string str_repr(
        const std::set<T, Compare, Alloc>&,
        const bool&
    );


    template <typename ITER>
    static std::string iter_to_s(
        const ITER&,
        const bool&,
        const std::string&,
        const std::string&
    );
};


// include the implementation so that it is accessible to the compiler
#include "pprint.cpp"
