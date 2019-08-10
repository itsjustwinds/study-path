var
        n,i,j,kq:longint;
procedure nhap;
begin
        kq:=1;
        readln(n);
        for i:=1 to n div 2 do
        begin
                inc(kq);
                if i*3+1<=n then inc(kq);
        end;
        writeln(kq);
end;
begin
        assign(input,'collatz.inp');
        assign(output,'collatz.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.