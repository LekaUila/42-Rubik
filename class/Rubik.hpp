/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rubik.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:40:19 by lflandri          #+#    #+#             */
/*   Updated: 2024/04/11 13:54:55 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUBIK
# define RUBIK
# include "Face.hpp"
# include "../header.hpp"
# include <ostream>
# include <iostream>
# include <sstream>


class Rubik
{
private:
	Face redFace;
	Face orangeFace;
	Face yellowFace;
	Face whiteFace;
	Face greenFace;
	Face blueFace;

public:
	Rubik();
	~Rubik();
	void	shuffle(std::string command);
	void	leftRotateFace(int color);
	void	rightRotateFace(int color);
	bool	isResolve();
	void	resolve();
};



#endif