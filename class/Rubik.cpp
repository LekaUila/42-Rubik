/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rubik.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:40:37 by lflandri          #+#    #+#             */
/*   Updated: 2024/04/11 15:06:05 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rubik.hpp"

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
	this->whiteFace.setRightFace(this->greenFace);
	this->blueFace.setTopFace(this->yellowFace);
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
	this->printRubikFaces();
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
				rightRotateFace(color);
				this->printRubikFaces();
			}
			else
			{
				std::cout << "face : " << color << " is rotating " << turn << " number of time in counter clockwise direction !" << std::endl;
				leftRotateFace(color);
				this->printRubikFaces();
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

void	Rubik::printRubikFaces()
{
	std::string	couleurCode[6] = {"\e[0;31m","\e[1;37m","\e[0;33m","\e[1;32m","\e[1;34m","\e[1;33m"};
	std::string	reset = "\e[0;m";
	std::vector< std::vector<int> > whiteArray = this->whiteFace.getCaseArray();
	std::vector< std::vector<int> > redArray = this->redFace.getCaseArray();
	std::vector< std::vector<int> > orangeArray = this->orangeFace.getCaseArray();
	std::vector< std::vector<int> > yellowArray = this->yellowFace.getCaseArray();
	std::vector< std::vector<int> > greenArray = this->greenFace.getCaseArray();
	std::vector< std::vector<int> > blueArray = this->blueFace.getCaseArray();

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "                ";
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << couleurCode[whiteArray[2 - i][2 - j]  - 1] << "■ " << reset;
		}
		std::cout << std::endl;
		
	}

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << couleurCode[orangeArray[2 - j][i]  - 1] << "■ " << reset;
		}
		std::cout << "  ";
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << couleurCode[greenArray[j][2 - i]  - 1] << "■ " << reset;
		}
		std::cout << "  ";

		for (size_t j = 0; j < 3; j++)
		{
			std::cout << couleurCode[redArray[i][j]  - 1] << "■ " << reset;
		}
		std::cout << "  ";
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << couleurCode[blueArray[2 - i][2 - j]  - 1] << "■ " << reset;
		}
		std::cout << std::endl;
		
	}



	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "                ";
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << couleurCode[yellowArray[2 - j][i] - 1] << "■ " << reset;
		}
		std::cout << std::endl;
		
	}
	
}

