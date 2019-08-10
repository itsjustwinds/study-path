uses math;
var
    a,b:array[0..1005] of int64;
    f:array[0..1005,0..1005] of longint;
    i,j,n,m,d:longint;
procedure nhap;
begin
    while not seekeoln do
    begin
        inc(n);
        read(a[n]);
    end;
    readln;
    while not seekeoln do
    begin
        inc(m);
        read(b[m]);
    end;
end;
{procedure sang;
begin
    for i:=2 to 10000000 do
    if nt[i]=0 then
    begin
        d:=1;
        while d*i<=10000000 do
        begin
            nt[d*i]:=i;
            inc(d);
        end;
    end;
end;}
function nt(n:longint):boolean;
var i:longint;
begin
    if n<2 then exit(false);
    for i:=2 to trunc(sqrt(n)) do
        if n mod i=0 then exit(false);
    exit(true);
end;
function kt(i:longint):boolean;
var x:real;
begin
    if round(sqrt(a[i]))=sqrt(a[i]) then
        exit(true);
    x:=exp(ln(a[i])/3);
    if (round(x)=x) and (nt(round(x))) then
        exit(true);
    exit(false);
end;
procedure xuly;
begin
    for i:=1 to n do
    if kt(i) then
    begin
        for j:=1 to m do
        begin
            if a[i]=b[j] then
                f[i][j]:=f[i-1][j-1]+1
            else f[i][j]:=max(f[i-1][j],f[i][j-1]);
        end;
    end
    else
    begin
        for j:=1 to m do
            f[i][j]:=max(f[i-1][j],f[i][j-1]);
    end;
    writeln(f[n][m]);
end;
begin
    {assign(input,'gen.inp');
    assign(output,'gen.out');
    reset(input);
    rewrite(output);}
    nhap;
    xuly;
    {close(input);
    close(output);}
end.
