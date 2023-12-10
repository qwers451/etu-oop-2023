#ifndef DrawField_cpp
#define DrawField_cpp
#include "DrawField.h"
#include "../Enum.h"
#include <iostream>
#define OFFSET 2
#define START 3

DrawField::DrawField(Field *field, WINDOW *fieldWindow) : field(field), fieldWindow(fieldWindow) {}

void DrawField::drawField()
{
    box(fieldWindow, 0, 0);
    int height = this->field->get_height();
    int width = this->field->get_width();
    mvwprintw(fieldWindow, 1, 5, "pole");
    int x, y;
    int xForPrint = START;
    int yForPrint = START;
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            mvwprintw(fieldWindow, yForPrint, xForPrint, "%s", "     ");
            xForPrint += OFFSET;
        }
        yForPrint++;
        xForPrint = START;
        for (x = 0; x < width; x++)
        {
            mvwprintw(fieldWindow, yForPrint, xForPrint, " ");
            xForPrint += OFFSET;
            mvwprintw(fieldWindow, yForPrint, xForPrint, "%c", CellDisplay().display(this->field->get_cell(x, y)));
            if (CellDisplay().display(this->field->get_cell(x, y)) != 'P')
            {
                if (x == this->field->get_start().first && y == this->field->get_start().second)
                    mvwprintw(fieldWindow, yForPrint, xForPrint, "%c", 'S');
                if (x == this->field->get_finish().first && y == this->field->get_finish().second)
                    mvwprintw(fieldWindow, yForPrint, xForPrint, "%c", 'F');
            }
            xForPrint += OFFSET;
        }
        yForPrint++;
        xForPrint = START;
    }
    wrefresh(fieldWindow);
}

#endif