#include "src/game/game.hpp"

int main()
{
    Game game("../scenarios/glider_gun.json");
    game.run();

    return 0;
}