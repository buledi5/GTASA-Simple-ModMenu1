
#include "menu_render.h"
#include "menu.h"

namespace GTASimpleMenu
{
    static MenuState state;
    static MenuColors colors;

    void SetMenuVisible(bool visible)
    {
        state.visible = visible;
    }

    bool IsMenuVisible()
    {
        return state.visible;
    }

    const MenuState& GetMenuState()
    {
        return state;
    }

    const MenuColors& GetMenuColors()
    {
        return colors;
    }

    std::vector<DrawCommand> BuildDrawCommands()
    {
        std::vector<DrawCommand> commands;

        if (!state.visible)
            return commands;

        const auto* category = GetCurrentCategory();

        if (!category)
            return commands;

        commands.push_back({
            DrawCommand::Type::Rectangle,
            state.x, state.y,
            state.width, state.height,
            colors.background, ""
        });

        commands.push_back({
            DrawCommand::Type::Rectangle,
            state.x, state.y,
            state.width, 45.0f,
            colors.header, ""
        });

        commands.push_back({
            DrawCommand::Type::Text,
            state.x + 12.0f,
            state.y + 12.0f,
            0.0f, 0.0f,
            colors.text,
            "SIMPLE MENU"
        });

        commands.push_back({
            DrawCommand::Type::Text,
            state.x + 12.0f,
            state.y + 60.0f,
            0.0f, 0.0f,
            colors.selected,
            category->title
        });

        float itemY = state.y + 100.0f;
        const int selected = GetCurrentItem();

        for (int i = 0; i < static_cast<int>(category->items.size()); ++i)
        {
            const bool isSelected = (i == selected);

            commands.push_back({
                DrawCommand::Type::Text,
                state.x + 15.0f,
                itemY,
                0.0f, 0.0f,
                isSelected ? colors.selected : colors.text,
                category->items[i].title
            });

            itemY += 32.0f;
        }

        return commands;
    }
}
