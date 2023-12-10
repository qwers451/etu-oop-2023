#ifndef Movement_cpp
#define Movement_cpp
#include "Movement.h"
#include <string>
#include <mutex>
#include <iostream>

Movement::Movement(Player &player, Observer &MovementObs) : player(player), MovementObs(MovementObs)
{
	IFieldGen *ev = new FieldGenerator(7, 13, MovementObs);
	this->setField(ev->create_field(this->player));
	this->update_coords();
}

std::mutex mtx;

void Movement::gameObsUpdate(std::string obsMessage)
{
	MovementObs.update(obsMessage);
}

void Movement::player_movement(MOVEMENT move)
{
	int new_x = this->coordinates.first;
	int new_y = this->coordinates.second;
	switch (move)
	{
	case MOVEMENT::RIGHT:
		new_x += 1;
		break;
	case MOVEMENT::LEFT:
		new_x -= 1;
		break;
	case MOVEMENT::UP:
		new_y -= 1;
		break;
	case MOVEMENT::DOWN:
		new_y += 1;
		break;
	default:
		break;
	}
	if (!this->check_coordinates(new_x, new_y))
	{
		return;
	}
	if (this->field->get_cell(new_x, new_y).get_pass())
	{
		;
		this->field->get_cell(this->coordinates.first, this->coordinates.second).set_player_presence(false);
		this->coordinates.first = new_x;
		this->coordinates.second = new_y;
		this->field->get_cell(new_x, new_y).set_player_presence(true);
		this->field->get_cell(new_x, new_y).setVisited(true);
		this->gameObsUpdate("X: " + std::to_string(new_x) + " Y: " + std::to_string(new_y) + " hp:" + std::to_string(this->player.get_hp()));
		if (this->field->get_cell(new_x, new_y).get_event() != nullptr)
		{
			this->check_for_event();
			this->update_coords();
		}
	}
}

void Movement::show_coords()
{
	mvprintw(9, 1, "X: %d", this->coordinates.first);
	mvprintw(10, 1, "Y: %d", this->coordinates.second);
}

bool Movement::check_coordinates(int x, int y)
{
	if (x >= 0 && x <= this->field->get_width() & y >= 0 && y < this->field->get_height())
		return true;
	else
		return false;
}

void Movement::update_coords()
{
	std::lock_guard<std::mutex> guard(mtx);
	int x = this->field->get_new_loc().first;
	int y = this->field->get_new_loc().second;
	if (x == -1)
	{
		return;
	}
	int prev_x = this->coordinates.first;
	int prev_y = this->coordinates.second;
	delete this->field->get_cell(prev_x, prev_y).get_event();
	this->field->get_cell(prev_x, prev_y).set_event(nullptr);
	this->field->get_cell(prev_x, prev_y).set_player_presence(false);
	if (this->check_coordinates(x, y))
	{
		this->coordinates.first = x;
		this->coordinates.second = y;
		this->field->get_cell(x, y).set_player_presence(true);
	}
	this->field->set_new_loc(-1, -1);
}

void Movement::check_for_event()
{
	this->field->get_cell(this->coordinates.first, this->coordinates.second).get_event()->event_trigger();
	this->update_coords();
}

std::pair<int, int> Movement::getCoords() const
{
	return this->coordinates;
}

Player &Movement::getPlayer() const
{
	return this->player;
}

Field *Movement::getField() const
{
	return this->field;
}

void Movement::setField(Field *new_field)
{
	this->field = new_field;
}

int Movement::checkPlayerHealth()
{
	return this->player.get_hp();
}

#endif