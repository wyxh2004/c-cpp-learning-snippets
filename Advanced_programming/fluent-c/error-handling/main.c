#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEYWORD_ONE_FOUND_FIRST 1
#define KEYWORD_TWO_FOUND_FIRST 2
#define NO_KEYWORD_FOUND 3
#define ERROR 4

typedef struct {
  FILE *file_pointer;
  char *buffer;
} FileParser;

int searchFileForKeywords(FileParser *parser) {
  if (parser == NULL)
    return ERROR;
  while (fgets(parser->buffer, BUFFER_SIZE, parser->file_pointer)) {
    if (strcmp("KEYWORD_ONE\n", parser->buffer) == 0)
      return KEYWORD_ONE_FOUND_FIRST;
    if (strcmp("KEYWORD_TWO", parser->buffer) == 0)
      return KEYWORD_TWO_FOUND_FIRST;
  }
  return NO_KEYWORD_FOUND;
}

void cleanUpParser(FileParser *parser) {
  if (parser) {
    if (parser->buffer)
      free(parser->buffer);
    if (parser->file_pointer)
      fclose(parser->file_pointer);
    free(parser);
  }
}

FileParser *createParser(char *file_name) {
  assert(file_name != NULL && "Invalid filename");
  FileParser *parser = malloc(sizeof(FileParser));
  if (parser) {
    parser->file_pointer = fopen(file_name, "r");
    parser->buffer = malloc(BUFFER_SIZE);
    if (!parser->file_pointer || !parser->buffer) {
      cleanUpParser(parser);
      return NULL;
    }
  }
  return parser;
}

int parseFile(char *file_name) {
  int return_val;
  FileParser *parser = createParser(file_name);
  return_val = searchFileForKeywords(parser);
  cleanUpParser(parser);
  return return_val;
}

int main(void) {
  int return_val;
  return_val = parseFile("test.txt");
  if (return_val == KEYWORD_ONE_FOUND_FIRST)
    printf("Keyword one found first\n");
  return 0;
}