/*
** EPITECH PROJECT, 2020
** b-cpp-500-par-5-1-babel-aurele.auboin
** File description:
** main
*/

#include <boost/asio.hpp>
#include <cstring>
#include <iostream>
#include "components/Exception.hpp"
#include "RType.hpp"
// #include "Network.hpp"
#include "scene/SceneManager.hpp"
#include <cstdlib>


static int display_flag_h(void);
static int is_correct_argument(int ac, char **av, char **env);
static void r_type_client(std::string ip, int port);

int main(int argc, char **argv, char **env)
{
    if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help") || !strcmp(argv[1], "--help"))) {
        return (display_flag_h());
    }
    if (is_correct_argument(argc, argv, env) == Err)
        return (Err);
    try {
        // r_type_client(std::strcmp(argv[1], "localhost") ? std::string(argv[1]) : std::string("127.0.0.1"), atoi(argv[2]));
        rtype::client::SceneManager(std::strcmp(argv[1], "localhost") ? std::string(argv[1]) : std::string("127.0.0.1"), atoi(argv[2])).loop();
    } catch(rtype::component::Exception &exception) {
        std::cerr << exception.what();
        return (exception.getValue());
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        std::cerr << "[Exception]: An error has occurred in Client. Please contact the developper team." << std::endl;
        return (Err);
    }
    return (Ok);
}

static int display_flag_h(void)
{
    std::cout << "USAGE: ./r-type_client ip_server port_server" << std::endl;
    std::cout << "This command will execute the client side of the R-Type project." << std::endl;
    std::cout << "The client handle games" << std::endl;
    std::cout << "R-Type is an iconic side-scrolling shoot\'em up video game." << std::endl;
    return (0);
}

static int is_correct_argument(int ac, char **av, char **env)
{
    if (env == NULL) {
        std::cerr << "[Error]: No environnement." << std::endl;
        return (Err);
    }
    if (ac != 3) {
        std::cerr << "Invalid nbr of argument. Take look at --help." << std::endl;
        return (Err);
    }
    for (int i = 0; av[2] && av[2][i]; i++)
        if (!(av[2][i] >= '0' && av[2][i] <= '9') || atoi(av[2]) == 0) {
            std::cerr << "[Argument]: Invalid Port." << std::endl;
            return (Err);
        }
    try {
        if (av[1] && std::strcmp(av[1], "localhost") != 0)
            boost::asio::ip::address::from_string(av[1]);
    } catch(...) {
        std::cerr << "[Argument]:Invalid Ip." << std::endl;
        return (Err);
    }
    return (Ok);
}


#include "systems/Network.hpp"
#include "components/Network.hpp"
#include "systems/NetworkClient.hpp"
#include "singleton/ECManager.hpp"

enum stateClient_e {
    QUIT = 1,
    SOLO = 11,
    DUO = 12,
    TRIO = 13,
    QUAD = 14,
};

