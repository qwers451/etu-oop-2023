#ifndef Cell_cpp
#define Cell_cpp
#include "Cell.h"
#include <algorithm>
#include <map>
#include <random>
#include <vector>

Cell::Cell()
{
    this->event = nullptr;
    this->passability = false;
    this->player_presence = false;
    this->visited = false;
    this->cell_coords = std::make_pair(0, 0);
}

Cell::Cell(Event *event, bool passability, bool player_presence, std::pair<int, int> cell_coords, bool visited)
{
    this->passability = passability;
    this->player_presence = player_presence;
    this->event = event;
    this->cell_coords = cell_coords;
    this->visited = visited;
}

bool Cell::getVisited() const
{
    return this->visited;
}

void Cell::setVisited(bool value)
{
    this->visited = value;
}

void Cell::set_pass(bool value)
{
    this->passability = value;
}

bool Cell::get_pass() const
{
    return this->passability;
}

void Cell::set_player_presence(bool value)
{
    this->player_presence = value;
}

bool Cell::get_player_presence() const
{
    return this->player_presence;
}

Cell::Cell(const Cell &other)
{
    this->passability = other.passability;
    this->player_presence = other.player_presence;
    this->event = other.event;
    this->cell_coords = other.cell_coords;
}

void Cell::cell_swap(Cell &other)
{
    std::swap(player_presence, other.player_presence);
    std::swap(passability, other.passability);
    std::swap(event, other.event);
    std::swap(cell_coords, other.cell_coords);
}

Cell::Cell(Cell &&other)
{
    this->cell_swap(other);
}

Cell &Cell::operator=(Cell &&other)
{
    if (this != &other)
        this->cell_swap(other);
    return *this;
}

Cell &Cell::operator=(const Cell &other) = default;

void Cell::set_event(Event *event)
{
    this->event = event;
}

Event *Cell::get_event() const
{ // �஢�ઠ �� �����ᢨ� �����
    return this->event;
}

std::pair<int, int> Cell::get_cell_coords() const
{
    return this->cell_coords;
}

void Cell::set_cell_coords(int x, int y)
{
    this->cell_coords.first = x;
    this->cell_coords.second = y;
}

int Cell::check_cell(int height, int width, int x, int y)
{
    if (x < 0 || y < 0 || x > width - 1 || y > height - 1)
        return -1;
    else
        return x + y * width; 
}

#endif