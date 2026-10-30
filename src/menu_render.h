
#pragma once

#include <string>
#include <vector>

namespace GTASimpleMenu
{
    struct MenuColors
    {
        unsigned int background = 0xE6101010;
        unsigned int header = 0xFF202020;
        unsigned int selected = 0xFF00A8FF;
        unsigned int text = 0xFFFFFFFF;
        unsigned int disabled = 0xFF888888;
    };

    struct MenuState
    {
        bool visible = false;
        float x = 40.0f;
        float y = 80.0f;
        float width = 300.0f;
        float height = 360.0f;
    };

    struct DrawCommand
    {
        enum class Type
        {
            Rectangle,
            Text
        };

        Type type;
        float x;
        float y;
        float width;
        float height;
        unsigned int color;
        std::string text;
    };

    void SetMenuVisible(bool visible);
    bool IsMenuVisible();

    const MenuState& GetMenuState();
    const MenuColors& GetMenuColors();

    std::vector<DrawCommand> BuildDrawCommands();
}
