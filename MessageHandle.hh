#ifndef MESSSAGE_HANDLE_H
#define MESSSAGE_HANDLE_H

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <vector>
#include "RemoteManagement.hh"

typedef enum
{
    APPTYPE_SERVER = 0,
    APPTYPE_CLIENT,
    APPTYPE_MAX,
} appType_e;

typedef enum
{
    CMD_GET_PID = 0,
    CMD_GET_MEMORY,
    CMD_GET_CPU_USAGE,
    CMD_GET_PORT_USED,
    CMD_KILL_PROCESS,
    CMD_MAX,
} command_e;

typedef enum
{
    MSG_TYPE_CMD = 0,
    MSG_TYPE_RESPONSE,
    MSG_TYPE_END_OF_RESPONSE,
    MSG_TYPE_MAX,
} msgType_e;

typedef struct
{
    msgType_e msgType;
    int socket;
    int sequenceNum;
    string msg;

public:
    void setResponse(int iSocket);
} response_t;

struct MessageHeader
{
private:
    appType_e selfInfo;
    int messageSize;
    msgType_e msgType;
    command_e command;
    bool isPid;
    variant<int, string> pidOrProccessNameVariant;

public:
    MessageHeader();
    void setSelfInfo(appType_e iSelfInfo);
    void setMsgType(msgType_e iMsgType);
    void setCommand(command_e iCommand);
    void setIsPis(bool isPid);
    void setpidOrProccessName(int iPis, string iProcessName);

    void setMessageHandlerInfo(string msg);
    bool parseMessageHandleInfo(MessageHeader iMessageHandle);
    bool checkIsPid();
    void printResponse();
    ~MessageHeader();
};

#endif
