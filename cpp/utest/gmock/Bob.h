#ifndef BOB_H
#define BOB_H

#include "BobInterface.h"

class Bob: public BobInterface {
 public:
  Bob() {
  }
  virtual ~Bob() {
  }
  
  virtual int Add(int x, int y) {
    return x + y;
  }
 private:
}; // class Bob

#endif // BOB_H
