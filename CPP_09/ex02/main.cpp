/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:54:16 by user              #+#    #+#             */
/*   Updated: 2023/07/06 23:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "please input some positive integer" << std::endl;
		std::cout << "like [./PmergeMe 4 3 2 1]" << std::endl;
		return (1);
	}
	PmergeMe	pm(argv);
  size_t  pos = 1;

	//pm.show_containerinput();
  std::cout << "=======================" << std::endl;
  while (pos != static_cast<size_t>(argc))
  {
    std::cout << argv[pos] << " ";
    pos++;
  }
  std::cout << std::endl;
  std::cout << "=======================" << std::endl;
	pm.sort_list();
  std::cout << "=======================" << std::endl;
	pm.sort_vector();
}

/*
以下のような変遷を経て完了するものだと考えられる

① リストを格納
9 8 7 6 5 4 3 2 1

② リストを分割していく（ここ自体が繰り返し
1 [9 8 7 6 5]
  
  [4 3 2 1]

2 [9 8 7]
  [6 5]
  
  [4 3]
  [2 1]

3 [9 8] | [7]
  [6] | [5]

  [4] | [3]
  [2] | [1]

4 ([9] | [8]) [7]
  [6] | [5]
  
  [4] | [3]
  [2] | [1]

③ 分割したものを入れ替えながら元に戻していく
1 [8 9] [7]
  [5 6]
  
  [3 4]
  [1 2]

*/