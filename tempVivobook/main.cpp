#include <iostream>

class PuzzlePubble {
private:
    char bubbles[6][10];
public:
    PuzzlePubble() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 10 ; j++) {
                bubbles[i][j] = ' ';
            }
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const PuzzlePubble pb){
        for (int i = -1; i < 11; i++) {
            for (int j = -1; j < 7; j++) {
                // ========
                if (i == -1 || i == 10) {
                    os << '=';
                    continue;
                }
                //   |
                else if (j == -1 || j == 6) {
                    os << '|';
                }
                // bubble
                else{
                    os << bubbles[i][j];
                }
            }
            os << std::endl;
        }
    }

    };