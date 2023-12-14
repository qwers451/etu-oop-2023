#ifndef Movement_h
#define Movement_h
#include "Player.h"
#include "../Enum.h"
#include "Classes.h"
#include "../Field/Field.h"
#include "../Field/DrawField.h"
#include <utility>
#include "../Field/Cell.h"
#include "../Field/FieldGenerator/IFieldGen.h"
#include "../Field/FieldGenerator/FieldGenerator.h"
#include "GameObserver.h"
#include "../Logger/MessageHandler.h"
#include "../Logger/LossLogger.h"

class Movement
{
public:
	Movement(Player &player, Observer &MovementObs, MessageHandler& msg_handler);

	void player_movement(MOVEMENT move);

	void show_coords();

	bool check_coordinates(int x, int y);

	int checkPlayerHealth();

	void check_for_event();

	void update_coords();

	void gameObsUpdate(std::string msg);

	std::pair<int, int> getCoords() const;

	Player &getPlayer() const;

	Field *getField() const;

	void setField(Field *field);

	~Movement() = default;

private:
	std::pair<int, int> coordinates = std::make_pair(0, 0);
	Player &player;
	Field *field;
	Observer &MovementObs;
	MessageHandler& msg_handler;
};

#endif