#include <iostream>
#include <string>

class Bitset {
  int size_ = 0;
  int num_of_1_ = 0;

  std::string bits_;
  std::string bits_inverted_;

 public:
  Bitset(int size) {
    bits_ = std::string(size, '0');
    bits_inverted_ = std::string(size, '1');
    size_ = size;
  }

  void fix(int idx) {
    if (bits_[idx] == '0') {
      bits_[idx] = '1';
      bits_inverted_[idx] = '0';
      ++num_of_1_;
    }
  }

  void unfix(int idx) {
    if (bits_[idx] == '1') {
      bits_[idx] = '0';
      bits_inverted_[idx] = '1';
      --num_of_1_;
    }
  }

  void flip() {
    bits_.swap(bits_inverted_);
    num_of_1_ = size_ - num_of_1_;
  }

  bool all() { return size_ == num_of_1_; }

  bool one() { return num_of_1_; }

  int count() { return num_of_1_; }

  std::string toString() { return bits_; }
};

int main() {
  Bitset bs = Bitset(5);
  bs.fix(3);
  bs.fix(1);
  bs.flip();
  std::cout << bs.all() << std::endl;
  bs.unfix(0);
  bs.flip();
  std::cout << bs.one() << std::endl;
  bs.unfix(0);
  std::cout << bs.count() << std::endl;
  std::cout << bs.toString() << std::endl;
}
