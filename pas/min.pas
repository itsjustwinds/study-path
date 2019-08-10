const
        fi='max.inp';
        fo='max.out';
var
        a:array [1..1000000] of longint;
        i,n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,a[i]);
        close(f);
end;
function timmax:longint;
var max:longint;
begin
        max:=a[1];
        for i:=2 to n do
                if a[i]>max then max:=a[i];
        timmax:=max;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        write(f,timmax);
        close(f);
end;
begin
        nhap;
        xuly;
end.

