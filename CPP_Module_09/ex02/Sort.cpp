#include "PmergeMe.hpp"

void PmergeMe::even_sort_deque()
{
	dequeIt it = this->numbers_deque.begin();
	int i = 0;
	for (; it != this->numbers_deque.end(); ++it)
	{
		if (i % 2 == 0 && next(it) != this->numbers_deque.end())
		{
			dequeIt next_it = next(it);
			if (*it > *next_it)
				std::iter_swap(it, next_it);
		}
		++i;
	}
}

void PmergeMe::merge_sort(std::deque<int> &deq, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		merge_sort(deq, left, middle);
		merge_sort(deq, middle + 1, right);
		merge(deq, left, middle, right);
	}
}

void PmergeMe::merge(std::deque<int> &deq, int left, int mid, int right)
{
	std::deque<int> temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (deq[i] <= deq[j])
			temp[k++] = deq[i++];
		else
			temp[k++] = deq[j++];
	}
	while (i <= mid)
		temp[k++] = deq[i++];
	while (j <= right)
		temp[k++] = deq[j++];
	for (int p = 0; p < k; ++p)
		deq[left + p] = temp[p];
}

void PmergeMe::sort_numbers()
{
	print_numbers("Before:");
	even_sort_deque();
	print_numbers("Even sort:");
	merge_sort(this->numbers_deque, 0, this->numbers_deque.size() - 1);
	print_numbers("After:");
}

// 12 5 101 2 8 42
