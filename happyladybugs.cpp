#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



string happyLadybugs(string b) {
    int l=count(b.begin(), b.end(), '_');
    int ans1=0,ans2=0, n=b.size();
    if(l==0){
        for(int i=0; i<n-l; i++){
            if(b[i]==b[i-1] || b[i]==b[i+1]) ans2++;
        }
    if(ans2==n) return "YES";
    else return "NO";
    }
    sort(b.begin(),b.end());
    for(int i=0; i<n-l; i++){
        if(b[i]==b[i-1] || b[i]==b[i+1]) ans1++;
    }
    if( ans1==n-l) return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
