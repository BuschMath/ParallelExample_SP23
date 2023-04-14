#include <iostream>
#include <thread>

// Function that will be executed concurrently
void print_hello(int id) {
    std::cout << "Hello from thread " << id << "!" << std::endl;
}

int main() {
    const int num_threads = 1000; // Number of threads to create

    // Create an array of threads
    std::thread threads[num_threads];

    // Launch threads
    for (int i = 0; i < num_threads; ++i) {
        threads[i] = std::thread(print_hello, i + 1);
    }

    // Join threads
    for (int i = 0; i < num_threads; ++i) {
        threads[i].join();
    }

    std::cout << "All threads joined." << std::endl;

    return 0;
}
