#include <iostream>
#include <bits/stdc++.h>

using namespace std;



string multi(char a, const string &b) {
    string s = "";
    int temp = 0;
    for (int i = b.length() - 1; i>=0; i--) {
        temp += (int(a) - 48) * (int(b[i])- 48);
        s = char(temp % 10 + 48) + s;
        temp = temp / 10;
    }
    if (temp >0) {
        s = char(temp + 48) + s;
    }
    return s;
}
string operator+ (string a, string b) {
    string s = "";
    a.insert(0, b.length() - a.length(), '0');
    b.insert(0, a.length() - b.length(), '0');
    int l = a.length();
    int temp = 0;
    for (int i = l-1; i>=0; i--) {
        temp += a[i] - '0' + b[i] - '0';
        s = char(temp%10 + 48) + s;
        temp = temp / 10;
    }
    if (temp >0) s = '1' + s;
    return s;
}

string operator* (const string &a, const string &b) {
    string s = "";
    int l = a.length();
    string s1[l];
    for (int i = l - 1; i>=0; i--) {
        s1[i] = multi(a[i],b);
        s1[i].insert(s1[i].length(), l - i - 1, '0');
        s = s + s1[i];
    }
    return s;

}
int main()
{
    //freopen("2008c.inp","r",stdin);
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    string f[1001];
    f[1] = "2";
    f[0] = "1";
    for (int i = 2; i<=n-2; i++) {
        f[i] = f[0] + to_string(i) * f[i-1];
    }
    cout<<f[n-2];
}

