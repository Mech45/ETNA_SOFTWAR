#ifndef SOFTWAR_ACCEPTANCE_H
#define SOFTWAR_ACCEPTANCE_H
#include "./init_server.h"
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <arpa/inet.h>


///////////////////////////////////////////////////////
// STRUCTURES
///////////////////////////////////////////////////////

typedef struct            s_acceptance_data
{
  int                 listener;
  struct sockaddr_in* cli_addr;
  socklen_t           socklen;
  s_client*           client;
}                   s_acceptance_data;

///////////////////////////////////////////////////////
// PROTOTYPES
///////////////////////////////////////////////////////

void handler_acceptance_chaining(int listener);
void* thread_acceptance(void* client);

#endif
