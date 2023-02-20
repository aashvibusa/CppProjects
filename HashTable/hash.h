#include <iostream>
#include <cstring>
#include <vector>
#include "node.h"
#include "student.h"

using namespace std;

class Hash {
 public:
  Hash();
  int hashFunction(int k);
  void add(int k, Student* s);
  void del(int k);
  void print();
  void rehash();
 public:
  int buckets;
  Node **table;
};
  
  
  
