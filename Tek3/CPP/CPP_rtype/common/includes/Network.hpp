#ifndef NETWORK_SPEC
#define NETWORK_SPEC

#include <ctime>

namespace rtype {
    namespace network {

        enum CodeAction {
            RIGHT = 1,
            LEFT = 2,
            UP = 4,
            DOWN = 8,
            SHOOT = 16,
            PLAY = 64,
            QUIT = 128
        };

        enum MessageTypeServer {
            DISPLAY_REFRESH = 1,
            DELETE_CPT = 2,
            ENDPOINT_S = 3,
            ENDGAME = 4
        };

        enum MessageTypeClient {
            CODE_ACTION = 2,
            ENDPOINT_C = 3
        };

        //client
        struct CodeActionMssg
        {
            int type = MessageTypeClient::CODE_ACTION; //CodeAction(2)
            std::time_t timestamp;
            int nb_player;
            int action;
        };

        //server
        struct DisplayRefreshMssg
        {
            int type = MessageTypeServer::DISPLAY_REFRESH;
            char uuiid[37]; //+ \0
            std::time_t timestamp;
            unsigned long mask_bitset;
            char message[2000];
        };

        //server
        struct DeleteComponentMssg
        {
            int type = MessageTypeServer::DELETE_CPT;
            char uuid[37]; //+ \0
            unsigned long mask_bitset;
        };

        //server and client
        struct EndpointMssg
        {
            int type = MessageTypeServer::ENDPOINT_S; //same value as the client ENDPOINT_S
            char addr[13];
            unsigned short port;
        };

        //server
        struct EndGameMssg
        {
            int type = MessageTypeServer::ENDGAME;
            bool has_won;
        };

    }
}

#endif
