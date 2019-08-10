const
        fi='sieu_nt.inp';
        fo='sieu_nt.out';
var
        a,b:array[ 1..1000000] of longint;
        i,dem,n,d:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function nt(n:longint):boolean;
var     i:longint;
begin
        nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure snt(n:longint);
var
        i:longint;
begin
        for i:=1 to 9 do
                if nt(n*10+i) then
                begin
                inc(d);
                b[d]:=n*10+i;
                end;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        dem:=0;
        for i:=2 to 9 do
                if nt(i) then
                begin
                        inc(dem);
                        a[dem]:=i;
                end;
        dec(n);
        repeat
        d:=0;
        for i:=1 to dem do
                snt(a[i]);
        for i:=1 to d do
                a[i]:=b[i];
        dem:=d;
        dec(n);
        until n=0;
        for i:=1 to d do
                write(f,a[i],' ');
        close(f);
end;
begin
        nhap;
        xuly;
end.
