#include "Game/Game.h"
#include "Input/KeyParser.h"
#include "Exceptions/ExceptionHandler.h"
#include "FrameLimiter.h"
#include "Logger/MessageHandler.h"
#include "LoggerOutput/LogOutputManager.h"
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
	if (option == 's')
	{
		IChangeConfig *ch = new ChangeConfig;
		ch->changeConfigFile(cfg);
	}
	if (ExceptionHandler(converter).checkForException())
		return 1;

	Player player;

	std::cout << "Press 1 to output logs into console.\nPress 2 to output logs into file.\nPress 3 to output logs into console and file.\n";
	char log_option;
	std::cin >> log_option;
	
	std::vector<Logger*> log_messages;
	MessageHandler msg_handler(log_messages);
	std::vector<std::string> msg_vector;

	
	GameObserver GameObs(msg_vector);
	CommandReader cr{converter, msg_handler};
	Movement controller(player, GameObs, msg_handler);
	Game game{controller, cr, GameObs, msg_handler};
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
	LogOutputManager(msg_handler).output(log_option);
	return 0;
}
