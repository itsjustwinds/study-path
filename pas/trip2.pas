const
        fi='trip.inp';
        fo='trip.out';
var
        m:array[1..100001] of longint;
        n,d,dem,i,j:longint;
        f,g:text;

procedure sort(l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;v:=r;x:=m[l+random(r div 2)];
        repeat
                while m[u]<x do inc(u);
                while m[v]>x do dec(v);
                if u<=v then
                begin
                        t:=m[u];m[u]:=m[v];m[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if l<v then sort(l,v);
        if u<r then sort(u,r);
end;
procedure xuly;
begin
        sort(1,n);
        i:=1;j:=n;dem:=0;
        repeat
                if m[i]+m[j]<=d then
                begin
                        inc(dem);
                        inc(i);dec(j);
                end
                else
                begin
                        inc(dem);
                        dec(j);
                end;
           {     if i=j then
                begin
                        inc(i);
                        inc(dem);
                end;}
        until i>j;
        writeln(g,dem);
end;
procedure nhap;
begin
        assign(f,fi);
        assign(g,fo);
        reset(f);
        rewrite(g);
        while not(eof(f)) do
        begin
                readln(f,n,d);
                for i:=1 to n do
                        read(f,m[i]);
                        readln(f);
                        xuly;
        end;
        close(f);
        close(g);
end;
begin
        nhap;
end.
