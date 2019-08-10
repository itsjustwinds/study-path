var
        f:array[1..100000] of longint;
        dd:array[1..100000] of longint;
        d:array[1..100000] of longint;
        i,j,n,chay:longint;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
                readln(f[i]);
end;
function tinh(n:longint):longint;
begin
        if f[n]=n then exit(0);
        if dd[f[n]]=chay then
        begin
                d[n]:=2;
                exit(1);
        end;
        if (d[n]<>0) then exit(d[n]);
        dd[n]:=chay;
        d[n]:=1+tinh(f[n]);
        exit(d[n]);
end;
procedure xuly;
begin
        chay:=0;
        for i:=1 to n do
        if d[i]=0 then
        begin
                inc(chay);
                dd[i]:=chay;
                d[i]:=1+tinh(f[i]);
        end;
        for i:=1 to n do
                writeln(d[i]);
end;
begin
        assign(input,'treat.inp');
        assign(output,'treat.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
