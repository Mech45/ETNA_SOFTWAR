#include "../lib/my/src/headers/my.h"
#include "./headers/main.h"
#include "./headers/init_server.h"
#include "./headers/handler_acceptance_chaining.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>

pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;

void handler_acceptance_chaining(int listener)
  {
    struct sockaddr_in* cli_addr;
    socklen_t           socklen;
    s_client**          clients;
    pthread_t           threads[4];
//    void*               status;
    s_acceptance_data*  s_data;
    int                 i;
    char*               array_name[4] = {"1","2","3","4"};
    int                 ret;

    socklen = sizeof(cli_addr);
    cli_addr = malloc(sizeof(struct sockaddr_in*));
    s_data = malloc(sizeof(s_acceptance_data));
    clients = malloc(4 * sizeof(s_client));
    s_data->listener = listener;
    s_data->cli_addr = cli_addr;
    s_data->socklen = socklen;
    for(i = 0; i < BACKLOG - 1; i++)
    {
      pthread_mutex_lock(&mutex);
      if (i != 0)
      {
        clients[i] = add_client(my_strconcat("client_", array_name[i]));
      }
      else
      {
        client_chain_handler_init("client_1");
        clients[i] = list_chain->first;
      }
      //create threads
      s_data->client = clients[i];
      pthread_create(&(threads[i]), NULL, thread_acceptance, (void *)s_data);
    }
    for (i = 0, ret = 0; i < 4; i++)
    {
      if (pthread_join(threads[i], NULL) != 0)
      {
        ret = -1;
      }
    }
    if (ret != -1)
    {
      add_clients_list(clients);
      free(s_data);
    }
    else
    {
      perror("pthread_create");
    }
  }

void* thread_acceptance(void* data_array)
  {
    s_client*           client_buff;
    s_acceptance_data*  s_data;
    int                 listener;
    struct sockaddr_in* cli_addr;
    socklen_t           socklen;

    s_data = data_array;
    listener = s_data->listener;
    cli_addr = s_data->cli_addr;
    socklen = s_data->socklen;
    client_buff = s_data->client;
    pthread_mutex_init(&(client_buff->mutex), NULL);
    client_buff->fd = accept(listener, (struct sockaddr *)cli_addr, &socklen);
    my_printf("Host->name : %s\n", s_data->client->name);
    write(client_buff->fd, my_strconcat("Hej!", client_buff->name), my_strlen(my_strconcat("Hej!", client_buff->name)));
    write(client_buff->fd, "\n", my_strlen("\n"));
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
  }
