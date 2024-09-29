#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

vectorPair PmergeMe::even_sort_vector()
{
	vectorIt it = this->numbers_vector.begin();
	int i = 0;
	for (; it != this->numbers_vector.end(); ++it)
	{
		if (i % 2 == 0 && next(it) != this->numbers_vector.end())
		{
			vectorIt next_it = next(it);
			if (*it > *next_it)
				std::iter_swap(it, next_it);
		}
		++i;
	}

	if (this->numbers_vector.size() % 2 == 1)
	{
		this->single_number_vector = this->numbers_vector[this->numbers_vector.size() - 1];
		vectorIt last_number = this->numbers_vector.end();
		this->numbers_vector.erase(--last_number);
	}
	vectorPair numbers_vector_pair(this->numbers_vector.size() / 2);
	for (size_t i = 0; i < this->numbers_vector.size(); ++i)
	{
		if (i % 2 == 0)
			numbers_vector_pair[i / 2].first = this->numbers_vector[i];
		else
			numbers_vector_pair[i / 2].second = this->numbers_vector[i];
	}
	return (numbers_vector_pair);
}

void PmergeMe::merge_sort_vector(vectorPair &vec, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		merge_sort_vector(vec, left, middle);
		merge_sort_vector(vec, middle + 1, right);
		merge_vector(vec, left, middle, right);
	}
}

void PmergeMe::merge_vector(vectorPair &vec, int left, int mid, int right)
{
	vectorPair temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (vec[i].second <= vec[j].second)
			temp[k++] = vec[i++];
		else
			temp[k++] = vec[j++];
	}
	while (i <= mid)
		temp[k++] = vec[i++];
	while (j <= right)
		temp[k++] = vec[j++];
	for (int p = 0; p < k; ++p)
		vec[left + p] = temp[p];
}

void PmergeMe::insert_sort_vector(vectorPair &vec_pair)
{
	if (vec_pair.size() > 0)
	{
		this->numbers_vector.push_back(vec_pair[0].first);
		this->numbers_vector.push_back(vec_pair[0].second);
		for (size_t i = 1; i != vec_pair.size(); ++i)
		{
			insert_vector(vec_pair[i].first);
			this->numbers_vector.push_back(vec_pair[i].second);
		}
	}
	if (this->single_number_vector != NO_SINGLE_NUMBER)
		insert_vector(this->single_number_vector);
}

void PmergeMe::insert_vector(int number)
{
	if (this->numbers_vector.size() == 0)
		this->numbers_vector.push_back(number);
	else if (number < this->numbers_vector[0])
		this->numbers_vector.insert(this->numbers_vector.begin(), number);
		// this->numbers_vector.push_front(number);
	else if (number > this->numbers_vector[this->numbers_vector.size() - 1])
		this->numbers_vector.push_back(number);
	else
	{
		int left = 0;
		int right = this->numbers_vector.size() - 1;
		int middle = (left + right) / 2;
		while (left <= right)
		{
			if (middle > 0 && \
				number > this->numbers_vector[middle - 1] && number < this->numbers_vector[middle])
			{
				vectorIt it = this->numbers_vector.begin();
				std::advance(it, middle);
				this->numbers_vector.insert(it, number);
				break ;
			}
			else if (number < this->numbers_vector[middle])
				right = middle - 1;
			else
				left = middle + 1;
			middle = (left + right) / 2;
		}
	}
}

void PmergeMe::print_numbers_pair_vector(const vectorPair &vec, const std::string &str)
{
	std::cout << GOLD << str << RESET << std::endl;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << "\e[38;2;190;190;190m" << vec[i].first << " ";
		std::cout << "\e[38;2;255;255;255m" << vec[i].second << " ";
	}
	if (this->single_number_vector != NO_SINGLE_NUMBER)
		std::cout << "\e[38;2;190;190;190m" << this->single_number_vector;
	std::cout << RESET << std::endl;
}
