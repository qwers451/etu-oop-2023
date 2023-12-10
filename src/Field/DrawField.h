#ifndef DrawField_h
#define DrawField_h
#include "Field.h"
#include "CellDisplay.h"
#include <ncurses.h>

class DrawField
{
public:
    explicit DrawField(Field *field, WINDOW *fieldWindow);

    DrawField() = default;

    void drawField();

private:
    const Field *field;
    WINDOW *fieldWindow;
};

#endif