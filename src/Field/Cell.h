#ifndef Cell_h
#define Cell_h
#include "../Events/Event.h"
#include "../Enum.h"
#include <map>

class Cell
{
public:
    explicit Cell(Event *event, bool passability, bool player_presence, std::pair<int, int> cell_coords, bool visited);

    Cell();

    void set_pass(bool value);

    bool get_pass() const;

    void set_player_presence(bool value);

    bool get_player_presence() const;

    void set_event(Event *event);

    Event *get_event() const;

    std::pair<int, int> get_cell_coords() const;

    void set_cell_coords(int x, int y);

    Cell(const Cell &other);

    Cell &operator=(const Cell &other);

    Cell(Cell &&other);

    Cell &operator=(Cell &&other);

    bool getVisited() const;

    void setVisited(bool value);

    ~Cell()
    {
        if (this->event != nullptr)
            delete event;
    }

private:
    Event *event;
    bool player_presence;
    bool passability;
    bool visited;
    void cell_swap(Cell &other);
    std::pair<int, int> cell_coords;
    int check_cell(int height, int width, int x, int y);
};

#endif