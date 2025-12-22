#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <stdexcept>

void check_args(int ac, char **av);
void check_digits(const std::string& str);

double print_sort_vector(int size, char **str);
std::vector<size_t> jacobsthal_sequence_vector(size_t n);
std::vector<int> Ford_Johnson_sort(const std::vector<int>& str);

double print_sort_deque(int size, char **str);
std::deque<size_t> jacobsthal_sequence_deque(size_t n);
std::deque<int> Ford_Johnson_sort(const std::deque<int>& str);