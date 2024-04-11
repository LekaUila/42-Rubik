/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:29:12 by lflandri          #+#    #+#             */
/*   Updated: 2024/04/11 15:10:23 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of argument !" << std::endl;
		return (-1);
	}
	/*if (checkArgument(argv[1]) == -1)
		return (-1);*/
	Rubik rubik;
	rubik.shuffle(argv[1]);

	return (0);
}