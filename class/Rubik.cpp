/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rubik.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:40:37 by lflandri          #+#    #+#             */
/*   Updated: 2024/04/09 18:15:22 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rubik.hpp"

int chooseColor(char c)
{
    if (c == 'F')
        return (GREEN);
    else if (c == 'R')
        return (RED);
    else if (c == 'U')
        return (WHITE);
    else if (c == 'B')
        return (BLUE);
    else if (c == 'L')
        return (ORANGE);
    else if (c == 'D')
        return (YELLOW);
    std::cout << "Error in shuffle, " << c << " is not a receveble argument !" << std::endl;
    return (-1);
}

int	turnNumber(std::string command, int i)
{
	std::string	number;
	int j = 0;
	int start = i;
	std::stringstream ss;

	while (command[i] && command[i] != ' ')
	{
		if (command[i] < '0' && command[i] > '9')
		{
			std::cout << "Error in shuffle, " << command[i] << " is not a receveble argument !" << std::endl;
    		return (-1);
		}
		number[j] = command[i]; 
		i++;
	}
	number = command.substr(start, i);
	ss << number;
	ss >> j;
	if (j == 0)
		return (1);
	//std::cout << "j is : " << j << std::endl;
	return (j);
}


Rubik::Rubik(/* args */)
{
	this->redFace.setColor(RED);
	this->orangeFace.setColor(ORANGE);
	this->yellowFace.setColor(YELLOW);
	this->whiteFace.setColor(WHITE);
	this->greenFace.setColor(GREEN);
	this->blueFace.setColor(BLUE);
	//block 1
	this->redFace.setLeftFace(this->greenFace);
	this->greenFace.setBottomFace(this->redFace);
	this->redFace.setBottomFace(this->yellowFace);
	this->greenFace.setLeftFace(this->yellowFace);
	this->yellowFace.setLeftFace(this->redFace);
	this->yellowFace.setBottomFace(this->greenFace);
	//block 2
	this->blueFace.setLeftFace(this->orangeFace);
	this->orangeFace.setBottomFace(this->blueFace);
	this->blueFace.setBottomFace(this->whiteFace);
	this->orangeFace.setLeftFace(this->whiteFace);
	this->whiteFace.setLeftFace(this->blueFace);
	this->whiteFace.setBottomFace(this->orangeFace);
	//mix
	this->redFace.setTopFace(this->whiteFace);
	this->redFace.setRightFace(this->blueFace);
	this->whiteFace.setTopFace(this->redFace);
	this->whiteFace.setRightFace(this->yellowFace);
	this->blueFace.setTopFace(this->redFace);
	this->blueFace.setRightFace(this->redFace);
	this->greenFace.setTopFace(this->orangeFace);
	this->greenFace.setRightFace(this->whiteFace);
	this->yellowFace.setTopFace(this->blueFace);
	this->yellowFace.setRightFace(this->orangeFace);
	this->orangeFace.setTopFace(this->greenFace);
	this->orangeFace.setRightFace(this->yellowFace);
}

Rubik::~Rubik()
{
}

void	Rubik::shuffle(std::string command)
{
	int		i = 0;
	int		j = 0;
	bool	clockwise = true;
	int		color;
	int		turn = 1;

	while (command[i])
	{
		clockwise = true;
		turn = 1;
		while (command[i] && command[i] == ' ')
			i++;
		if (!command[i])
			break ;
		color = chooseColor(command[i]);
		i++;
		//std::cout << "color is " << color << std::endl;
		if (command[i] == '\'')
		{
			//std::cout << "counter clockwise !!" << std::endl;
			clockwise = false;
			i++;
		}
		if (command[i] != ' ')
			turn = turnNumber(command, i);
		while(command[i] && command[i] != ' ')
		{
			if (command[i] < '0' || command[i] > '9')
			{
				std::cout << "Error in shuffle, " << command[i] << " is not a receveble argument !" << std::endl;
    			return ;
			}
			i++;
		}
		if (turn == -1 || color == -1)
			return ;
		j = 0;
		while (j != turn)
		{
			if (clockwise == true)
			{
				std::cout << "face : " << color << " is rotating " << turn << " number of time in clockwise direction !" << std::endl;
				//rightRotateFace(color);
			}
			else
			{
				std::cout << "face : " << color << " is rotating " << turn << " number of time in counter clockwise direction !" << std::endl;
				//leftRotateFace(color);
			}
			j++;
		}
	}
}

void	Rubik::leftRotateFace(int color)
{
	switch (color)
	{
	case RED:
		this->redFace.rotateLeft();
		break;
	case BLUE:
		this->blueFace.rotateLeft();
		break;
	case WHITE:
		this->whiteFace.rotateLeft();
		break;
	case GREEN:
		this->greenFace.rotateLeft();
		break;
	case ORANGE:
		this->orangeFace.rotateLeft();
		break;
	case YELLOW:
		this->yellowFace.rotateLeft();
		break;
	
	default:
		break;
	}
}

void	Rubik::rightRotateFace(int color)
{
	switch (color)
	{
	case RED:
		this->redFace.rotateRight();
		break;
	case BLUE:
		this->blueFace.rotateRight();
		break;
	case WHITE:
		this->whiteFace.rotateRight();
		break;
	case GREEN:
		this->greenFace.rotateRight();
		break;
	case ORANGE:
		this->orangeFace.rotateRight();
		break;
	case YELLOW:
		this->yellowFace.rotateRight();
		break;
	
	default:
		break;
	}
}

bool	Rubik::isResolve()
{
	return (this->blueFace.isFaceComplete() && this->redFace.isFaceComplete()
		&& this->greenFace.isFaceComplete() && this->yellowFace.isFaceComplete()
		&& this->orangeFace.isFaceComplete() && this->whiteFace.isFaceComplete());
}

void	Rubik::resolve()
{

}

