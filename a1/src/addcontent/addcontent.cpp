/*

addcontent
This takes as argument the ip-address and port of some peer in your system, and a piece of content.
It adds a new piece of content into the system.
You choose a peer to host the content – this is not necessarily the peer that we provide as command-line argument.
The content,  which is provided as command-line argument, is just a string.
This command outputs, to stdout, a unique positive integer key by which this content may be retrieved from your peer-to-peer system.

Exampleusage and output:

$ addcontent 1.2.3.4 50400 "Alias Grace"
12

$ addcontent 3.4.5.6 34232 "Come, Thou Tortoise"
328

$ addcontent 1.2.3.4 50400 "No Great Mischief"
33

$ addcontent 3.4.5.6 50400 "Fifth Business"
Error: no such peer

*/

#include "addcontent.h"

int main(int argc, char *argv[]) {
   switch (argc) {//parse input
      case 4:
         //forward the request to the input ip/port.
         //if this peer matches those params
            //if more than a single peer
               //if s.size()+1 > ceil(c/p)
                  //pass to the next peer in line for load balancing
            //std::cout << s.addContent(argv[3])) << std::endl;
         break;

      default:
         std::cerr << "Usage: addcontent ip port content" << std::endl;
         exit(-1);

   } //end of input switch

}
