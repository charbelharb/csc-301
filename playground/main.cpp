#include <iostream>
#include <memory>
#include "HttpClient.h"
using namespace std;

int main() {
    auto http_client = make_unique<HttpClient>();
    cout << "Hello, World!" << std::endl;
    return 0;
}
