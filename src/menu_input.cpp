
#include "menu_input.h"
#include "menu.h"
#include "menu_render.h"

namespace GTASimpleMenu
{
    void HandleTouch(float x, float y, bool pressed)
    {
        if (!pressed || !IsMenuVisible())
            return;

        const MenuState& state = GetMenuState();

        if (x < state.x || x > state.x + state.width)
            return;

        if (y < state.y || y > state.y + state.height)
            return;

        const float relativeY = y - state.y;

        if (relativeY < 60.0f)
        {
            NextCategory();
            return;
        }

        if (relativeY < state.height - 50.0f)
        {
            if (relativeY < state.height / 2.0f)
                PreviousItem();
            else
                NextItem();
        }
    }
}
