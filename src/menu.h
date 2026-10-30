
#pragma once

#include <string>
#include <vector>

namespace GTASimpleMenu
{
    struct MenuItem
    {
        std::string title;
        bool enabled = false;
    };

    struct MenuCategory
    {
        std::string title;
        std::vector<MenuItem> items;
    };

    std::vector<MenuCategory> CreateMenu();

    // Item navigation
    void NextItem();
    void PreviousItem();

    // Category navigation
    void NextCategory();
    void PreviousCategory();

    // Selection access
    const MenuCategory* GetCurrentCategory();
    int GetCurrentItem();
}
