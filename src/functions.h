#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

template<typename T, std::size_t SIZE>
std::size_t array_length(const T (&)[SIZE]) {
  return SIZE;
}

// template<typename K, typename V>
// void print_key_val(const K& key, const V& val) {
//   std::cout << "(" << key << ", " << val << ")" << std::endl;
// }
template<typename MapIterator>
void print_key_val(MapIterator i) {
  std::cout << "(" << i->first << ", " << i->second << ")" << std::endl;
}
#endif

