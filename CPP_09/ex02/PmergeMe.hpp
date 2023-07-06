/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2023/07/06 23:32:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:54:23 by user              #+#    #+#             */
/*   Updated: 2023/05/20 17:27:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <iostream>
#include <sstream>

class PmergeMe
{
	private:
		std::list<int>		merge_list;
		std::vector<int>	merge_vector;
		bool				exec_ok;

	public:
		PmergeMe();
		PmergeMe(char **any);
		PmergeMe(PmergeMe const &sub);
		PmergeMe &operator=(PmergeMe const &sub);
		~PmergeMe();

		bool	list_containch() const;
		bool	vector_containch() const;
		void	show_containerinput() const;
		void	show_listcontainer() const;
		void	show_vectorcontainer() const;

		void	sort_list();
		void	sort_vector();
		int		stringToInt(const std::string& str);
		bool	inputnumch(const std::string& str);
		bool	num_formatch(const std::string& str);
		bool	num_overdch(const std::string& str);

		bool	add_nbr(int nbr);
		class	MyError: public std::exception
		{	
			public:
				virtual const char* what() const throw()
				{
        			return ("add nbr missed");
    			}
		};
};

#endif