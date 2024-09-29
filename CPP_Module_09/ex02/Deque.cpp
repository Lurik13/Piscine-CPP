#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

dequePair PmergeMe::even_sort_deque()
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

	if (this->numbers_deque.size() % 2 == 1)
	{
		this->single_number_deque = this->numbers_deque[this->numbers_deque.size() - 1];
		dequeIt last_number = this->numbers_deque.end();
		this->numbers_deque.erase(--last_number);
	}
	dequePair numbers_deque_pair(this->numbers_deque.size() / 2);
	for (size_t i = 0; i < this->numbers_deque.size(); ++i)
	{
		if (i % 2 == 0)
			numbers_deque_pair[i / 2].first = this->numbers_deque[i];
		else
			numbers_deque_pair[i / 2].second = this->numbers_deque[i];
	}
	return (numbers_deque_pair);
}

void PmergeMe::merge_sort_deque(dequePair &deq, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		merge_sort_deque(deq, left, middle);
		merge_sort_deque(deq, middle + 1, right);
		merge_deque(deq, left, middle, right);
	}
}

void PmergeMe::merge_deque(dequePair &deq, int left, int mid, int right)
{
	dequePair temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (deq[i].second <= deq[j].second)
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

void PmergeMe::insert_sort_deque(dequePair &deq_pair)
{
	if (deq_pair.size() > 0)
	{
		this->numbers_deque.push_back(deq_pair[0].first);
		this->numbers_deque.push_back(deq_pair[0].second);
		for (size_t i = 1; i != deq_pair.size(); ++i)
		{
			insert_deque(deq_pair[i].first);
			this->numbers_deque.push_back(deq_pair[i].second);
		}
	}
	if (this->single_number_deque != NO_SINGLE_NUMBER)
		insert_deque(this->single_number_deque);
}

void PmergeMe::insert_deque(int number)
{
	if (this->numbers_deque.size() == 0)
		this->numbers_deque.push_back(number);
	else if (number < this->numbers_deque[0])
		this->numbers_deque.push_front(number);
	else if (number > this->numbers_deque[this->numbers_deque.size() - 1])
		this->numbers_deque.push_back(number);
	else
	{
		int left = 0;
		int right = this->numbers_deque.size() - 1;
		int middle = (left + right) / 2;
		while (left <= right)
		{
			if (middle > 0 && \
				number > this->numbers_deque[middle - 1] && number < this->numbers_deque[middle])
			{
				dequeIt it = this->numbers_deque.begin();
				std::advance(it, middle);
				this->numbers_deque.insert(it, number);
				break ;
			}
			else if (number < this->numbers_deque[middle])
				right = middle - 1;
			else
				left = middle + 1;
			middle = (left + right) / 2;
		}
	}
}

void PmergeMe::print_numbers_pair_deque(const dequePair &deq, const std::string &str)
{
	std::cout << GOLD << str << RESET << std::endl;
	for (size_t i = 0; i < deq.size(); ++i)
	{
		std::cout << "\e[38;2;190;190;190m" << deq[i].first << " ";
		std::cout << "\e[38;2;255;255;255m" << deq[i].second << " ";
	}
	if (this->single_number_deque != NO_SINGLE_NUMBER)
		std::cout << "\e[38;2;190;190;190m" << this->single_number_deque;
	std::cout << RESET << std::endl;
}
