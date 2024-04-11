/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:42:43 by lflandri          #+#    #+#             */
/*   Updated: 2024/04/11 13:56:39 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER
# define HEADER
# include "class/Rubik.hpp"
# include <iostream>
# include <vector>
# include <string>

# define RED 1
# define WHITE 2
# define ORANGE 3
# define GREEN 4
# define BLUE 5
# define YELLOW 6


/*FUNCTION DECLARATION*/


int	chooseColor(char c);
int	turnNumber(std::string command, int i);



#endif