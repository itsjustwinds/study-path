const
        fi='tvshow.inp';
        fo='tvshow.out';
type
        tg=record
        a,b:longint;
end;
var
        x:array [1..100000] of tg;
        dem,i,j,n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,x[i].a,x[i].b);
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,t:longint;
        m:longint;
begin
        u:=l;
        v:=r;
        m:=x[(l+r) div 2].a;
        repeat
                while x[u].a<m do inc(u);
                while x[v].a>m do dec(v);
                if u<=v then
                begin
                        t:=x[u].a;x[u].a:=x[v].a;x[v].a:=t;
                        t:=x[u].b;x[u].b:=x[v].b;x[v].b:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if l<v then sort(l,v);
        if u<r then sort(u,r);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,n);
        dem:=0;
        for j:=1 to n-1 do
                for i:=j+1 to n do
                        if x[j].b>x[i].a then
                        begin
                                inc(dem);
                                break;
                        end;
        write(f,dem);
        close(f);
end;
begin
        nhap;
        xuat;
end.