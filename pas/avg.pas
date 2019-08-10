const
        max=1000000000;
var
        a:array[1..1000] of longint;
        i,j,k,t,n:longint;
procedure xuly;
var
        i,j,k:longint;
        kq:int64;
        tong:array[1..1000,1..1000] of int64;
begin
        kq:=0;
        for i:=1 to n-2 do
                for j:=i+2 to n do
                tong[i,j]:=a[i]+a[j];
        for k:=2 to n do
        begin
                for i:=1 to k-1 do
                        for j:=k+1 to n do
                                if (tong[i,j]=2*a[k]) then
                                        inc(kq);
        end;
        writeln(kq);
end;
procedure nhap;
begin
        readln(t);
        for k:=1 to t do
        begin
                readln(n);
                for i:=1 to n do
                        read(a[i]);
                xuly;
        end;
end;
begin
        assign(input,'avg.inp');
        assign(output,'avg.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
