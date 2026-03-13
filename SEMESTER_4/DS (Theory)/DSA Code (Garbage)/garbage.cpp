#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char* message_1 = "Hello this is imran Butt";
    const char* message_2 = "Hello this is imran buttt";
    string yoah1(message_1);
    string yoah2(message_2);
    cout << yoah1 << endl;
    cout << yoah2 << endl;
    cout << (yoah1 > yoah2) << endl;
    char text_array[50];
    strcpy(text_array, message_1);
    cout << text_array << endl;
    int size = 0;
    const char* keyword = "imran Butt";
    bool found = true;
    for (int i = 0 ; text_array[i] != '\0'; i++) {
         if (text_array[i] == keyword[0]) {
            found = true;
            cout << "I'm Here" << endl; 
            int j = i;
            for (int k = 0; k < strlen(keyword) && (text_array[j] != '\0'); k++, j++ ) {
                cout << "Text: " << text_array[j] << endl;
                cout << "Keyword: " << keyword[k] << endl;
                if (keyword[k] != text_array[j]) {
                    cout << "Condition Failed!" << endl;
                    found = false;
                    break;
                }
            }
            if (found) {
                break;
            }
         } 
     }
    cout << "Found: " << found << endl;
    return 0;
}