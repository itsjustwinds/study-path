const
        maxn=505;
type matrix=array[1..maxn,1..maxn] of int64;
var
        t,it,n:longint;
        a,b,c:matrix;
        kt:boolean;
procedure nhap;
var     i,j:longint;
begin
        readln(n);
        for i:=1 to n do
        for j:=1 to n do
                read(a[i,j]);
        for i:=1 to n do
        for j:=1 to n do
                read(b[i,j]);
end;
function nhan(x,y:matrix):matrix;
var     z:matrix;
        i,j,k:longint;
begin
        for i:=1 to n do
                for j:=1 to 1 do
                begin
                        z[i][j]:=0;
                        for k:=1 to n do
                        z[i][j]:=z[i][j]+x[i,k]*y[k][j];
                end;
        exit(z);
end;
procedure xuly;
var     i:longint;
        d,e,f,g:matrix;
begin
        randomize;
        for i:=1 to n do
        c[i][1]:=random(10)+1;
        d:=nhan(a,c);
        e:=nhan(a,d);
        f:=nhan(a,e);
        g:=nhan(b,c);
        for i:=1 to n do
        if (f[i][1]<>g[i][1]) then
        begin
                kt:=false;
                exit;
        end;
        kt:=true;
end;
procedure xuat;
begin
        if (kt) then writeln('YES') else writeln('NO');
end;
begin
        assign(input,'mmc.inp');
        assign(output,'mmc.out');
        reset(input);
        rewrite(output);
        readln(t);
        while (t>0) do
        begin
                dec(t);
                nhap;
                xuly;
                xuat;
        end;
        close(input);
        close(output);
end.