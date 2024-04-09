/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Face.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:39:02 by lflandri          #+#    #+#             */
/*   Updated: 2024/04/09 18:13:58 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACE
# define FACE
# include <vector>
# include <string>
# define RED 1
# define WHITE 2
# define ORANGE 3
# define GREEN 4
# define BLUE 5
# define YELLOW 6


/*Face of Rubik*/
class Face
{
private:
	int color;
	std::vector< std::vector<int> > caseArray;
	Face *leftFace;
	Face *rightFace;
	Face *topFace;
	Face *bottomFace;

public:

	Face();
	Face(int color);
	~Face();

	/*Set the left face*/
	void							setLeftFace(Face &leftFace);
	/*Set the right face*/
	void							setRightFace(Face &rightFace);
	/*Set the top face*/
	void							setTopFace(Face &topFace);
	/*Set the bottom face*/
	void							setBottomFace(Face &bottomFace);
	/*Rotate the face on the left.
	
	All adjacente case will be update in consequence.
	*/
	void							rotateLeft();
	/*Rotate the face on the right.
	
	All adjacente case will be update in consequence.
	*/
	void							rotateRight();
	/*Return the case off the array.*/
	std::vector< std::vector<int> >	&getCaseArray();
	/*Return true if the frace is complete, false else.
	*/
	bool							isFaceComplete();
	/*Set the color of the face (all case will be change)*/
	void setColor(int color);
};
#endif