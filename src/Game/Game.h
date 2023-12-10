#ifndef Game_h
#define Game_h
#include "../Input/CommandReader.h"
#include "../Input/IChangeConfig.h"
#include "../Input/ChangeConfig.h"
#include "Movement.h"
#include "../Exceptions/ExitGame.h"
#include "GameObserver.h"

class Game
{
public:
    Game(Movement &movement, ICommandReader &cr, Observer &gameObserver) : movement(movement), commandInput(cr), gameObserver(gameObserver) {}

    void startTheGame();

    void setPlayerClass();

    void restart();

    void GameObsUpdate(std::string msg);

    ~Game() = default;

private:
    Movement &movement;
    ICommandReader &commandInput;
    Observer &gameObserver;
};

#endif