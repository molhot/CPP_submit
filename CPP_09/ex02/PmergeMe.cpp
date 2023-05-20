/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:54:20 by user              #+#    #+#             */
/*   Updated: 2023/05/20 20:29:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "Pmerge constructor called" << std::endl;
}

bool PmergeMe::add_nbr(int nbr)
{
	try
	{
		this->merge_list.push_back(nbr);
		this->merge_vector.push_back(nbr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	return (true);
}

PmergeMe::PmergeMe(char **any)
{
	size_t		pos;
	std::string	any_in;
	int			any_nbr;

	std::cout << "Pmerge constructor called" << std::endl;
	pos = 1;
	while (any[pos] != NULL)
	{
		try
		{
			any_in = any[pos];
			any_nbr = std::stoi(any_in);
			if (add_nbr(any_nbr) == false)
				throw PmergeMe::MyError();
		}
		catch(const std::exception& e)
		{
			std::cout << any[pos] << "input nbr is something wrong format" << std::endl;
		}
		pos++;
		
	}
}

PmergeMe::~PmergeMe()
{
	std::cout << "Pmerge destructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &sub)
{
	if (sub.list_containch() == true && sub.vector_containch() == true)
	{
		this->merge_list = sub.merge_list;
		this->merge_vector = sub.merge_vector;
	}
	else if (sub.list_containch() == true && sub.vector_containch() == false)
		this->merge_list = sub.merge_list;
	else if (sub.list_containch() == false && sub.vector_containch() == true)
		this->merge_vector = sub.merge_vector;
	std::cout << "copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &sub)
{
	if (this == &sub)
	{
		std::cout << "operand called" << std::endl;
		return (*this);
	}
	if (sub.list_containch() == true && sub.vector_containch() == true)
	{
		this->merge_list = sub.merge_list;
		this->merge_vector = sub.merge_vector;
	}
	else if (sub.list_containch() == true && sub.vector_containch() == false)
		this->merge_list = sub.merge_list;
	else if (sub.list_containch() == false && sub.vector_containch() == true)
		this->merge_vector = sub.merge_vector;
	std::cout << "operand called" << std::endl;
	return (*this);
}

bool	PmergeMe::list_containch() const
{
	return (this->merge_list.empty());
}

bool	PmergeMe::vector_containch() const
{
	return (this->merge_vector.empty());
}

void	PmergeMe::show_listcontainer() const
{
	std::list<int>::const_iterator	front = this->merge_list.begin();
	std::list<int>::const_iterator	end = this->merge_list.end();

	while (front != end)
	{
		std::cout << *front << " ";
		++front;
	}
	std::cout << "<< list container's contents" << std::endl;
}

void	PmergeMe::show_vectorcontainer() const
{
	std::vector<int>::const_iterator	front = this->merge_vector.begin();
	std::vector<int>::const_iterator	end = this->merge_vector.end();

	while (front != end)
	{
		std::cout << *front << " ";
		++front;
	}
	std::cout << "<< vector container's contents" << std::endl;
}

void	PmergeMe::show_containerinput() const
{
	show_listcontainer();
	show_vectorcontainer();
}

static	void	merge(std::list<int> *list, std::list<int> left, std::list<int> right)
{
	while (left.empty() != true && right.empty() != true)
	{
		if (left.front() <= right.front())
		{
			list->push_back(left.front());
			left.pop_front();
		}
		else
		{
			list->push_back(right.front());
			right.pop_front();
		}
	}
	while (left.empty() == false)
	{
		list->push_back(left.front());
		left.pop_front();
	}
	while (right.empty() == false)
	{
		list->push_back(right.front());
		right.pop_front();
	}
}

static	std::list<int> separate_list(std::list<int> mergelist)
{
	std::list<int>				left;
	std::list<int>				right;
	std::list<int>				result;
	std::list<int>::iterator	begin;
	size_t						list_len_half;
	size_t						list_pos;

	if (mergelist.size() <= 1)
		return (mergelist);
	list_pos = 0;
	list_len_half = mergelist.size() / 2;
	begin = mergelist.begin();
	while (list_pos != list_len_half)
	{
		left.push_back(*begin);
		begin++;
		list_pos++;
	}
	while (list_pos != mergelist.size())
	{
		right.push_back(*begin);
		begin++;
		list_pos++;
	}
	left = separate_list(left);
	right = separate_list(right);
	merge(&result, left, right);
	return (result);
}

void	show_mergedlistcontainer(std::list<int> list)
{
	std::list<int>::iterator	front = list.begin();
	std::list<int>::iterator	end = list.end();

	while (front != end)
	{
		std::cout << *front << " ";
		++front;
	}
	std::cout << "<< list merged contents" << std::endl;
}

void	PmergeMe::sort_list()
{
	std::list<int>	list_sorted;

	clock_t	start = clock();
	list_sorted = separate_list(this->merge_list);
	clock_t	end = clock();
	show_mergedlistcontainer(list_sorted);
	std::cout << "this merge is " << static_cast<double>(end - start)  / CLOCKS_PER_SEC << " time passed" << std::endl;
}

static	void	show_mergedvectcontainer(std::vector<int> vect)
{
	size_t	pos;

	pos = 0;
	while (pos != vect.size())
	{
		std::cout << vect[pos] << " ";
		pos++;
	}
	std::cout << "<< vect merged contents" << std::endl;
}

static	void	merge(std::vector<int> *vect, size_t left, size_t mid, size_t right)
{
	int 						i;
    int 						j;
	int 						k;
	std::vector<int>::iterator	begin;
    std::vector<int> 			temp;

	i = left;
	j = mid + 1;
    while (i <= mid && j <= right)
	{
        if ((*vect)[i] <= (*vect)[j]) 
		{
            temp.push_back((*vect)[i]);
            i++;
        } 
		else 
		{
            temp.push_back((*vect)[j]);
            j++;
        }
    }
    while (i <= mid) 
	{
        temp.push_back((*vect)[i]);
        i++;
    }
    while (j <= right)
	{
        temp.push_back((*vect)[j]);
        j++;
    }
	k = left;
	begin = temp.begin();
    while (begin != temp.end())
	{
        (*vect)[k] = *begin;
        k++;
		begin++;
    }
}

static	void	mergesort(std::vector<int> *vect, size_t left, size_t right)
{
	int	mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		mergesort(vect, left, mid);
		mergesort(vect, mid + 1, right);

		merge(vect, left, mid, right);
	}
}

static	std::vector<int> separate_vect(std::vector<int> vect)
{
	size_t				size;

	if (vect.empty() == true)
	{
		std::cout << "this vect is not filled" << std::endl;
		return (vect);
	}
	size = vect.size();
	mergesort(&vect, 0, size - 1);
	return (vect);
}

void	PmergeMe::sort_vector()
{
	std::vector<int>	vect_sorted;

	clock_t	start = clock();
	vect_sorted = separate_vect(this->merge_vector);
	clock_t	end = clock();
	show_mergedvectcontainer(vect_sorted);
	std::cout << "this merge is " << static_cast<double>(end - start)  / CLOCKS_PER_SEC << " time passed" << std::endl;
}