static void r_type_client(std::string ip, int port)
{

    // Contexte de la fonction:
    // - Le client vient de clique sur le bouton player
    // - Et a choix au préalable, il voulait combien qu'autre joueur (entre 0 à 3 autres joueur)

    /*<<<<<< SYNC TCP BOOST ASIO    */

    // Start Client TCP and Connect to Server
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket(io_service); // Creation Socket TCP
    socket.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip.data()), port)); // Connection TCP avec le Server
    std::cout << "[Start]: Client succesfull connected." << std::endl;


    // Send structure rtype::system::codeAction_t to Server avec le nbr de coéquipier
    rtype::network::CodeActionMssg transfert = {};
    transfert.type = rtype::network::MessageTypeClient::CODE_ACTION;
    transfert.timestamp = 0;
    ////////////    RANDON SUR LE NBR DE COEQUIPER     /////////////////////////////////////////////////////////////
    std::srand(std::time(nullptr));
    transfert.nb_player = 2; // CHOIX D'UNE TEAMS: INT ENTRE 11 ET 14 (correspond à l'enum SOLO ET QUAD)
    // transfert.nb_player = 10 + ((std::rand() % 4) + 1); // CHOIX D'UNE TEAMS: INT ENTRE 11 ET 14 (correspond à l'enum SOLO ET QUAD)
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::string nbr = (transfert.nb_player == 1 ? "SOLO" : (transfert.nb_player == 2 ? "DUO" : (transfert.nb_player == 3 ? "TRIO" : (transfert.nb_player == 4 ? "QUAD" : ("NONE"))))); // Juste de l'affichage
    std::cout << std::string("Search type of team: " + nbr + " People ...") << std::endl;
    transfert.action = rtype::network::CodeAction::PLAY; // J'ai vu ça dans la doc # gros menteur antoine
    // Le reste de la structure n'est pas utilisé ...
    // Convertion de la struct en string
    std::vector<char> msg;
    msg.resize(sizeof(rtype::network::CodeActionMssg));
    std::memcpy(msg.data(), &transfert, sizeof(rtype::network::CodeActionMssg));
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg), error); // Envoie de la struct
    if (error) { // Fatale Erreur
        std::cout << "[Error]: client send failed (" << error.message() << ")" << std::endl;
        socket.close();
        io_service.stop();
        return;
    }
    std::cout << "[Send]: Client sent: '" << nbr << "'" << std::endl;


    // Réception de l'endpoint UDP du SERVER (quand les autres joueurs ont été trouvé)
    // (récup une string qui contient la struct rtype::component::MyNetworkInfo)
    boost::asio::streambuf receive_buffer;

    boost::asio::read(socket, receive_buffer, boost::asio::transfer_at_least(1), error); // récupération de ce que le server envoie
    if (error && error != boost::asio::error::eof) { // FATALE ERREUR
        std::cout << "[Error]: client receive failed (" << error.message() << ")" << std::endl;
        socket.close();
        io_service.stop();
        return;
    }
    const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
    std::cout << "[Receive]: Client receive: '" << data << "'" << std::endl;
    if (receive_buffer.size() < sizeof(struct rtype::network::EndpointMssg)) { // Check la taille du packet reçu
        // Fatale Error, Le message reçu n'est pas le endpoint du server
        std::cout << "[Error]: Failure Reception of Server Endpoint" << std::endl;
        socket.close();
        io_service.stop();
        return;
    }
    // Conversion du char * en struct rtype::component::MyNetworkInfo
    // struct rtype::component::MyNetworkInfo serverInfo(boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 0}); // C'est juste pour init la structure
    struct rtype::network::EndpointMssg edp;// C'est juste pour init la structure aussi
    
    memcpy(&edp, data, sizeof(struct rtype::network::EndpointMssg));

    std::cout << "Create Entity" << std::endl;
    std::cout << "Server's Addr received" << edp.addr << std::endl;
    std::cout << "Server's Port received" << edp.port << std::endl;

    // Creation Client Entity (Temporaire)
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::entity::Entity clientEntity = handler._eMan.createEntity(); // Creation de l'entity


    /*<<<<<< ASYNC UDP BOOST ASIO    */
    std::cout << "Start UDP" << std::endl;

    // Start Client UDP
    rtype::system::StartNetworkClient addNetworkComponent;
    addNetworkComponent.update(clientEntity); // System pour setup les component pour le network

    // Modification du component OpponentNetwork (Très important pour pouvoir communiqué avec le server)
    struct rtype::component::MyNetworkInfo serverInfo(boost::asio::ip::udp::endpoint{boost::asio::ip::make_address(edp.addr), edp.port});
    handler.getComponent<rtype::component::OpponentNetworkInfo>(clientEntity)._endpoint = serverInfo._endpoint;
    std::cout << "SEND UDP" << std::endl;

    // L'UDP étant setup le client envoi ses informations UDP au server:
    // Conversion Struct en string:
    std::vector<char> sendEndpoint;
    sendEndpoint.resize(sizeof(struct rtype::network::EndpointMssg));
    auto e = handler.getComponent<rtype::component::MyNetworkInfo>(clientEntity);

    struct rtype::network::EndpointMssg edp2{.port = e._endpoint.port()};

    std::string a = e._endpoint.address().to_string();

    memcpy(&edp2.addr, a.data(), a.size());

    memcpy(sendEndpoint.data(), &edp2,sizeof(struct rtype::network::EndpointMssg));

    boost::asio::write(socket, boost::asio::buffer(&edp2, sizeof(struct rtype::network::EndpointMssg)), error); // Envoie de la struct


    // A partir ici le jeu commence:
    // Communication uniquement en UDP avec le server
    //////////////////////////////////////////////////
    // Game loop
    std::cout << "In Game Loop: " << edp2.addr << " " << edp2.port << std::endl;
    // Le Read est temporaire (C'est pour empeché que le client se ferme)

usleep(10000);
    
    handler.getComponent<rtype::component::Socket>(clientEntity)._socket.send_to(boost::asio::buffer("Yo a marche aa"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address(edp.addr), edp.port});
    handler.getComponent<rtype::component::Socket>(clientEntity)._socket.send_to(boost::asio::buffer("Yo a marche aa"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address(edp.addr), edp.port});
    handler.getComponent<rtype::component::Socket>(clientEntity)._socket.send_to(boost::asio::buffer("Yo a marche aa"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address(edp.addr), edp.port});


    boost::asio::streambuf useless;
    boost::asio::read(socket, useless, boost::asio::transfer_at_least(1), error);

    //////////////////////////////////////////////////
    //C'est le server qui dirai en UDP ou TCP (à voir) que la partie est fini

    //Close Server UDP
    rtype::system::CloseNetworkClient deleteNetworkComponent;
    deleteNetworkComponent.update(clientEntity); // System pour delete les component du network

    /*>>>>>> ASYNC UDP BOOST ASIO    */



    // Close TCP Client
    socket.close();
    io_service.stop();

    /*>>>>>> SYNC TCP BOOST ASIO    */

    // Retour au menu principale
    // Si le joueur veut jouer une nouvelle partie
    // On recommence toute la fonction r_type_client(ip, port)

}
