// elev_app.cpp
// клиентский файл
#include "elevator.h" // дл€ объ€влений классов
#include "msoftcon.h"

int main()
{

	building theBuilding;
	while (true)
	{
		theBuilding.master_tick(); // послать временные метки
		// всем лифтам
		wait(1000); // пауза
		// получить запросы этажей от пользователей
		theBuilding.record_floor_reqs();
	}
	return 0;
}
