#ifndef Field_cpp
#define Field_cpp
#include "Field.h"

Field::Field(std::pair<int, int> new_loc, int height, int width, std::pair<int, int> starting_cell,
             std::pair<int, int> finishing_cell)
{
    if (height > 30 || width > 30 || height <= 0 || width <= 0)
    {
        // std::cout << "Invalid value. Height and width will be set to default.\n";
        this->height = DEFAULT_H;
        this->width = DEFAULT_W;
    }
    else
    {
        this->height = height;
        this->width = width;
    }
    this->starting_cell = starting_cell;
    this->finishing_cell = finishing_cell;
    this->new_loc = new_loc;
    // this->field = nullptr;
    this->field = new Cell *[height];
    for (int y = 0; y < height; y++)
    {
        this->field[y] = new Cell[width];
        for (int x = 0; x < width; x++)
        {
            this->field[y][x] = Cell();
            this->field[y][x].set_pass(false);
            this->field[y][x].set_cell_coords(x, y);
        }
    }
}

Field::Field(int height, int width)
{
    if (height > 30 || width > 30 || height <= 0 || width <= 0)
    {
        // std::cout << "Invalid value. Height and width will be set to default.\n";
        this->height = DEFAULT_H;
        this->width = DEFAULT_W;
    }
    else
    {
        this->height = height;
        this->width = width;
    }
    this->starting_cell = std::make_pair(0, 0);
    this->finishing_cell = std::make_pair(this->width - 1, this->height - 1);
    this->new_loc = std::make_pair(-1, -1);
    this->field = nullptr;
}

void Field::change_field(Cell **new_field)
{
    this->field = new_field;
}

int Field::get_height() const
{
    return this->height;
}

int Field::get_width() const
{
    return this->width;
}

std::pair<int, int> Field::get_start() const
{
    return this->starting_cell;
}

std::pair<int, int> Field::get_finish() const
{
    return this->finishing_cell;
}

void Field::field_swap(Field &other)
{
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(starting_cell, other.starting_cell);
    std::swap(finishing_cell, other.finishing_cell);
    std::swap(new_loc, other.new_loc);
    std::swap(field, other.field);
}

Field::Field(Field &&other)
{
    this->field_swap(other);
}

Field::Field(const Field &other)
{
    this->width = other.width;
    this->height = other.height;
    this->starting_cell = other.starting_cell;
    this->finishing_cell = other.finishing_cell;
    this->new_loc = other.new_loc;
    if (other.field != nullptr)
    {
        this->field = new Cell *[other.height];
        for (int y = 0; y < other.height; y++)
        {
            this->field[y] = new Cell[other.width];
            for (int x = 0; x < other.width; x++)
            {
                this->field[y][x] = other.field[y][x];
            }
        }
    }
    else
    {
        this->field = nullptr;
    }
}

Field &Field::operator=(const Field &other)
{
    if (this != &other)
        Field(other).field_swap(*this);
    return *this;
}

Field &Field::operator=(Field &&other)
{
    if (this != &other)
        this->field_swap(other);
    return *this;
}

Cell &Field::get_cell(int x, int y) const
{
    return this->field[y][x];
}

std::pair<int, int> Field::get_new_loc() const
{
    return this->new_loc;
}

void Field::set_new_loc(int x, int y)
{
    this->new_loc.first = x;
    this->new_loc.second = y;
}

Cell **Field::get_field() const
{
    return this->field;
}

Field::~Field()
{
    if (this->field != nullptr)
    {
        for (int y = 0; y < this->height; y++)
            delete[] this->field[y];
        delete[] this->field;
    }
}

#endif