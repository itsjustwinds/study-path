const
        oo=trunc(10e7);
var
        dd:array[-oo..oo] of longint;
        i,j,n,max,kq:longint;
procedure nhap;
var     x:longint;
begin
        kq:=0;
        max:=0;
        readln(n);
        for i:=1 to n do
        begin
                readln(x);
                inc(dd[x]);
                if (dd[x]>max) or ((dd[x]=max)and (x<kq)) then
                begin
                        max:=dd[x];
                        kq:=x;
                end;
        end;
        writeln(kq);
end;
begin
        assign(input,'aaaaaaa.inp');
        assign(output,'aaaaaaaa.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.