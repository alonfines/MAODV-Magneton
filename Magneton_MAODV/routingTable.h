#include <vector>

enum RouteStatus {
    ACTIVE, IDLE, EXPIRED
};

struct AodvRoutingEntry {
    // Destination IP Address
    int destAddress;

    // Next Hop
    int nextHop;

    // Number of Hops
    int hopCount;

    // Active Neighbors List
    std::vector<int> activeNeighbors;

    // Sequence Number
    unsigned int seqNum;

    // Lifetime
//    simtime_t lifetime;

    // Route Status
    RouteStatus status;

    // RREQ Status
    bool rreqSent;
    int rreqRetries = 2;


};

// The routing table would then be a collection of these entries:
std::vector<AodvRoutingEntry> routingTable;
