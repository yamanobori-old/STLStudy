﻿#ifndef _FUNCTORS_H_
#define _FUNCTORS_H_

#include <cstring>


//
// 関数オブジェクト
//
// struct とすることで "public:" を書く必要がない

struct RandomGenerator {
  RandomGenerator(unsigned int seed, int div) : div_(div) {
    srand(seed);
  }
  int operator()() {
    return rand() % div_;
  }
  int div_;
};

struct EndsWith {
  EndsWith(std::string& ending) :ending_(ending){}
  bool operator()(std::string& s) {
    if (ending_.size() > s.size()) return false;
    return std::equal(ending_.rbegin(),  ending_.rend(),  s.rbegin());
  }
  std::string& ending_;
};

struct GT: public std::unary_function<std::string, bool> {
  GT(size_t n) :n_(n){}
  size_t n_;
  result_type operator()(argument_type s) {
    return static_cast<result_type>(s.size() > n_);
  }
};

struct Print {
  template<typename T>
    void operator()(T val) {
      std::cout << val << " ";
    }
};

struct ToUpper {
  std::string operator()(std::string& org) {
    std::string upper = org;;
    std::transform(org.begin(), org.end(), upper.begin(), ::toupper);
    return upper;
  }
};

struct Square {
  int operator()(int n) {
    return n * n;
  }
};

struct CreatePair {
  std::pair<int, int> operator()(int n) {
    return std::make_pair(n, n * n);
  }
};

struct Sum {
  template<typename T>
    T operator()(T lhs, T rhs) {
      return lhs + rhs;
    }
};

struct DeleteObject {
  template<typename T>
    void operator()(T* p) {
      delete p;
    }
};

struct GetLength
{
  int operator()(std::string s) {
    return s.size();
  }
};

struct IsEight {
  bool operator()(int n) {
    return n == 8;
  }
};

struct IsEven: public std::unary_function<int, bool> {
  result_type operator()(argument_type i) {
    return static_cast<result_type>(i % 2 == 0);
  }
};

struct CIStringLess :public std::binary_function<std::string, std::string, bool> {

  // 等価に対して trueを返さないこと!!
  bool operator() (const std::string& lhs, const std::string rhs) const
  {
#ifdef _MSC_VER
    return _stricmp(lhs.c_str(), rhs.c_str()) < 0;
#else
    return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
#endif
  }
};

struct DereferenceLess {
  // 等価に対して trueを返さないこと!!
  template<typename Ptr>
  bool operator()(Ptr p1, Ptr p2)
  {
    return *p1 < *p2;
  }
};

struct DereferenceEq {
  template<typename Ptr>
    bool operator()(Ptr p1, Ptr p2) const
    {
      return *p1 == *p2;
    }
};

#endif
