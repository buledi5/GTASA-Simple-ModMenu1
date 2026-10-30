
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

    inline std::vector<MenuCategory> CreateMenu()
    {
        return {
            {
                "PLAYER",
                {
                    {"Player Options", false},
                    {"Health Display", false},
                    {"Armor Display", false}
                }
            },
            {
                "VEHICLE",
                {
                    {"Vehicle Options", false},
                    {"Vehicle Repair", false},
                    {"Vehicle Display", false}
                }
            },
            {
                "WORLD",
                {
                    {"World Options", false},
                    {"Time Display", false},
                    {"Weather Display", false}
                }
            },
            {
                "SETTINGS",
                {
                    {"Menu Theme", false},
                    {"Touch Controls", false},
                    {"About", false}
                }
            }
        };
    }
}
