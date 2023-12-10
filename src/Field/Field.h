#ifndef Field_h
#define Field_h
#include "Cell.h"
#include <utility>
#define DEFAULT_H 10
#define DEFAULT_W 10
#define MAX_H 30
#define MAX_W 30

class Field
{
public:
    explicit Field(std::pair<int, int> new_loc = std::make_pair(-1, -1), int height = DEFAULT_H, int width = DEFAULT_W, std::pair<int, int> starting_cell = std::make_pair(0, 0),
                   std::pair<int, int> finishing_cell = std::make_pair(DEFAULT_W - 1, DEFAULT_H - 1));

    Field(int height, int width);

    int get_height() const;

    int get_width() const;

    std::pair<int, int> get_start() const;

    std::pair<int, int> get_finish() const;

    std::pair<int, int> get_new_loc() const;

    void change_field(Cell **new_field);

    void set_new_loc(int x, int y);

    Cell &get_cell(int x, int y) const;

    Cell **get_field() const;

    Field(const Field &other);

    Field &operator=(const Field &other);

    Field(Field &&other);

    Field &operator=(Field &&other);

    void setHeight(int height);

    ~Field();

private:
    int height;
    int width;
    std::pair<int, int> starting_cell;
    std::pair<int, int> finishing_cell;
    std::pair<int, int> new_loc; 
    Cell **field;
    void field_swap(Field &other);
};

#endif