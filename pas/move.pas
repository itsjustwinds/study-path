var
        a:array[1..10000,1..10000] of integer;
        d:array[1..10000] of integer;
        i,j,n,x,y:longint;
        kq:int64;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
        begin
                readln(x,y);
                inc(d[x]);
                a[x,d[x]]:=y;
        end;
