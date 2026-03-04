#include <iterator>


//
#include <vector>
#include <iostream>

//
//when we talk about an itterator we talck about an object that acte like the pointer and allow to 

//.access elements in a continer
//.move throught the container
//.it's the relation between container and algorithme (because STL algorithms don't work with containers directly.)


//synthax
std::vector<int>::iterator it;
return *it;

*it; //thisis the accesse to value
it++;//uncriment
it--;//dicrement
it + 3; //jump
it != v; //compare

// the 5 types of iterators ==>

//1- input iterator
// ✅ Read values (*it)
// ✅ Move forward (++it)
std::istream_iterator<int> input(std::cin);//htis is the start the input
 std::istream_iterator<int> end;//this end  iterator the inpput that represont the endd of the stream (to know if the read iss stop)
//2- output iterator
// ✅ Can write values (*it = value)

// ✅ Can move forward (++it)
std::ostream_iterator<int> output(std::cout, "");

//3- forward iterator
// ✅ Can read (*it)

// ✅ Can write (*it = value)

// ✅ Can move forward (++it)

// ✅ Multi-pass (this is the key difference from Input Iterator)
//4- bidirectional iterator
✅ Can read (*it)

✅ Can write (*it = value)

✅ Can move forward (++it)

✅ Can move backward (--it)

✅ Multi-pass

//5-random access iterator
✅ Can read (*it)

✅ Can write (*it = value)

✅ Can move forward (++it)

✅ Can move backward (--it)

✅ Cannot jump (it + 5)

✅ Multi-pass

resumer 
| Feature    | Input | Forward | Bidirectional | Random |
| ---------- | ----- | ------- | ------------- | ------ |
| Read       | ✅     | ✅       | ✅             | ✅  |
| Write      | ❌     | ✅       | ✅             | ✅  |
| Forward    | ✅     | ✅       | ✅             | ✅  |
| Backward   | ❌     | ❌       | ✅             | ✅  |
| Jump +n    | ❌     | ❌       | ❌             | ✅  |
| Multi-pass | ❌     | ✅       | ✅             | ✅  |


which continer use iterator and which type of the iterator 
| Container | Iterator Type  |
| --------- | -------------- |
| vector    | Random Access  |
| deque     | Random Access  |
| list      | Bidirectional  |
| set       | Bidirectional  |
| map       | Bidirectional  |
| stack     | ❌ no iterators |
| queue     | ❌ no iterators |


we have also some futer in the iterator like 

1- const_iterator

2-reverse_iterator 

3-