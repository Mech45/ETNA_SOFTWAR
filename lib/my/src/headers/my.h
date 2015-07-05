/*
** Header.h for  in /Users/stevenleclerc/Documents/Projets/myPrintf/my_printf/my_printf/emacs
**
** Made by Steven Leclerc
** Login   <lecler_s@etna-alternance.net>
**
** Started on  Wed Apr 23 11:39:49 2014 Steven Leclerc
** Last update Sun Mar 22 16:08:46 2015 COSSON Clement
*/

#ifndef MY_HEADER_H
#define MY_HEADER_H

  ///////////////////////////////////////////////////////
  // PROTOTYPES
  ///////////////////////////////////////////////////////

  void my_printf(char *fstring, ...);
  void my_put_nbr(int nb);
  void my_putchar(int c);
  void my_putstr(char *str);
  int my_strchar(char to_find, char* string);
  int my_strlen(char *str);
  int my_strcmp(char *s1, char *s2);
  int my_strpos(char *, char *);
  char *my_strconcat(char *first_string, char *second_string);
  char *my_strcpy(char *str_source);
  char *my_strncpy(char *, char *, int);
  char *my_strstr(char *str, char *to_find);
  char *my_readline(int alloc);
  char* my_strcpy(char* str_source);
  int my_getnbr(char *str);
  void convertHex (int input, int maj);
  void nibblesIT(int tabEmptyBin[], int recupHexa[]);
  void readHexa(int recupHexa[]);
  void hexaMaj(int input);
  void hexaMin(int input);
  void convOctal(int input);
  int checkChar(char input, int *iPoint);
  void unsignedU(int input);
  void binA(int input);
  void readBin(int tabEmpty[]);
  int  my_str_isnum(char *str);

  typedef struct arg_l
  {
    char letter;
    void (*function)();
  }arg_letter;

#endif
