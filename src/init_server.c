#include "../lib/my/src/headers/my.h"
#include "./headers/init_server.h"
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


void          init_server()
{
  int                 listener;
  struct sockaddr_in  srv_addr;
  struct sockaddr_in  cli_addr;
  socklen_t           socklen;
  struct protoent     *proto;
  s_client*           client_one;
  s_client*           client_two;

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
  socklen = sizeof(cli_addr);
  client_chain_handler_init("client_one");
  client_one = list_chain->first;
  client_two = add_client("client_two");
  client_one->fd = accept(listener, (struct sockaddr *)&cli_addr, &socklen);
  client_two->fd = accept(listener, (struct sockaddr *)&cli_addr, &socklen);
  if (client_one->fd == -1 || client_two->fd == -1)
  {
    exit(EXIT_FAILURE);
  }
  my_printf("Connexion ok\n");
  write(client_one->fd, my_strconcat("Hej!", client_one->name), my_strlen(my_strconcat("Hej!", client_one->name)));
  write(client_two->fd, my_strconcat("Hej!", client_two->name), my_strlen(my_strconcat("Hej!", client_two->name)));

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

s_client* add_client(char* client_name)
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
