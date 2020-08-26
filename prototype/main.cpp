/*******************************************************************
 * * Program name: 	main.hpp
 * * Author:		Benjamin Hillen
 * * Date: 		    5 December 2019
 * * Description: 	Driver of the Cat Comes Back Game, seeds the
 * *                random number generator, creates a Game object,
 * *                then runs the game by calling mainMenu().
*******************************************************************/

#include "Game.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(NULL));
    
    Game game;

    game.mainMenu();

    return 0;
}