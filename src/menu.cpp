
#include "menu.h"

namespace GTASimpleMenu
{
    static std::vector<MenuCategory> categories = CreateMenu();

    static int currentCategory = 0;
    static int currentItem = 0;

    std::vector<MenuCategory> CreateMenu()
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

    void NextItem()
    {
        if (categories.empty()) return;

        auto& items = categories[currentCategory].items;
        if (items.empty()) return;

        currentItem = (currentItem + 1) %
                      static_cast<int>(items.size());
    }

    void PreviousItem()
    {
        if (categories.empty()) return;

        auto& items = categories[currentCategory].items;
        if (items.empty()) return;

        currentItem--;

        if (currentItem < 0)
            currentItem = static_cast<int>(items.size()) - 1;
    }

    void NextCategory()
    {
        if (categories.empty()) return;

        currentCategory =
            (currentCategory + 1) %
            static_cast<int>(categories.size());

        currentItem = 0;
    }

    void PreviousCategory()
    {
        if (categories.empty()) return;

        currentCategory--;

        if (currentCategory < 0)
            currentCategory = static_cast<int>(categories.size()) - 1;

        currentItem = 0;
    }

    const MenuCategory* GetCurrentCategory()
    {
        if (categories.empty()) return nullptr;

        return &categories[currentCategory];
    }

    int GetCurrentItem()
    {
        return currentItem;
    }
}
