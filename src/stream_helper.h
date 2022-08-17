#include <string>


template <typename T>
/******************************************************************************
 * @brief   Check if an object is streamable.
 * 
 * @return true
 * @return false 
 *****************************************************************************/
bool is_streamable();


template <typename T>
/******************************************************************************
 * @brief   Get a string representation of a streamable object.
 * 
 * @param obj           The streamable object to get the string representation
 *                      for.
 * @return std::string  The string representation of the given object.
 *****************************************************************************/
std::string streamble_to_s(const T& obj);


template <typename T>
/******************************************************************************
 * @brief   Get a string representation of a non-streamable object.
 * 
 * @param obj           The non-streamable object to get the string
 *                      representation for.
 * @return std::string  The string representation of the given object.
 *****************************************************************************/
std::string non_streamable_to_s(const T& obj);


// include the implementation so that it is accessible to the compiler
#include "stream_helper.cpp"
