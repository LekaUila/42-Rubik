/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Face.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:38:52 by lflandri          #+#    #+#             */
/*   Updated: 2024/04/09 17:24:55 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Face.hpp"

	Face::Face(int color)
	:color(color)
	{
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				this->caseArray[i][j] = color;
			}
		}
	}
	
	Face::~Face()
	{
		
	}

	/*Set the left face*/
	void							Face::setLeftFace(Face &leftFace)
	{
		this->leftFace = &leftFace;
	}
	
	/*Set the right face*/
	void							Face::setRightFace(Face &rightFace)
	{
		this->rightFace = &rightFace;

	}
	
	/*Set the top face*/
	void							Face::setTopFace(Face &topFace)
	{
		this->topFace = &topFace;

	}
	
	/*Set the bottom face*/
	void							Face::setBottomFace(Face &bottomFace)
	{
		this->bottomFace = &bottomFace;

	}
	
	/*Rotate the face on the left.
	
	All adjacente case will be update in consequence.
	*/
	void							Face::rotateLeft()
	{
		std::vector<std::vector<int>>	copyActualFAce;
		std::vector<int>				copyLeftLignFace;
		std::vector<int>				copyRightLignFace;
		std::vector<int>				copyTopLignFace;
		std::vector<int>				copyBottomLignFace;

		for (size_t i = 0; i < 3; i++)
		{
			copyLeftLignFace[i] = this->leftFace->getCaseArray()[2][i];
			copyBottomLignFace[i] = this->bottomFace->getCaseArray()[i][0];
			copyRightLignFace[i] = this->rightFace->getCaseArray()[i][2];
			copyTopLignFace[i] = this->topFace->getCaseArray()[0][i];
			for (size_t j = 0; j < 3; j++)
			{
				copyActualFAce[i][j] = this->caseArray[i][j];
			}
		}
		for (size_t i = 0; i < 3; i++)
		{
			this->caseArray[i][2] = copyActualFAce[2][2 - i];

			this->caseArray[2][2 - i] = copyActualFAce[2 - i][0];
			this->caseArray[2 - i][0] = copyActualFAce[0][i];
			this->caseArray[0][i] = copyActualFAce[i][2];

			this->leftFace->getCaseArray()[2][2 - i] = copyTopLignFace[i];
			this->bottomFace->getCaseArray()[i][0] = copyLeftLignFace[i];
			this->rightFace->getCaseArray()[2 - i][2] = copyBottomLignFace[i];
			this->topFace->getCaseArray()[0][i] = copyRightLignFace[i];
		}
	}
	
	/*Rotate the face on the right.
	
	All adjacente case will be update in consequence.
	*/
	void							Face::rotateRight()
	{
		std::vector<std::vector<int>>	copyActualFAce;
		std::vector<int>				copyLeftLignFace;
		std::vector<int>				copyRightLignFace;
		std::vector<int>				copyTopLignFace;
		std::vector<int>				copyBottomLignFace;

		for (size_t i = 0; i < 3; i++)
		{
			copyLeftLignFace[i] = this->leftFace->getCaseArray()[2][i];
			copyBottomLignFace[i] = this->bottomFace->getCaseArray()[i][0];
			copyRightLignFace[i] = this->rightFace->getCaseArray()[i][2];
			copyTopLignFace[i] = this->topFace->getCaseArray()[0][i];
			for (size_t j = 0; j < 3; j++)
			{
				copyActualFAce[i][j] = this->caseArray[i][j];
			}
		}
		for (size_t i = 0; i < 3; i++)
		{
			this->caseArray[i][2] = copyActualFAce[0][i];
			this->caseArray[2][2 - i] = copyActualFAce[i][2];
			this->caseArray[2 - i][0] = copyActualFAce[2][2 - i];
			this->caseArray[0][i] = copyActualFAce[2 - i][0];

			this->leftFace->getCaseArray()[2][i] = copyBottomLignFace[i];
			this->bottomFace->getCaseArray()[2 - i][0] = copyRightLignFace[i];
			this->rightFace->getCaseArray()[i][2] = copyTopLignFace[i];
			this->topFace->getCaseArray()[0][2 - i] = copyLeftLignFace[i];
		}
	}
	
	/*Return the case off the array.*/
	std::vector<std::vector<int>>	&Face::getCaseArray()
	{
		return (this->caseArray);
	}
	
	/*Return true if the frace is complete, false else.
	*/
	bool							Face::isFaceComplete()
	{
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if(this->caseArray[i][j] != color)
				{
					return (false);
				}
			}
		}
		return (true);
	}
	