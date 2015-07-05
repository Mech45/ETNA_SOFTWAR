#include "../lib/my/src/headers/my.h"
#include "./headers/selecting.h"
#include "./headers/init_server.h"
#include "./headers/handle_read_command.h"
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

t_listFunc structList[] =
  {
    {"forward", function_forward},
    {"backward", function_backward},
    {"left", function_left},
    {"right", function_right},
    {0,0}
  };

void handle_read_command(s_client* client)
{
  char*         buffer_read;
  int           nread;
  int i;

  buffer_read = malloc(sizeof(char) * 20);
  nread = read(client->fd, buffer_read, 20);
  buffer_read[nread - 2] = '\0';
  my_printf("received : #%s#\n", buffer_read);
  for (i = 0; structList[i].action != 0; i++)
  {
    if (my_strcmp(buffer_read, structList[i].action) == 0)
    {
      structList[i].ptr(client);
    }
  }
  free(buffer_read);
}

void function_forward(s_client* client)
{
  my_printf("OK\n");
  write(client->fd, "ok\n", my_strlen("ok\n"));
}
void function_backward(s_client* client)
{
  my_printf("OK\n");
  write(client->fd, "ok\n", my_strlen("ok\n"));
}
void function_left(s_client* client)
{
  my_printf("OK\n");
  write(client->fd, "ok\n", my_strlen("ok\n"));
}
void function_right(s_client* client)
{
  my_printf("OK\n");
  write(client->fd, "ok\n", my_strlen("ok\n"));
}
