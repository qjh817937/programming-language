#ifndef BYTE_STREAM_H_
#define BYTE_STREAM_H_

#include <string.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <algorithm>
#include <tr1/type_traits>

struct ByteStream {
  //static int const MAX_SIZE = 255;
  //static int const MAX_CAPACITY = 256;
  static int const MAX_SIZE = 287;
  static int const MAX_CAPACITY = 288; // 256+32
  static int const CAPACITY = MAX_CAPACITY - 8;

  ByteStream() : buf_(new char[+MAX_CAPACITY]), off_(0) {}
  ~ByteStream() { delete[] buf_; }

  ByteStream& reset() { off_ = 0; return *this; }
  char const *data() const { return buf_; }
  int size() const { return off_; }

  bool operator==(ByteStream const& other) const {
    return off_ == other.off_ && memcmp(buf_, other.buf_, off_) == 0;
  }

  template <typename T>
  ByteStream& write(T const& v) {
    return write_if_fundamental(v, std::tr1::is_fundamental<T>());
  }

  template <typename T>
  ByteStream& write(T const *a, int n) {
    return write_if_fundamental(a, n, std::tr1::is_fundamental<T>());
  }

  ByteStream& write(ByteStream const& v) {
    int s = v.off_;
    if (off_ + v.off_ > +MAX_CAPACITY)
      s = +MAX_CAPACITY - off_;
    do_write(v.buf_, s);
    return *this;
  }

 private:
  template <typename T>
  ByteStream& write_if_fundamental(T const& v, std::tr1::true_type) {
    if (!(off_ < +CAPACITY))
      return *this;
    do_write(&v, sizeof (v));
    return *this;
  }

  template <typename T>
  ByteStream& write_if_fundamental(T const& v, std::tr1::false_type) {
    return write_if_array(v, std::tr1::is_array<T>());
  }

  template <typename T>
  ByteStream& write_if_array(T const& v, std::tr1::true_type) {
    return write(v, sizeof (v) / sizeof (v[0]));
  }

  template <typename T>
  ByteStream& write_if_array(T const& v, std::tr1::false_type) {
    return write_if_pointer(v, std::tr1::is_pointer<T>());
  }

  template <typename T>
  ByteStream& write_if_pointer(T const& v, std::tr1::true_type) {
    return write(*v);
  }

  template <typename T>
  ByteStream& write_if_pointer(T const& v, std::tr1::false_type) {
    return write(v.data(), v.size());
  }
    
  template <typename T>
  ByteStream& write_if_fundamental(T const *a, int n, std::tr1::true_type) {
    if (!(off_ < +CAPACITY))
      return *this;
    n = std::min(n, +MAX_SIZE);
    int s = n;
    if (off_ + sizeof(T) * s + 1 > +CAPACITY)
      s = (+CAPACITY - off_ - 2) / sizeof(T) + 1;
    buf_[off_++] = n;
    do_write(a, sizeof(T) * s);
    return *this;
  }

  template <typename T>
  ByteStream& write_if_fundamental(T const *a, int n, std::tr1::false_type) {
    if (!(off_ < +CAPACITY))
      return *this;
    n = std::min(n, +MAX_SIZE);
    buf_[off_++] = n;
    for (int i = 0; i < n; ++i)
      write(a[i]);
    return *this;
  }

  void do_write(void const *b, int n) {
    memcpy(buf_ + off_, b, n);
    off_ += n;
  }

 private:
  ByteStream(ByteStream const&);
  ByteStream& operator=(ByteStream const&);

  char *buf_;
  int off_;
};

#endif  // BYTE_STREAM_H_
