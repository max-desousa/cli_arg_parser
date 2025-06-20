#include "cli_expect.h"

cli_option example_options[] = {
  {
    .type = unsigned_int,
    .option_long_name = "number-to-expect",
    .option_short_name = "n",
    .option_default_value = &(uint8_t){5},
    .option_description = "This is a simple number that I am expecting",
  },
  {
    .type = boolean,
    .option_long_name = "boolean-to-expect",
    .option_short_name = "b",
    .option_default_value = &(bool){false},
    .option_description = "This is a simple boolean that I am expecting",
  }
};

static void print_default_value(void* _value, cli_option_type _type) {
  switch (_type) {
    case unsigned_int:
    case signed_int:
      printf("%d\n", *(int*)_value);
      break;
    case string:
      printf("%s\n", (char*)_value);
      break;
    case character:
      printf("%c\n", *(char*)_value);
      break;
    case boolean:
      if (*(bool*)_value) {
        printf("true\n");
      }
      else {
        printf("false\n");
      }
      break;
    default:
      break;
  }
}

static void process_help_message(cli_option _template[], int _count, char** _input) {
  uint8_t iterator;
  bool need_to_print_help;

  need_to_print_help = false;

  for (iterator = 1; iterator < _count; iterator++) {
    if (0 == strcmp(_input[iterator], "--help")) {
      need_to_print_help = true;
      break;
    }
  }

  if (need_to_print_help) {
    printf("----- Help List for %s -----\n\n", _input[0]);
    for (iterator = 0; iterator < 2; iterator++) {
      printf("Option: -%s/--%s\n", _template[iterator].option_short_name, _template[iterator].option_long_name);
      printf("\tDefault value: ");
      print_default_value(_template[iterator].option_default_value, _template[iterator].type);
      printf("\tDescription: %s\n", _template[iterator].option_description);
      printf("\n-----\n\n");
    }
    exit(0);
  }
}

void parse_cli_options(cli_option _template[], int _count, char** _input) {
  process_help_message(_template, _count, _input);
}

int main(int argc, char* argv[]) {
  parse_cli_options(example_options, argc, argv);
  return 0;
}
