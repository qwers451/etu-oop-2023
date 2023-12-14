#ifndef Game_cpp
#define Game_cpp
#include "Game.h"
#include <climits>

void Game::restart()
{
	this->movement.getPlayer().set_health(Classes(this->movement.getPlayer().get_class()).hP);
	this->movement.getField()->set_new_loc(0, 0);
	this->movement.update_coords();
}

void Game::setPlayerClass()
{
	this->GameObsUpdate("1 FIGHTER\n2 SPION\n3 PIRAT");
	char input;
	input = getch();
	switch (input)
	{
	case ('1'):
		this->movement.getPlayer().set_character(CLASS::FIGHTER);
		break;
	case ('2'):
		this->movement.getPlayer().set_character(CLASS::SPION);
		break;
	case ('3'):
		this->movement.getPlayer().set_character(CLASS::PIRAT);
		break;
	default:
		break;
	}
	erase();
}

void Game::GameObsUpdate(std::string obsMassege)
{
	gameObserver.update(obsMassege);
}

void Game::startTheGame()
{
	std::pair<int, int> field_size = std::make_pair(
		this->movement.getField()->get_height(), 
		this->movement.getField()->get_width());
	msg_handler.msg_update(new GameLogger(field_size,
		this->movement.getField()->get_start()));

	this->setPlayerClass();
	while (true)
	{
		COMMAND cmd = commandInput.read();
		if (cmd == COMMAND::QUIT)
		{
			break;
		}
		if (cmd == COMMAND::MOVEUP)
		{
			this->movement.player_movement(MOVEMENT::UP);
		}
		if (cmd == COMMAND::MOVERIGHT)
		{
			this->movement.player_movement(MOVEMENT::RIGHT);
		}
		if (cmd == COMMAND::MOVELEFT)
		{
			this->movement.player_movement(MOVEMENT::LEFT);
		}
		if (cmd == COMMAND::MOVEDOWN)
		{
			this->movement.player_movement(MOVEMENT::DOWN);
		}
		if ((this->movement.checkPlayerHealth() == 0) || this->movement.getCoords().first == this->movement.getField()->get_finish().first && this->movement.getCoords().second == this->movement.getField()->get_finish().second)
		{	
			init_pair(1, COLOR_RED, COLOR_BLACK);
			this->GameObsUpdate("restart r. quit any.");
			char option = getch();
			if (option == 'r')
			{
				init_pair(1, COLOR_BLUE, COLOR_BLACK);
				this->restart();
				erase();
			}
			else
				break;
		}
	}
}

#endif