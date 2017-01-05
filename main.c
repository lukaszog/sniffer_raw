#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

void printpacket(const unsigned char *data, const unsigned int length)
{
    unsigned char byte;
    unsigned int i=0, j=0;

    for(i; i<length; i++)
    {

        printf("%02x ", data[i]);

        if(((i%16)==15) || (i==length-1))
        {
                for(j=0; j<15-(i%16); j++)
                {
                    printf("   ");
                }
                printf("| ");

                for(j=(i-(i%16)); j <= i; j++)
                {
                    byte = data[j];
                    if((byte > 31) && (byte < 127)) {
                        printf("%c", byte);
                    }
                    else {
                        printf(".");
                    }
                }
                printf("\n");
        }
    }
}

int main() {

    int i=0, recv_length=0, sockfd=0;

    char buffer[10000];

    if((sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
    {
        perror("Create socket error");
    }

    while(1){
        recv_length = recv(sockfd, buffer, 9000, 0);
        printf("Przechwycilem pakiet o rozmiarze %d bajtow\n", recv_length);
        printpacket(buffer, recv_length);
    }

    return 0;
}