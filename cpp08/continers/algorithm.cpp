// #include <vector>
// #include<algorithm>


// //some the funciton is the algorithm like 
// // is htis case we talk about 8 catigoris

// //1-non-modifying sequence operation they don't change like 
// //("all_of" "any_of" "none_of" "for_each"...)this funciton don't change the contener 

// // the things that's we need to handle is the type complexity we use the fast functions amd the performence functions
// /*in c++ algorithms are standarde librory that work in the range of data*/
// //they work with continers like vector array list ..


// //⚠️ Remember:
// //c++98 does not have ==> auto, nullptr, unordered_map , unordered_set, 
// 3️⃣ Algorithms Available in C++98

// Everything below is allowed in C++98.

// 🔥 Sorting & Ordering

// sort

// stable_sort

// partial_sort

// nth_element

// is_sorted ❌ (not in C++98 — C++11)

// binary_search

// lower_bound

// upper_bound

// equal_range

// 🔥 Searching

// find

// find_if

// adjacent_find

// count

// count_if

// search

// search_n

// 🔥 Min / Max

// min

// max

// min_element

// max_element

// 🔥 Modifying Algorithms

// copy

// copy_backward

// swap

// swap_ranges

// iter_swap

// transform

// replace

// replace_if

// fill

// fill_n

// generate

// generate_n

// remove

// remove_if

// remove_copy

// remove_copy_if

// unique

// unique_copy

// reverse

// reverse_copy

// rotate

// rotate_copy

// random_shuffle ✅ (removed in C++17)

// 🔥 Partitioning

// partition

// stable_partition

// 🔥 Set Algorithms (for sorted ranges)

// set_union

// set_intersection

// set_difference

// set_symmetric_difference

// includes

// 🔥 Heap Algorithms

// make_heap

// push_heap

// pop_heap

// sort_heap

// 🔥 Permutations

// next_permutation

// prev_permutation

// 4️⃣ Numeric Algorithms (<numeric>)

// accumulate

// inner_product

// partial_sum

// adjacent_difference

// 5️⃣ Function Objects (<functional>)

// Instead of lambdas (not available in C++98), you use:

// std::less

// std::greater

// std::plus

// std::minus

// std::multiplies

// std::divides

// std::equal_to

// etc.