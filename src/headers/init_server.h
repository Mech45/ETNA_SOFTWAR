#ifndef SOFTWAR_INITSERVER_H
#define SOFTWAR_INITSERVER_H

#define PORT 4242
#define BACKLOG 5
#define EXIT_FAILURE 0
#define EXIT_SUCCESS 1

///////////////////////////////////////////////////////
// STRUCTURES
///////////////////////////////////////////////////////
typedef struct            s_server
{
  int               listener;
}                   s_server;

typedef struct            s_client
{
  char*             name;
  int               fd;
  struct s_client*  next;
}                   s_client;

typedef struct            s_listChain
{
  struct s_client*    first;
  struct s_client**   clients_list;
  struct s_server*    server_info;
}                   s_listChain;

/*GLOBAL CHAIN LIST*/
s_listChain*   list_chain;

///////////////////////////////////////////////////////
// PROTOTYPES
///////////////////////////////////////////////////////

int           init_server();
void          client_chain_handler_init(char* client_name);
s_client*     add_client(char* client_name);
void          add_clients_list(s_client** clients);
void          deleteAllChain();

#endif
