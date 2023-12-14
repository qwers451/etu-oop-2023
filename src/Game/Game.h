#ifndef Game_h
#define Game_h
#include "../Input/CommandReader.h"
#include "../Input/IChangeConfig.h"
#include "../Input/ChangeConfig.h"
#include "Movement.h"
#include "../Exceptions/ExitGame.h"
#include "GameObserver.h"
#include "../Logger/GameLogger.h"
#include "../Logger/WinLogger.h"


class Game
{
public:
    Game(Movement &movement, ICommandReader &cr, Observer &gameObserver, MessageHandler& msg_handler) :
     movement(movement), commandInput(cr), gameObserver(gameObserver), msg_handler(msg_handler) {}

    void startTheGame();

    void setPlayerClass();

    void restart();

    void GameObsUpdate(std::string msg);

    ~Game() = default;

private:
    Movement &movement;
    ICommandReader &commandInput;
    Observer &gameObserver;
    MessageHandler& msg_handler;
};

#endif