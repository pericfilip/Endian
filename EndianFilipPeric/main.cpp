#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

void inputGenerator() {
    ofstream input("input.txt");
    int min = 1;
    int max = 65535;
    srand(time(NULL));

    for(int i = 0; i < 16; i++) {
        int output = min + (rand() % static_cast<int>(max - min + 1));
        input << output << endl;
    }

}

int main() {

    inputGenerator();

    ifstream randomInputs("input.txt");
    ofstream middleByteWriter("middle_byte.txt");
    ofstream littleEndianWriter("little_endian.txt");

    if(randomInputs.is_open()) {
        long loop;
        while(randomInputs >> loop) {

            unsigned short bigEndian = loop;

            unsigned char rightB = bigEndian & 0xFF;
            unsigned char leftB = (bigEndian >> 8) & 0xFF;

            unsigned short littleEndian = (rightB << 8) | leftB;
            littleEndianWriter << littleEndian << endl;
            middleByteWriter << ((littleEndian >> 4) & 0xFF) << endl;
        }
        return 0;
    }
}
