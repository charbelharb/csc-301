//
// Created by charbel on 11/4/25.
//

#ifndef PLAYGROUND_HTTPCLIENT_H
#define PLAYGROUND_HTTPCLIENT_H
#include <string>

class HttpClient {
public:
    static void TryGet(const std::string &url);
};

#endif //PLAYGROUND_HTTPCLIENT_H
