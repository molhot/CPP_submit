/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:46:34 by user              #+#    #+#             */
/*   Updated: 2023/05/10 23:12:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
#define Array_HPP

#include <iostream>

template <class T>

class	Array
{
	private:
		T*		_array;
		size_t	_size;
	
	public:
		Array(): _size(0), _array(new T[0])
		{
			std::cout << "Array constructor called" << std::endl;
			//this->_array = new T[0];
		};
		Array(unsigned int n): _size(n), _array(new T[n])
		{
			std::cout << "Array constructor called" << std::endl;
			//this->_array = new T[0];
		};
		Array(Array const &sub)
		{
			std::cout << "Array COPY constructor called" << std::endl;
			this->_array = NULL;
			*this = sub;
		};
		Array& operator=(Array const &sub)
		{
			size_t	pos;

			std::cout << "Array OPERAND called" << std::endl;
			if (this->_array != NULL)
				delete[] this->_array;
			if (sub._size != 0)
			{
				pos = 0;
				this->_size = sub._size;
				this->_array = new T[sub.size];
				while (pos != this->_array)
				{
					this->_array[pos] = sub._array[pos];
					pos++;
				}
			}
			else
			{
				this->_size = 0;
				this->_array = new T[0];
			}
			return (*this);
		};
		~Array()
		{
			if (this->_array != NULL)
				delete[] this->_array;
			std::cout << "destructor called" << std::endl;
		};
		T& operator[](unsigned int n)
		{
			if (n >= this->_size)
				throw (Array::BADSIZE());
			return (this->_array[n]);
		};
		class	BADSIZE: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("error size");
				}
		};
};

#endif