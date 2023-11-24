/*
 * time: 2023.11.24
 * privode: 格物数安实习
 * issue: 列出给定字符串所有的子字符串
 *
 * solve: substr()
 */
#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;

  for (int i = 0; i < str.size(); ++i) {
    for (int j = i + 1; j < str.size() + 1; ++j) {
      std::cout << str.substr(i, j - i) << std::endl;
    }
  }
  return 0;
}
