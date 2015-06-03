#include "../lib/my/src/headers/my.h"
#include "./headers/main.h"
#include "./headers/init_server.h"
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


int main()
{

  char*               buffer;
  int                 nread;
  fd_set              readfs;
  s_client*           client_one;
  s_client*           client_two;

  init_server();
  client_one = list_chain->first;
  client_two = client_one->next;
  while (42)
  {
    FD_ZERO(&readfs);
    FD_SET(client_one->fd, &readfs);
    FD_SET(client_two->fd, &readfs);
    FD_SET(0, &readfs);
    select(6, &readfs, NULL, NULL, NULL);
    if (FD_ISSET(client_one->fd, &readfs))
    {
      my_printf("Client_One\n");
      buffer = malloc(sizeof(char) * 20);
      nread = read(client_one->fd, buffer, 20);
      buffer[nread] = '\0';
      write(client_two->fd, buffer, my_strlen(buffer));
      free(buffer);
      FD_CLR(client_one->fd, &readfs);
    }
    if (FD_ISSET(client_two->fd, &readfs))
    {
      my_printf("Client_Two\n");
      buffer = malloc(sizeof(char) * 20);
      nread = read(client_two->fd, buffer, 20);
      buffer[nread] = '\0';
      write(client_one->fd, buffer, my_strlen(buffer));
      free(buffer);
      FD_CLR(client_two->fd, &readfs);
    }
    if (FD_ISSET(0, &readfs))
    {
      close(client_one->fd);
      close(client_two->fd);
      //TODO FREE LISTCHAIN
      return (EXIT_SUCCESS);
    }
  }
  return (0);
}
