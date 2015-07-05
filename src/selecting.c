#include "../lib/my/src/headers/my.h"
#include "./headers/selecting.h"
#include "./headers/handle_read_command.h"
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int handle_select(s_client** clients_list_all)
  {
    int                 result;
    struct timeval      tv;
    int                 i;
    fd_set              readfs;
    fd_set              writefs;

    while (42)
    {
      /*SET TIMEOUT AFTER 2.5 SECONDS*/
      tv.tv_sec = 2;
      tv.tv_usec = 500000;
      FD_ZERO(&readfs);
      FD_ZERO(&writefs);
      for (i = 0; i < BACKLOG - 1; i++)
      {
        FD_SET(clients_list_all[i]->fd, &readfs);
      }
      for (i = 0; i < BACKLOG - 1; i++)
      {
        FD_SET(clients_list_all[i]->fd, &writefs);
      }
      FD_SET(0, &readfs);
      result = select(8, &readfs, &writefs, NULL, &tv);
      if (result == 0)
      {
        my_printf("TIMEOUT!\n");
        result = 1;
      }
      if (FD_ISSET(clients_list_all[0]->fd, &readfs))
      {
        //Read Command from client
        my_printf("HANDLE SELECT READ OK\n");
        handle_read_command(clients_list_all[0]);
        FD_CLR(clients_list_all[0]->fd, &readfs);
      }
      if (FD_ISSET(clients_list_all[0]->fd, &writefs))
      {
        FD_CLR(clients_list_all[0]->fd, &writefs);
      }
      if (FD_ISSET(clients_list_all[1]->fd, &readfs))
      {
        FD_CLR(clients_list_all[1]->fd, &readfs);
      }
      if (FD_ISSET(clients_list_all[1]->fd, &writefs))
      {
        FD_CLR(clients_list_all[1]->fd, &writefs);
      }
      if (FD_ISSET(clients_list_all[2]->fd, &readfs))
      {
        FD_CLR(clients_list_all[2]->fd, &readfs);
      }
      if (FD_ISSET(clients_list_all[2]->fd, &writefs))
      {
        FD_CLR(clients_list_all[2]->fd, &writefs);
      }
      if (FD_ISSET(clients_list_all[3]->fd, &readfs))
      {
        FD_CLR(clients_list_all[3]->fd, &readfs);
      }
      if (FD_ISSET(clients_list_all[3]->fd, &writefs))
      {
        FD_CLR(clients_list_all[3]->fd, &writefs);
      }
      if (FD_ISSET(0, &readfs))
      {
        for (i = 0; i < 4; i++)
          close(clients_list_all[i]->fd);
        close(list_chain->server_info->listener);
        deleteAllChain();
        exit(EXIT_SUCCESS);
      }
    }
  }
