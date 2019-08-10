var
        ngto:array[1..200000] of longint;
        i,j,a,b,d:longint;
procedure nhap;
begin
        readln(a,b);
        if a=1 then a:=2;
        for i:=2 to b do
        if ngto[i]=0 then
        begin
                ngto[i]:=i;
                d:=2;
                while i*d<=b do
                begin
                        ngto[i*d]:=i;
                        inc(d);
                end;
        end;
end;
procedure xuly;
begin
        for i:=a to b do
        if ngto[i]=i then
                writeln(i);
end;
begin
        {assign(input,'pnumber.inp');
        assign(output,'pnumber.out');
        reset(input);
        rewrite(output);}
        nhap;
        xuly;
        {close(input);
        close(output);}
end.
