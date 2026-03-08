#include <bits/stdc++.h>
using namespace std;
#include <execinfo.h>
#include <unistd.h>

#include <csignal>
const long long inf = LONG_MAX;
#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto &ai : (x)) std::cin >> ai
#define flush fflush(stdout)

#define saverun(f) try {f();} \
    catch (const std::exception &e) {std::cerr << "Exception: " << e.what() << std::endl;} \
    catch (...) {std::cerr << "Unknown exception occurred" << std::endl;}    

typedef long long i64;

void signal_handler(int signum) {
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    std::cerr << "Error: signal " << signum << ":" << std::endl;
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Register signal handler for segmentation faults
    signal(SIGSEGV, signal_handler);
    signal(SIGABRT, signal_handler);

    int test_cases = 1;
    // std::cin >> test_cases;
    while (test_cases--) {
        saverun(solve);
    }
}

