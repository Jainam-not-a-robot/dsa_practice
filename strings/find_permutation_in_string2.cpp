#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.length()>s2.length()) {
        cout << "false" << endl;
        return 0;
    }
    vector<int> m(26,0);
    vector<int> m2(26,0);
    for(auto &x:s1) m[x-'a']++;
    int first_idx=0;
    int last_idx=s1.length()-1;
    for(int j=0;j<s1.length();j++) {
        m2[s2[j]-'a']++;
    }
    for(int i=0;i<s2.length()-s1.length()+1;i++) {
        if(m==m2) {
            cout << "true" << endl;
            return 0;
        }
        else {
            m2[s2[first_idx++]-'a']--;
            if(last_idx+1<s2.length()) m2[s2[++last_idx]-'a']++;
        }
    }
    cout << "false" << endl;
    return 0;
}
//In sliding window technique we convert 0(n*k) to O(n+k), we first initialise the vector and delete the first item and add the last item till we can,
//that's it 
//instead of creating a new vector/datatype
