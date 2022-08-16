#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, par = 0;
    string str = "", word, ans = "";
    char c;

    scanf("%d", &n);
    scanf("%c", &c);
    for (int i = 0; i < n; i++) {
        scanf("%c", &c);

        str += c;
    }

    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            par++;
            ans += "...";

            while (i < n && par != 0) {
                i++;

                if (str[i] == '(') par++;
                if (str[i] == ')') par--;
            }
        } else {
            ans += str[i];
        }
    }

    cout << ans << endl;

    return 0;
}
