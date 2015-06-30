#include <iostream>
#include <string>

using namespace std;

//void permutation(string & s) {
//    permutationRecursion(s, 0);
//}

void permutationRecursion(string & s, size_t begin) {
    if(begin == s.length()) {
        cout << s << '\t';
        return;
    }

    for(size_t i = begin; i < s.length(); i++) {
        swap(s[begin], s[i]);
        permutationRecursion(s, begin+1);
        swap(s[begin], s[i]);
    }
}

int main(int argc, const char* argv[]) {
    string s = "abcd";
    permutationRecursion(s, 0);
    return 0;
}
