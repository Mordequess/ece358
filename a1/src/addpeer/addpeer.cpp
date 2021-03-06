/*

addpeer
This causes a new peer to be created and added to your system.
The optional command-line arguments are the ip-address and port associated with one other peer in your system.
If these command-line arguments are not provided, you assume that this is the first peer in the system.
You should output the non-loopback ip address and port at which the peer is created.
The peer is always created on this host.
If the host has more than one non-loopback ip address, you pick any of those addresses to print.

Example usage and output:
$ addpeer
1.2.3.4 50400

$ addpeer 1.2.3.4 50400
3.4.5.6 12013

$ addpeer 1.2.3.4 50400
3.4.5.6 34232


Load-balancing requirement
At any moment, you should ensure that each peer maintains an equally fairshare of the content items.
That is, if at a particular moment we have P peers and C pieces of content, then each peer must host between floor(c/p) and ceiling(c/p) pieces of content.
For us to query and check this, you havethe following additional requirement:

We will write a tcp client that will connect() to the ip-address and port of a peer.
Once the peer accepts the connection request, we will send() the string “allkeys”.
We will then recv().
The peer must send back the keys of all the pieces of content it hosts as a string, separated by ',', and terminated by '0'.

E.g., the string the peer responds with may be “23,4,12,0.”
Your peer may shutdown() the connection as soon as it sends this.
(We will shutdown() from our end anyway.)

*/

#include "../peer.h"
#include "addpeer.h"

void makePeer(char *ip, int port) {
   Peer p(ip, port);
}

void makePeer() {
   Peer p;

}

void runNewPeer(char *ip, int port) {
   pid_t pid = fork(); /* Create a child process */

   switch (pid) {
      case -1: /* Error */
         std::cerr << "Error: fork() failed.\n";
         exit(1);
      case 0: /* Child process */
         makePeer(ip, port);
         break;
      default: /* Parent process */
         //Parent should be quiet
         return;
   }
}

void runFirstPeer() {
   pid_t pid = fork(); /* Create a child process */

   switch (pid) {
      case -1: /* Error */
         std::cerr << "Error: fork() failed.\n";
         exit(1);
      case 0: /* Child process */
         makePeer();
         break;
      default: /* Parent process */
         //Parent should be quiet
         return;
   }
}

int main(int argc, char *argv[]) {
   switch (argc) {//parse input
      char *ip;
      int port;

      case 3:
         ip = argv[1];
         port = atoi(argv[2]);
         runNewPeer(ip, port);
         break;

      case 1:
         runFirstPeer();
         break;

      default:
         std::cerr << "Usage: addpeer [ ip port ]" << std::endl;
         exit(-1);
   } //end of input switch

   return 0;
}
