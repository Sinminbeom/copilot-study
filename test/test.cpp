#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = R"(
CONTAINER ID   IMAGE                                                                   COMMAND                  CREATED        STATUS                          PORTS                                                                                                                                                                                                             NAMES
b2c492f07d2e   adtc.swm.ai:5000/control/env-rest-dev:1.0.64                            "java -jar javaexec.…"   3 days ago     Up 3 days                       0.0.0.0:28888->28888/tcp, :::28888->28888/tcp                                                                                                                                                                     infra-glue-env-rest-dev
1a81a1ad725e   adtc.swm.ai:5000/control/env-rest-test:1.0.25                           "java -jar javaexec.…"   3 days ago     Up 3 days                       0.0.0.0:28887->28887/tcp, :::28887->28887/tcp                                                                                                                                                                     infra-glue-env-rest-test
d85070f59240   adtc.swm.ai:5000/a50/cpu:dev-x86_64-18.04-20210914_1336                 "/bin/bash"              3 days ago     Up 3 days                                                                                                                                                                                                                                         apollo_dev_swmai
)";

    std::regex pattern(R"(\b[0-9a-f]{12}\b)");

    std::smatch matches;
    std::string::const_iterator searchStart(text.cbegin());
    while (std::regex_search(searchStart, text.cend(), matches, pattern)) {
        std::cout << matches.str() << std::endl;
        searchStart = matches.suffix().first;
    }

    return 0;
}