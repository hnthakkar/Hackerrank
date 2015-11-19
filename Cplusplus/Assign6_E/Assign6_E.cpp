#include <iostream>
using namespace std;

/*boolean isWinning(position pos) {
    moves[] = possible positions to which I can move from the
position pos;
    for (all x in moves)
        if (!isWinning(x)) return true;

    return false;
}*/

int main(){
	int K, L, towers;
	cin >> K >> L >> towers;
	int coins = 0;
	int win[1000000];
	win[0] = 0;
	win[1] = 1;
	
	while (towers--) {
		cin >> coins;

	}
	return 0;
}
