//
//  main.cpp
//  BLP_API
//
//  Created by Olga on 13/05/16.
//  Copyright © 2016 Sergey. All rights reserved.
//

#include <iostream>
#include <string.h>

#include "blpapi_correlationid.h"
#include "blpapi_event.h"
#include "blpapi_message.h"
#include "blpapi_request.h"
#include "blpapi_session.h"

using namespace BloombergLP;
using namespace blpapi;

static void handleResponseEvent(const Event& event){
    std::cout << "EventType ="
    << event.eventType()
    << std::endl;
    MessageIterator iter(event);
    while (iter.next()){
        Message message = iter.message();
        std::cout << "correlationId="
        << message.correlationId()
        << std::endl;
        std::cout << "messageType  ="
        << message.messageType()
        << std::endl;
        message.print(std::cout);
    }
}

static void handleOtherEvent(const Event& event){
    std::cout << "EventType="
    << event.eventType()
    << std::endl;
    MessageIterator iter(event);
    while (iter.next()) {
        Message message = iter.message();
        std::cout << "correlationId="
        << message.correlationId()
        << std::endl;
        std::cout << "messageType="
        << message.messageType()
        << std::endl;
        message.print(std::cout);
        if (Event::SESSION_STATUS == event.eventType()
            &&  0 == ::strcmp("SessionTerminated",
                              message.messageType().string())) {
                std::cout << "Terminating: "
                          << message.messageType()
                          << std::endl;
                ::exit(1);
            }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}













