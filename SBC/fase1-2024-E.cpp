#include <iostream>

using namespace std;

int main(){
    int n;
    int first;
    cin >> n;
    int discard, next_line, next_column;
    int rot = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0)
                cin >> first;
            else{
                cin >> discard;
                if (i == 0 && j == 1){
                    next_line = discard;
                }
                if (i == 1 && j == 0){
                    next_column = discard;
                }
            }
        }
    }
    if(next_line > first && next_column > first)
        cout << "0" << endl;
    if(next_line < first && next_column > first)
        cout << "1" << endl;
    if(next_line < first && next_column < first)
        cout << "2" << endl;
    if(next_line > first && next_column < first)
        cout << "3" << endl;
    return 0;
}