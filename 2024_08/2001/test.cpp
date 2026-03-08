#include <iostream>
#include <ranges>
#include <string>
namespace R = std::ranges;
namespace V = std::ranges::views;

const int N = 1000;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string s(N, '0');
    for (int i = 0; i < N / 2; ++i) s[i * 2] = '1';
    for (const auto word : V::split(s, '1'))
        std::cout << std::string_view{begin(word), end(word)} << ' ';
}
