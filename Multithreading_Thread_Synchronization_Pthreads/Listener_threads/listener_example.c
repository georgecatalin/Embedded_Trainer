#include <stdio.h>
#include <stdint.h>
#include "network_utils.h"


pthread_t  *listener_thread_1;
pthread_t *listener_thread_2;

void function_to_execute_when_package_recvd(char *packet, uint32_t packet_size, char *IPAddress, uint32_t port_number)
{
    printf("%s invoked in line %d and file name %s \t-> message %s received from sender %s:%u \n", __func__,__LINE__,__FILE__,packet, IPAddress, port_number);
}

int main(void)
{
   printf("Create a new thread to listen on IP 127.0.0.1 and port 3000.\n");
   listener_thread_1 = udp_server_create_and_start("127.0.0.1",3000, function_to_execute_when_package_recvd);

   printf("Create a new thread to listen on IP 127.0.0.1 and port 3001.\n");
    listener_thread_2 = udp_server_create_and_start("127.0.0.1",3001, function_to_execute_when_package_recvd);

   pthread_exit(0);

    return 0;
}