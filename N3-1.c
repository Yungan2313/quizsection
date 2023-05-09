#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#define MAX_LINE_LEN 60
 
// char line[MAX_LINE_LEN+1];
struct word_linked_list{
    char word;
    struct word_linked_list *next;
};
struct word_linked_list *linell = NULL;
int line_len = 0;
int num_words = 0;
void clear_line(void)
{
  struct word_linked_list *cur;
  while(linell != NULL){
    cur = linell;
    linell = linell->next;
    free(cur);
  }
  linell = malloc(sizeof(struct word_linked_list));
  linell->word = '\0';
  linell->next = NULL;
  // line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  struct word_linked_list *temp = linell;
  while(temp->next != NULL){
    temp = temp->next;
  }
  if (num_words > 0) {
    struct word_linked_list *new_node,*new_node_next;
    new_node = malloc(sizeof(struct word_linked_list));
    new_node_next = malloc(sizeof(struct word_linked_list));
    new_node->word = ' ';
    new_node->next = new_node_next;
    new_node_next->word = '\0';
    new_node_next->next = NULL;
    temp->next = new_node;
    temp = temp->next;
    //line[line_len] = ' ';
    // line[line_len+1] = '\0';
    line_len++;
  }
  int word_len = strlen(word);
  for(int i = 0;i<word_len;i++){
    struct word_linked_list *new_node;
    new_node = malloc(sizeof(struct word_linked_list));
    new_node->word = *(word+i);
    new_node->next = NULL;
    if(linell->word == '\0'){
      linell = new_node;
      temp = linell;
    }
    else{
      temp->next = new_node;
      temp = temp->next;
    }
  }
  // strcat(line, word);
  line_len += strlen(word);
  num_words++;
}
 
int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, i, j;
 
  extra_spaces = MAX_LINE_LEN - line_len;
  struct word_linked_list *temp;
  for (temp = linell; temp != NULL; temp = temp->next) {

    if(temp->word != ' '){
      putchar(temp->word);
    }
    else{
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
    i++;
    // if (line[i] != ' ')
    //   putchar(line[i]);
    // else {
    //   spaces_to_insert = extra_spaces / (num_words - 1);
    //   for (j = 1; j <= spaces_to_insert + 1; j++)
    //     putchar(' ');
    //   extra_spaces -= spaces_to_insert;
    //   num_words--;
    // }
  }
  putchar('\n');
}
 
void flush_line(void)
{
  if(line_len > 0){
    struct word_linked_list *temp = linell;
    while(temp->next != NULL){
      putchar(temp->word);
      temp = temp->next;
    }
    putchar(temp->word);
  }
  // if (line_len > 0)
  //   puts(line);
}
