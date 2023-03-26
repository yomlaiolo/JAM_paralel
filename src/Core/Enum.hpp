/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Enum
*/

#pragma once

namespace Game
{
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

    enum Event {
        NO,
        DOOR,
        KEY,
        TP,
        CHEST,
        ENEMY,
        BOSS,
        PLAYER,
        EXIT
    };
}

