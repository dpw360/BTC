#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string getClass(int address[4]) {
    int octet = address[0];
    
    if (octet <= 127) {
        return "A";
    } else if (octet <= 191) {
        return "B";
    } else if (octet <= 223) {
        return "C";
    } else if (octet <= 239) {
        return "D";
    } else {
        return "E";
    }
}

string getMask(string ntwkClass) {
    if (ntwkClass == "A") {
        return "255.0.0.0";
    } else if (ntwkClass == "B") {
        return "255.255.0.0";
    } else if (ntwkClass == "C") {
        return "255.255.255.0";
    } else {
        return "NO MASK";
    }
}

string getNetwkID(int address[4], string ntwkClass) {
    if (ntwkClass == "A") {
        return to_string(address[0]) + ".0.0.0";
    } else if (ntwkClass == "B") {
        return to_string(address[0]) + "." + to_string(address[1]) + ".0.0";
    }  else if (ntwkClass == "C") {
        return to_string(address[0]) + "." + to_string(address[1]) + "." + to_string(address[2]) + ".0";
    } else {
        return "N/A";
    }
}

string getHostMin(int address[4], string ntwkClass) {
    if (ntwkClass == "A") {
        return to_string(address[0]) + ".0.0.1";
    } else if (ntwkClass == "B") {
        return to_string(address[0]) + "." + to_string(address[1]) + ".0.1";
    }  else if (ntwkClass == "C") {
        return to_string(address[0]) + "." + to_string(address[1]) + "." + to_string(address[2]) + ".1";
    } else {
        return "N/A";
    }
}

string getHostMax(int address[4], string ntwkClass) {
    if (ntwkClass == "A") {
        return to_string(address[0]) + ".255.255.254";
    } else if (ntwkClass == "B") {
        return to_string(address[0]) + "." + to_string(address[1]) + ".255.254";
    }  else if (ntwkClass == "C") {
        return to_string(address[0]) + "." + to_string(address[1]) + "." + to_string(address[2]) + ".254";
    } else {
        return "N/A";
    }
}

string getBroadcast(int address[4], string ntwkClass) {
    if (ntwkClass == "A") {
        return to_string(address[0]) + ".255.255.255";
    } else if (ntwkClass == "B") {
        return to_string(address[0]) + "." + to_string(address[1]) + ".255.255";
    }  else if (ntwkClass == "C") {
        return to_string(address[0]) + "." + to_string(address[1]) + "." + to_string(address[2]) + ".255";
    } else {
        return "N/A";
    }
}

int main() {
    bool quit = false;
    while (!quit) {
        // Get an IP address and convert it to a string stream object.
        cout << "Enter q to quit.\n";
        cout << "Enter an IP Address: ";
        string ipAddyRaw, octet;
        cin >> ipAddyRaw;
        if (ipAddyRaw == "q") {
            break;
        }
        stringstream ipAddy (ipAddyRaw);

        // Populate an array w/ the octets.
        int address[4];
        int octetNum = 0;
        while (getline(ipAddy, octet, '.')) {
            address[octetNum] = stoi(octet);
            octetNum++;
        }

        // Checks if the address is valid.
        bool invalidFlag = false;
        for (int i = 0; i < 4; i++) {
            if (address[i] > 255 || address[i] < 1) {
                invalidFlag = true;
            }
        }

        // Checks if the address is valid.
        if (invalidFlag) {
            cout << "This address is invalid!" << endl;
            continue;
        }

        // Initiates all the variables for the address components and displays.
        string networkClass, mask, netwkID, hostMin, hostMax, broadcast;
        networkClass = getClass(address);
        mask = getMask(networkClass);
        netwkID = getNetwkID(address, networkClass);
        hostMin = getHostMin(address, networkClass);
        hostMax = getHostMax(address, networkClass);
        broadcast = getBroadcast(address, networkClass);

        cout << "Network Class:       " + networkClass + "\nMask:                " + mask +
            "\nNetwork ID:          " + netwkID + "\nHost Min:            " + hostMin +
            "\nHost Max:            " + hostMax + "\nBroadcast:           " + broadcast << endl;
    }
}