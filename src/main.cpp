#include "Game/Game.h"
#include "Input/KeyParser.h"
#include "Exceptions/ExceptionHandler.h"
#include "FrameLimiter.h"
#include <thread>
#include <iostream>
#include <locale.h>
#include <mutex>

int main()
{
	setlocale(LC_ALL, "");
	char option;
	std::cout << "введите s для открытия настроек управления\n";
	std::cin >> option;
	CommandConverter converter{};
	GameObserver gameObserver{};
	if (option == 's')
	{
		IChangeConfig *ch = new ChangeConfig;
		ch->changeConfigFile(cfg);
	}
	if (ExceptionHandler(converter).checkForException())
		return 1;
	Player player;
	GameObserver eventObserver{};
	CommandReader cr{converter};
	Movement controller(player, eventObserver);
	Game game{controller, cr, gameObserver};
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	WINDOW *fieldWindow = subwin(stdscr, 20, 60, 10, 50);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	wbkgd(fieldWindow, COLOR_PAIR(1));
	DrawField fieldDisplay(controller.getField(), fieldWindow);
	std::mutex mtx;
	mtx.lock();
	std::thread GameThread(&Game::startTheGame, game);
	std::thread FieldDisplayThread([&GameThread, &fieldDisplay]()
								   {while(GameThread.joinable()){
		FrameLimiter().frameLimiter(fieldDisplay);
	} });
	mtx.unlock();
	GameThread.join();
	FieldDisplayThread.join();
	endwin();
	return 0;
}
