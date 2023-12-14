#ifndef GameObserver_h
#define GameObserver_h
#include "Observer.h"

class GameObserver: public Observer{
private:
    std::vector<std::string> msg_vector;
public:
    GameObserver(std::vector<std::string> msg_vector): msg_vector(msg_vector) {}

    void update(std::string msg);

    std::vector<std::string> getMsgVector() const;

    void updateFieldDisplay(WINDOW* fieldDisplay, std::stringstream output);
};

#endif