#ifndef FieldGenerator_cpp
#define FieldGenerator_cpp
#include "FieldGenerator.h"
#include "../../Events/Event.h"
#include <vector>
#include <iostream>
#include <random>

FieldGenerator::FieldGenerator(int height, int width, Observer &eventObserver) : height(height), width(width), eventObserver(eventObserver)
{
    if (this->height > 30 || this->width > 30 || this->height <= 0 || this->width <= 0)
    {
        this->height = DEFAULT_H;
        this->width = DEFAULT_W;
    }
    new_field = Field(this->height, this->width);
}

Field *FieldGenerator::create_field(Player &player)
{
    int value;
    value = 1;
    Cell **field = new Cell *[this->height];
    for (int y = 0; y < this->height; y++)
    {
        field[y] = new Cell[this->width];
        for (int x = 0; x < this->width; x++)
        {
            field[y][x] = Cell();
            field[y][x].set_pass(true);
            field[y][x].set_cell_coords(x, y);
        }
    }

    Cell *cur;

    for (int i = 0; i < this->height; i++)
    {

        for (int j = 0; j < this->width; j++)
        {

            cur = &field[i][j];

            int num = ((2 * i + 3 * j) % (20 * value));
            switch (num)
            {
            case 1:
                cur->set_event(new HealingSpot(4, player));
                break;
            case 6:
                cur->set_event(new Trap(10, player));
                break;
            case 19:
                if (i != this->height && j != this->width)
                {
                    cur->set_event(new Teleport(new_field.get_finish(), &new_field, player, eventObserver));
                }
                break;
            case 10:
                if (i != (this->height - 1) && j != (this->width - 1))
                {
                    field[i][j].set_pass(false);
                }
                break;
            }
        }
    }

    new_field.set_new_loc(0, 0);
    new_field.change_field(field);
    return &new_field;
}

#endif