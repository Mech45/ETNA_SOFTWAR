#include "../lib/my/src/headers/my.h"
#include "./headers/selecting.h"
#include "./headers/handle_read_command.h"
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

pthread_mutex_t  mutex_read_and_actions_client1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  mutex_read_and_actions_client2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  mutex_read_and_actions_client3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  mutex_read_and_actions_client4 = PTHREAD_MUTEX_INITIALIZER;

int handle_select(s_client** clients_list_all)
  {
    int                 result;
    struct timeval      tv;
    int                 i;
    pthread_t           threads[4];
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
        pthread_mutex_lock(&(clients_list_all[0]->mutex));
        my_printf("HANDLE SELECT READ OK\n");
        pthread_create(&(threads[0]), NULL,(void*)handle_read_command, (void *)clients_list_all[0]);
        FD_CLR(clients_list_all[0]->fd, &readfs);
      }
      if (FD_ISSET(clients_list_all[0]->fd, &writefs))
      {
        // my_printf("HOST 1 Writing detected\n");
        FD_CLR(clients_list_all[0]->fd, &writefs);
      }
      if (FD_ISSET(clients_list_all[1]->fd, &readfs))
      {
        pthread_mutex_lock(&(clients_list_all[1]->mutex));
        my_printf("HANDLE SELECT READ OK\n");
        pthread_create(&(threads[1]), NULL,(void*)handle_read_command, (void *)clients_list_all[1]);
        FD_CLR(clients_list_all[1]->fd, &readfs);
      }
      if (FD_ISSET(clients_list_all[1]->fd, &writefs))
      {
        // my_printf("HOST 2 Writing detected\n");
        FD_CLR(clients_list_all[1]->fd, &writefs);
      }
      if (FD_ISSET(clients_list_all[2]->fd, &readfs))
      {
        pthread_mutex_lock(&(clients_list_all[2]->mutex));
        my_printf("HANDLE SELECT READ OK\n");
        pthread_create(&(threads[2]), NULL,(void*)handle_read_command, (void *)clients_list_all[2]);
        FD_CLR(clients_list_all[2]->fd, &readfs);
      }
      if (FD_ISSET(clients_list_all[2]->fd, &writefs))
      {
        // my_printf("HOST 3 Writing detected\n");
        FD_CLR(clients_list_all[2]->fd, &writefs);
      }
      if (FD_ISSET(clients_list_all[3]->fd, &readfs))
      {
        pthread_mutex_lock(&(clients_list_all[3]->mutex));
        my_printf("HANDLE SELECT READ OK\n");
        pthread_create(&(threads[3]), NULL,(void*)handle_read_command, (void *)clients_list_all[3]);
        FD_CLR(clients_list_all[3]->fd, &readfs);
      }
      if (FD_ISSET(clients_list_all[3]->fd, &writefs))
      {
        // my_printf("HOST 4 Writing detected\n");
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
