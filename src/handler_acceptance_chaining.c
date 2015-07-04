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

pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;

void handler_acceptance_chaining(int listener)
  {
    struct sockaddr_in* cli_addr;
    socklen_t           socklen;
    s_client*           clients[4];
    pthread_t           threads[4];
    s_acceptance_data*  s_data;
    int                 i;
    char*               array_name[4] = {"1","2","3","4"};

    /* HANDLE MUTEX */
    //mutex = PTHREAD_MUTEX_INITIALIZER;
    socklen = sizeof(cli_addr);
    cli_addr = malloc(sizeof(struct sockaddr_in*));
    s_data = malloc(sizeof(s_acceptance_data));
    s_data->listener = listener;
    s_data->cli_addr = cli_addr;
    s_data->socklen = socklen;
    client_chain_handler_init("client_1");
    clients[0] = list_chain->first;
    for (i = 1; i < BACKLOG; i++)
    {
      pthread_mutex_lock(&mutex);
      clients[i] = add_client(my_strconcat("client_", array_name[i-1]));
      //create thread with para addr of chain client
      s_data->client = clients[i];
      pthread_create(&(threads[i]), NULL, thread_acceptance, (void *)s_data);
    }

    //TODO Handle each entrance connexion on loop + THREAD

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
    client_buff->fd = accept(listener, (struct sockaddr *)cli_addr, &socklen);
    pthread_mutex_unlock(&mutex);
    my_printf("Host->name : %s", s_data->client->name);
    write(client_buff->fd, my_strconcat("Hej!", client_buff->name), my_strlen(my_strconcat("Hej!", client_buff->name)));
    pthread_exit(NULL);
  }
