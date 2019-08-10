const
        fi='cover.inp';
        fo='cover.out';
var
        l,r,t,vt:array[0..1000001] of longint;
        i,j,k,a,b,n,d,max:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,a,b);
        for i:=1 to n do
        begin
                readln(f,l[i],r[i]);
                vt[i]:=i;
        end;
        close(f);
end;
procedure sort(i,j:longint);
var
        u,v,x,t:longint;
begin
        u:=i;v:=j;x:=l[(i+j) div 2];
        repeat
                while l[u]< x do inc(u);
                while l[v]> x do dec(v);
                if u<=v then
                begin
                        t:=l[u];l[u]:=l[v];l[v]:=t;
                        t:=r[u];r[u]:=r[v];r[v]:=t;
                        t:=vt[u];vt[u]:=vt[v];vt[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if i<v then sort(i,v);
        if u<j then sort(u,j);
end;
procedure xuly(a,b:longint);
begin
        max:=0;
        for i:=1 to n do
                if l[i]<=a then
                begin
                        if r[i]>a then
                                if r[i]>max then max:=r[i];
                end
                else break;
        if max>=b then
        begin
                inc(d);
                t[d]:=vt[max];
                exit;
        end
        else
        begin
                inc(d);
                t[d]:=vt[max];
                xuly(max,b);
        end;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,n);
        xuly(a,b);
        if d<>0 then
        begin
                writeln(f,d);
                for i:=1 to d do
                        writeln(f,t[i]);
        end
        else write(f,-1);
        close(f);
end;
begin
        nhap;
        xuat;
end.
