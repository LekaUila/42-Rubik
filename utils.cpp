#include "header.hpp"


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