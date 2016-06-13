#ifndef PEER
#define PEER

#include "contentStructure.h"
#include "mybind.h"

#include <iostream>
#include <cstdlib>
#include <strings.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

/*
struct addrinfo {
   int              ai_flags;
   int              ai_family;
   int              ai_socktype;
   int              ai_protocol;
   socklen_t        ai_addrlen;
   struct sockaddr *ai_addr;
   char            *ai_canonname;
   struct addrinfo *ai_next;
};

int getaddrinfo(const char *node, const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res);

void freeaddrinfo(struct addrinfo *res);

const char *gai_strerror(int errcode);

*/

//99.253.145.155

class Peer {
public:
   //static std::vector<Peer*> peerlist;
   ContentStructure content;

   int sockfd;
   sockaddr_in serv_addr; //= new sockaddr_in(AF_INET, 0, addr, 0);
   sockaddr_in leftPeer;
   sockaddr_in rightPeer;

   Peer() {
      std::cout << "we made one!" << std::endl;
            // Initialize the network "addpeer"
      /* First call to socket() function */
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd < 0) {
         perror("ERROR opening socket");
         exit(1);
      }
      bzero((char *) &serv_addr, sizeof(serv_addr));
      serv_addr.sin_family = AF_INET;
      inet_aton("0.0.0.0", &serv_addr.sin_addr);
      if (mybind(sockfd, &serv_addr) < 0) {
         perror("ERROR on binding");
         exit(1);
      }

      std::cout << serv_addr.sin_addr.s_addr << std::endl;
      std::cout << serv_addr.sin_port << std::endl;
   }

   void setupNetwork() {
      leftPeer = serv_addr;
      rightPeer = serv_addr;
      std::cout << "Peer address " << &serv_addr << std::endl;
      std::cout << "Left address " << &leftPeer << std::endl;
      std::cout << "Right address " << &rightPeer << std::endl;
   }

   void addPeerToNetwork(char *ip, int port) {

   }

   void begin() {
      std::cout << "IT HAS BEGUN" << std::endl;
      for (int i = 0; i < 30; i++) {
         std::cout << i << std::endl;
      }
   }





};
//Peer::peerlist;

#endif
