#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
        int inet_sock;
        struct ifreq ifr;
        inet_sock = socket(AF_INET, SOCK_DGRAM, 0);

        strcpy(ifr.ifr_name, "xenbr0");
        if (ioctl(inet_sock, SIOCGIFADDR, &ifr) <  0)
                perror("ioctl");
        printf("%s\n", inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr));

        close(inet_sock);
        return 0;
}
