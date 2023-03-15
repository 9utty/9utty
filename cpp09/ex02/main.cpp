#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cerr << "Usage: " << argv[0] << " <list of positive integers>\n";
        return 1;
    }

    std::vector<int> inputVector;
    std::deque<int> inputDeque;
    for (int i = 1; i < argc; ++i) {
        int value = std::atoi(argv[i]);
        if (value < 0) {
            std::cerr << "Error: Only positive integers are allowed.\n";
            return 1;
        }
        inputVector.push_back(value);
        inputDeque.push_back(value);
    }

    PmergeMe sorter;
    std::vector<int> sortedVector;
    std::deque<int> sortedDeque;

    std::clock_t startVector = std::clock();
    sorter.sortWithVector(inputVector, sortedVector);
    std::clock_t endVector = std::clock();
    double elapsedVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

    std::clock_t startDeque = std::clock();
    sorter.sortWithDeque(inputDeque, sortedDeque);
    std::clock_t endDeque = std::clock();
    double elapsedDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    std::stringstream beforeSS;
    for (std::vector<int>::const_iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
        beforeSS << *it << ' ';
    }

    std::stringstream afterSS;
    for (std::vector<int>::const_iterator it = sortedVector.begin(); it != sortedVector.end(); ++it) {
        afterSS << *it << ' ';
    }

    std::cout << "Before: " << beforeSS.str() << '\n';
    std::cout << "After: " << afterSS.str() << '\n';
    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector: " << elapsedVector << " us\n";
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque: " << elapsedDeque << " us\n";

    return 0;
}
