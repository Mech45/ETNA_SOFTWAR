#include "../lib/my/src/headers/my.h"
#include "./headers/init_server.h"
#include "./headers/handler_acceptance_chaining.h"
#include "./headers/main.h"
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


int          init_server()
{
  int                 listener;
  struct sockaddr_in  srv_addr;
  struct protoent     *proto;
  int                 on;

  on = 1;
  if ((proto = getprotobyname("TCP")) == NULL)
    exit(EXIT_FAILURE);
  if ((listener = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
  {
    //TODO Get Error_handler
    exit(EXIT_FAILURE);
  }
  srv_addr.sin_family = AF_INET;
  srv_addr.sin_addr.s_addr = INADDR_ANY;
  srv_addr.sin_port = htons(PORT);
  //OPT TO RE-USE THE SAME PORT
  setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  if ((bind(listener, (const struct sockaddr*)&srv_addr, sizeof(srv_addr))) == -1)
  {
    //TODO Get Error_handler
    exit(EXIT_FAILURE);
  }
  if ((listen(listener, BACKLOG)) == -1)
  {
    //TODO Get Error_handler
    my_printf("Connexion ko\n");
    exit(EXIT_FAILURE);
  }
  my_printf("Connexion ok\n");
  //Function Handle acceptance + create chain per client
  handler_acceptance_chaining(listener);
  my_printf("Connexion ok\n");
  return(listener);
}

void          client_chain_handler_init(char* client_name)
{
  s_client*     client;

  list_chain = malloc(sizeof(s_listChain));
  client = malloc(sizeof(s_client));
  if ((list_chain == NULL) || (client == NULL))
  {
    exit(-1);
  }
  client->name = client_name;
  list_chain->first = client;
}

s_client*     add_client(char* client_name)
{
  s_client*     client;
  s_client*     client_buffer;

  client_buffer = list_chain->first;
  client = malloc(sizeof(s_client));
  client->name = client_name;
  client->next = NULL;
  client_buffer->next = client;
  return (client);
}

void add_clients_list(s_client** clients)
{
    list_chain->clients_list = clients;
}

void deleteAllChain()
{
  s_client* entity;

  while (list_chain->first != NULL)
    {
      entity = list_chain->first;
      list_chain->first = entity->next;
      free(entity);
    }
  free(list_chain);
}
