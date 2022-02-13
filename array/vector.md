#Vector
##Constructors
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100. Useful for filling array with value
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    std::vector<int> fourth (third);                       // a copy of third
##Operations' time complexity
- push_back() : Constant amortized time, linear if relocation is needed
- pop_back() : Constant
- insert() : linear on the number of elem inserted. If reallocation happens, linear on the entire vector
- erase() : linear on the number of elements erased (destructions) plus the number of elements after the last element deleted (moving)
- front() : constant
- back() : constant
- at() : constant
