#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortWithVector(const std::vector<int> &input, std::vector<int> &output);
    void sortWithDeque(const std::deque<int> &input, std::deque<int> &output);
    static const std::size_t INSERT_SORT_THRESHOLD = 10;

    template <typename Container>
    void mergeInsertSort(Container &container, std::size_t left, std::size_t right);

private:
    template <typename Container>
    void merge(Container &container, std::size_t left, std::size_t middle, std::size_t right);
    template <typename Container>
    void insertSort(Container &container, std::size_t left, std::size_t right);
};



template <typename Container>
void PmergeMe::mergeInsertSort(Container &container, std::size_t left, std::size_t right) {
    if (right - left <= 1) {
        // Base case: if there is one element or less, return.
        return;
    }

    if (right - left <= INSERT_SORT_THRESHOLD) {
        // If the size of the subarray is less than or equal to the threshold, use insertSort.
        insertSort(container, left, right);
    } else {
        // If the size of the subarray is greater than the threshold, split and merge.
        std::size_t middle = left + (right - left) / 2;
        mergeInsertSort(container, left, middle);
        mergeInsertSort(container, middle, right);
        merge(container, left, middle, right);
    }
}

template <typename Container>
void PmergeMe::merge(Container &container, std::size_t left, std::size_t middle, std::size_t right) {
    // Create temporary subarrays
    Container leftArray(container.begin() + left, container.begin() + middle);
    Container rightArray(container.begin() + middle, container.begin() + right);

    // Merge the subarrays back into the original container
    std::size_t i = 0, j = 0, k = left;
    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] < rightArray[j]) {
            container[k++] = leftArray[i++];
        } else {
            container[k++] = rightArray[j++];
        }
    }

    // Copy any remaining elements from the left and right subarrays
    while (i < leftArray.size()) {
        container[k++] = leftArray[i++];
    }
    while (j < rightArray.size()) {
        container[k++] = rightArray[j++];
    }
}

template <typename Container>
void PmergeMe::insertSort(Container &container, std::size_t left, std::size_t right) {
    for (std::size_t i = left + 1; i < right; ++i) {
        typename Container::value_type key = container[i];
        std::size_t j = i - 1;

        // Move elements that are greater than 'key' one position ahead
        while (j >= left && container[j] > key) {
            container[j + 1] = container[j];
            if (j-- == 0) {
                break;
            }
        }
        container[j + 1] = key;
    }
}

#endif // PMERGEME_HPP
