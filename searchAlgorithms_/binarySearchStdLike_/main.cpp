#include <iostream>
#include <iterator>
#include <vector>
#include <compare>

namespace my {
    template <typename ForwardIt>
    using diff_t = typename std::iterator_traits<ForwardIt>::difference_type;

    template <class ForwardIt, typename T>
    ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value) {
        ForwardIt it;
        diff_t<ForwardIt> step;
        diff_t<ForwardIt> cnt = std::distance(first, last); 
        while (cnt) {
            it = first;
            step = cnt / 2;
            std::advance(it, step);
            if (*it < value) {
                first = ++it;
                cnt -= step + 1;
            }
            else {
                cnt = step;
            }
        }
        return first;
    }

    template<typename ForwardIt, typename T, typename Compare>
    ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp) {
        ForwardIt it;
        diff_t<ForwardIt> step;
        diff_t<ForwardIt> cnt = std::distance(first, last); 
        while (cnt) {
            it = first;
            step = cnt / 2;
            std::advance(it, step);
            if (comp(*it, value)) {
                first = ++it;
                cnt -= step + 1;
            }
            else {
                cnt = step;
            }
        }
        return first;
    }

    template <typename ForwardIt, typename T>
    bool binary_search(ForwardIt first, ForwardIt last, const T& value) {
        first = my::lower_bound(first, last, value);
        return (!(first == last) && !(value < *first));
    }

    template<typename ForwardIt, typename T, typename Compare>
    bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp) {
        first = my::lower_bound(first, last, value, comp);
        return (!(first == last) && !(comp(value, *first)));
    }
}

struct UserDefinedType {
    UserDefinedType() = default;
    UserDefinedType(int n_) : n(n_) {}
    int n;
};

int main() {
    std::vector<int> haystack{ 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

    //UserDefinedType udt_obj(11);
    //if (my::binary_search(haystack.begin(), haystack.end(), udt_obj, [](const UserDefinedType& lhs, const UserDefinedType& rhs) { return lhs.n < rhs.n; })) {
    //    std::cout << "OK, " << udt_obj.n << " has been found in the vector.\n";
    //}
    //else {
    //    std::cout << "NOK, " << udt_obj.n << " has not been found in the vector.\n";
    //}

    int needle = 18;
    if (my::binary_search(haystack.begin(), haystack.end(), needle)) {
        std::cout << "OK, " << needle << " has been found in the vector.\n";
    }
    else {
        std::cout << "NOK, " << needle << " has not been found in the vector.\n";
    }
}