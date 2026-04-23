#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const bool debug = false;

map<char, int> charMap = {
    {'-', 0},
    {'\\', 1},
    {'(', 2},
    {'@', 3},
    {'?', 4},
    {'>', 5},
    {'&', 6},
    {'%', 7},
    {'/', -1}
};

int parseValue(string targetValue);
int eightPower(int p);

int main() {
	fastio;

    string inputVal;

    while(true){
        getline(cin, inputVal);
        if(inputVal == "#") break;
        int parsedVal = parseValue(inputVal);
        cout << parsedVal << "\n";
    }
    

	return 0;
}

int parseValue(string targetValue){
    int length = targetValue.size();
    int result = 0;

    for(int i = 0; i < length; i++){
        int value = eightPower(length - 1 - i) * charMap[targetValue[i]];
        result += value;
        // cout << value << " ";
    }
    // cout << "----------\n";
    return result;
}

int eightPower(int p){
    int result = 1;
    for(int i = 0; i < p; i++){
        result *= 8;
    }
    return result;
}