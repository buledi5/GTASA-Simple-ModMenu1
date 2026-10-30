
#include "menu_render.h"
#include "menu.h"

#include "menu_config.h"

namespace GTASimpleMenu
{
    static MenuState state{
        Config::DEFAULT_VISIBLE,
        Config::MENU_X,
        Config::MENU_Y,
        Config::MENU_WIDTH,
        Config::MENU_HEIGHT
    };

    static MenuColors colors{
        Config::COLOR_BACKGROUND,
        Config::COLOR_HEADER,
        Config::COLOR_SELECTED,
        Config::COLOR_TEXT,
        Config::COLOR_DISABLED
    };

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

        const MenuCategory* category = GetCurrentCategory();

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
            state.width, Config::HEADER_HEIGHT,
            colors.header, ""
        });

        commands.push_back({
            DrawCommand::Type::Text,
            state.x + 12.0f,
            state.y + 12.0f,
            0.0f, 0.0f,
            colors.text,
            Config::MENU_TITLE
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

        for (int i = 0;
             i < static_cast<int>(category->items.size());
             ++i)
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

            itemY += Config::ITEM_HEIGHT;
        }

        return commands;
    }
}
