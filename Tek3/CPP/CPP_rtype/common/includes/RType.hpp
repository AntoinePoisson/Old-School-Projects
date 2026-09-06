/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** RType
*/

#ifndef INFORTYPE_HPP_
#define INFORTYPE_HPP_

#define TIMERGAME 40

enum {
    Ok = 0,
    Err = 84,
};

namespace rtype {

    enum idBitset {
        idPosition = 1,//0
        idDestination = 2,
        idNextPosition = 4,
        idDirection = 8,
        idStartingTime = 16,
        idSpeed = 32,
        idSurface = 64,
        idCollision = 128,
        idCollided = 256,
        idConceidedDamage = 512,
        idDamage = 1024,
        idLife = 2048,
        idSprite = 4096,
        idSpriteSheet = 8192,
        idText = 16384,
        idSound = 32768,
        idStartCriteria = 65536,
        idKeyboardEvent = 131072,
        idIOService = 262144,
        idSocket = 524288,
        idMyNetworkInfo = 1048576,
        idOpponentNetworkInfo = 2097152,
        idQueueMessageReceive = 4194304,
        idQueueMessageSend = 8388608,
        idListClientNetwork = 16777216,
        idListAction = 33554432,
        idSFMLEvent = 67108864,
        idSFMLWindow = 134217728,
        idMusic = 268435456,
        idDisplayOrder = 536870912,
        idType = 1073741824,
        idScene = 2147483648,
        idSocketTCP = 4294967296,
        idQueueMessageSendClient = 8589934952,
        idQueueMessageRecvClient = 17179869184,
        idServerEndpoints = 34359738368,
        idMouseEvent = 68719476736,
        idButtonAction = 137438953472,
        idUnremovable = 274877906944,
        idServer = 549755813888,
        idPlayer = 1099511627776,
        idBullet = 2199023255552,
        idMob = 4398046511104,
        idListMethodeMob = 8796093022208,
        idNbrMob = 17592186044416,
        idLevel = 35184372088832,
        idDeletOrPrint = 70368744177664,
        idGlobalVolume = 140737488355328,//47
        idTimerMob = 281474976710656,
        idnexth = 562949953421312,//2 power 49 here
    };

    enum tempBitSet {
        idRead = 1,
        idWrite = 2,
        idInterpret = 4,
        idAsync = 8,
    };

    enum whoIs {
        Player = 1099511627776,
        Monster = 4398046511104,
        Bullet = 2199023255552,
        Server = 549755813888,
    };
}

#endif /* !INFORTYPE_HPP_ */
