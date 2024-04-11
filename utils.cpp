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