#include <algorithm>
#include <iterator>
template <typename T>
typename T::iterator easyfind(T continer, int i){
    typename T::iterator it;
    it = std::find(continer.begin(), continer.end(), i);
    if(it == continer.end())
        throw std::runtime_error("value not found");
    return it; 
}