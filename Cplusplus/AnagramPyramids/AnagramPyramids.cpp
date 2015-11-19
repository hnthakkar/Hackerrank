#include <iostream>
using namespace std;

struct dictRef {
	int len;
	int occur[26];
};

int abs(int a, int b){
	if (a > b)
		return a - b;
	return b - a;
}

int main() {
	int T = 1;
	char ch = 0;
	while (cin >> ch) {
		cin.unget();
		int words = 0;
		cin >> words;
		struct dictRef *dict[words];
		string tmp;
		int len = 0;
		for (int i = 0; i < words; i++) {
			cin >> tmp;
			len = tmp.length();
			struct dictRef *input = new dictRef();
			input->len = len;
			for (int j = 0; j < len; j++) {
				input->occur[toupper(tmp.at(j)) - 65] += 1;
			}
			dict[i] = input;
		}

		int cases;
		cin >> cases;
		cout << "Case " << T << ":" << endl;
		while (cases--) {
			string top, bottom;
			cin >> top >> bottom;
			int topLen = top.length();
			int topOccur[26] = {};
			for (int i = 0; i < topLen; i++) {
				topOccur[toupper(top.at(i)) - 65] += 1;
			}

			int bottomLen = bottom.length();
			int bottomOccur[26] = {};
			for (int i = 0; i < bottomLen; i++) {
				bottomOccur[toupper(bottom.at(i)) - 65] += 1;
			}

			int ref[26];
			for (int i = 0; i < 26; i++){
				ref[i] = bottomOccur[i];
			}
			bool match = false;
			for (int i = bottomLen-1; i >= topLen; i--) {
				bool diffFound = false;
				match = false;
				struct dictRef *item;
				for (int j = 0; j < words; j++) {
					item = dict[j];
					if (item->len != i)
						continue;
					diffFound = false;
					int *itemOccur = item->occur;
					for (int k = 0; k < 26; k++) {
						if (ref[k] == itemOccur[k]){
							if (k == 25 && diffFound){
								match = true;
							}
							continue;
						}

						if (diffFound || abs(ref[k],item->occur[k]) > 1){
							break;
						} else {
							diffFound = true;
						}
					}
					if (match) {
						break;
					}
				}
				if (!match){
					break;
				} else {
					for (int k = 0; k < 26; k++) {
						ref[k] = item->occur[k];
					}
				}
			}
			if (match){
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
		T++;
	}
	return 0;
}
