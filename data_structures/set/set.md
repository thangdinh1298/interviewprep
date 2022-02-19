# Set
## Constructors
  std::set<int> first; //O(1)
  std::set<int> second (myints,myints+5); //O(n) if range sorted, O(nlogn) otherwise
  std::set<int> third (second); //O(n) if range sorted, O(nlogn) otherwise
  std::set<int> fourth (second.begin(), second.end()); //O(n) if range sorted, O(nlogn) otherwise
## Operations
- find() : O(logn)
- insert(val) : O(logn)
- erase(val) : O(logn)
- find_min using a.begin() : O(1)
- find_max using a.rbegin() : O(1)
- lower_bound()/upper_bound() : O(logn)
