struct node {
    int id, num;
    int child[27];
};

int n, qlen, printed;
char word[22], buff[22];
vector <node> t;

void add_node() {
    node c;
    c.id = 0;   c.num = 0;
    for (int i = 0; i <= 26; ++i) c.child[i] = -1;
    t.push_back(c);
}

void insert(char *s) {
    int idx = 0;
    for (int i = 0; s[i]; ++i) {
        int w = s[i] - 'a';
        if (t[idx].child[w] == -1) {
            add_node();
            t[idx].child[w] = t.size() - 1;
        }
        idx = t[idx].child[w];
    }
    t[idx].child[26] = 0;
}

int count(char *s) {
    int idx = 0;
    for (int i = 0; s[i]; ++i) {
        int w = s[i] - 'a';
        if (t[idx].child[w] == -1) return -1;
        idx = t[idx].child[w];
    }
    return idx;
}

void print(int idx, int len) {
    if (t[idx].child[26] == 0 && len > qlen) {
        buff[len] = 0;
        puts(buff);
        printed++;
    }
    for (int i = 0; i < 26; ++i)
        if (t[idx].child[i] != -1) {
            buff[len] = i + 'a';
            print(t[idx].child[i], len + 1);
        }
}

