#include <stdio.h>

// EXEMPLO DE UTILIZAÇÃO DE CORES: 
// printf(CYAN 'exemplo' RESET_COLOR)
// No exemplo, a cor de texto será definida para CYAN e, logo apôs exibir o texto, reseta a cor com RESET_COLOR

// CORES REGULARES
#define BLACK   "\e[0;30m"
#define RED     "\e[0;31m"
#define GREEN   "\e[0;32m"
#define YELLOW  "\e[0;33m"
#define BLUE    "\e[0;34m"
#define PURPLE  "\e[0;35m"
#define CYAN    "\e[0;36m"
#define WHITE   "\e[0;37m"

// CORES E LETRAS EM NEGRITO
#define BLACK_BOLD   "\e[1;30m"
#define RED_BOLD     "\e[1;31m"
#define GREEN_BOLD   "\e[1;32m"
#define YELLOW_BOLD  "\e[1;33m"
#define BLUE_BOLD    "\e[1;34m"
#define PURPLE_BOLD  "\e[1;35m"
#define CYAN_BOLD    "\e[1;36m"
#define WHITE_BOLD   "\e[1;37m"

// CORES E LETRAS COM UNDERLINE
#define BLACK_UNDELINE   "\e[4;30m"
#define RED_UNDELINE     "\e[4;31m"
#define GREEN_UNDELINE   "\e[4;32m"
#define YELLOW_UNDELINE  "\e[4;33m"
#define BLUE_UNDELINE    "\e[4;34m"
#define PURPLE_UNDELINE  "\e[4;35m"
#define CYAN_UNDELINE    "\e[4;36m"
#define WHITE_UNDELINE   "\e[4;37m"

// CORES DE FUNDO
#define BLACK_BACKGROUND   "\e[40m"
#define RED_BACKGROUND     "\e[41m"
#define GREEN_BACKGROUND   "\e[42m"
#define YELLOW_BACKGROUND  "\e[43m"
#define BLUE_BACKGROUND    "\e[44m"
#define PURPLE_BACKGROUND  "\e[45m"
#define CYAN_BACKGROUND    "\e[46m"
#define WHITE_BACKGROUND   "\e[47m"

// CORES COM MAIOR INTENSIDADE DE BRILHO
#define BLACK_HIGH_INTENSITY   "\e[0;90m"
#define RED_HIGH_INTENSITY     "\e[0;91m"
#define GREEN_HIGH_INTENSITY   "\e[0;92m"
#define YELLOW_HIGH_INTENSITY  "\e[0;93m"
#define BLUE_HIGH_INTENSITY    "\e[0;94m"
#define PURPLE_HIGH_INTENSITY  "\e[0;95m"
#define CYAN_HIGH_INTENSITY    "\e[0;96m"
#define WHITE_HIGH_INTENSITY   "\e[0;97m"

// CORES COM MAIOR INTENSIDADE DE BRILHO E LETRAS EM NEGRITO
#define BLACK_BOLD_HIGH_INTENSITY   "\e[1;90m"
#define RED_BOLD_HIGH_INTENSITY     "\e[1;91m"
#define GREEN_BOLD_HIGH_INTENSITY   "\e[1;92m"
#define YELLOW_BOLD_HIGH_INTENSITY  "\e[1;93m"
#define BLUE_BOLD_HIGH_INTENSITY    "\e[1;94m"
#define PURPLE_BOLD_HIGH_INTENSITY  "\e[1;95m"
#define CYAN_BOLD_HIGH_INTENSITY    "\e[1;96m"
#define WHITE_BOLD_HIGH_INTENSITY   "\e[1;97m"

// CORES DE FUNDO COM MAIOR INTENSIDADE DE BRILHO
#define BLACK_HIGH_INTENSITY_BACKGROUND   "\e[0;100m"
#define RED_HIGH_INTENSITY_BACKGROUND     "\e[0;101m"
#define GREEN_HIGH_INTENSITY_BACKGROUND   "\e[0;102m"
#define YELLOW_HIGH_INTENSITY_BACKGROUND  "\e[0;103m"
#define BLUE_HIGH_INTENSITY_BACKGROUND    "\e[0;104m"
#define PURPLE_HIGH_INTENSITY_BACKGROUND  "\e[0;105m"
#define CYAN_HIGH_INTENSITY_BACKGROUND    "\e[0;106m"
#define WHITE_HIGH_INTENSITY_BACKGROUND   "\e[0;107m"

#define RESET_COLOR "\e[0m"
