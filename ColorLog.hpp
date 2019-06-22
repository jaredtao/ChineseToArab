#pragma once
#include <type_traits>
enum class LogType {
    Reset = 0,

    Bold,
    Unbold,

    FrontBlack,
    FrontRed,
    FrontGreen,
    FrontYellow,
    FrontBlue,
    FrontPurple,
    FrontCyan,
    FrontWhite,
    BackBlack,
    BackRed,
    BackGreen,
    BackYellow,
    BackBlue,
    BackPurple,
    BackCyan,
    BackWhite,

    TypeCount
        };
static const char * logCommands[] = {
    "\033[0m",
    "\033[1m",
    "\033[2m",
    "\033[30m",
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
    "\033[37m",
    "\033[40m",
    "\033[41m",
    "\033[42m",
    "\033[43m",
    "\033[44m",
    "\033[45m",
    "\033[46m",
    "\033[47m",
    };
template <typename EnumType, typename IntType = int>
int enumToInt(EnumType enumValue)
{
    static_assert (std::is_enum<EnumType>::value, "EnumType must be enum");

    return static_cast<IntType>(enumValue);
}
