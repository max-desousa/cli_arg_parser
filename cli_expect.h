#ifndef CLI_EXPECT_H
#define CLI_EXPECT_H

/* Inclusion of headers making libaray possible */
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/* Declaration of option types for user to expect from cli input */
typedef enum {
  unsigned_int,
  signed_int,
  string,
  character,
  boolean,
} cli_option_type;

/* Structure that defines option requirements */
typedef struct {
  cli_option_type type;
  char* option_long_name;
  char* option_short_name;
  void* option_default_value;
  char* option_description;
} cli_option;


/* Declaration of prototypes for "public" functions*/
void parse_cli_options(cli_option _template[], int _count, char** _input);

#endif
