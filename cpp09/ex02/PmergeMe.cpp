#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { return *this; }
PmergeMe::~PmergeMe() {}

void PmergeMe::sortWithVector(const std::vector<int> &input, std::vector<int> &output) {
    output = input;
    mergeInsertSort(output, 0, output.size());
}

void PmergeMe::sortWithDeque(const std::deque<int> &input, std::deque<int> &output) {
    output = input;
    mergeInsertSort(output, 0, output.size());
}

// Explicit template instantiation for merge and insertSort.
template void PmergeMe::merge<std::vector<int> >(std::vector<int> &container, std::size_t left, std::size_t middle, std::size_t right);
template void PmergeMe::merge<std::deque<int> >(std::deque<int> &container, std::size_t left, std::size_t middle, std::size_t right);
template void PmergeMe::insertSort<std::vector<int> >(std::vector<int> &container, std::size_t left, std::size_t right);
template void PmergeMe::insertSort<std::deque<int> >(std::deque<int> &container, std::size_t left, std::size_t right);
template void PmergeMe::mergeInsertSort<std::vector<int> >(std::vector<int> &container, std::size_t left, std::size_t right);
template void PmergeMe::mergeInsertSort<std::deque<int> >(std::deque<int> &container, std::size_t left, std::size_t right);
