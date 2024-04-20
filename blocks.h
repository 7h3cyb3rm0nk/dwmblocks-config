// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 40, 0},

    {"", "date '+%b-%d-(%a)-%I:%M%p'", 5, 0},
    {"", "cat /sys/class/power_supply/BAT1/capacity", 5, 0},
    {"",
     "cat /sys/class/power_supply/BAT1/status| grep Charging | sed "
     "s/Charging/chrgng/g ",
     5, 0},
    {"", "nmcli dev | grep -E 'wlp45s0' | awk {'print $NF'}", 7, 0},
};

// sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
