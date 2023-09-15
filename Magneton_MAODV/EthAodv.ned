//Inets Aodv does not multiple Ethernet Interfaces, here we ajust the existing Ned file to support it.  
//Changes: instead of using interface as a single string' we turn it to an arr

import inet.routing.aodv.Aodv; // Adjust the import path to match the location of the original Aodv module

module EthAodv extends Aodv
{
    
}

