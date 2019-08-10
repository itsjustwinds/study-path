var     i:longint;
        kq:int64;
begin
        assign(input,'11111111.inp');
        assign(output,'111111111.out');
        reset(input);
        rewrite(output);
        kq:=1;
        for i:=1 to 10 do
                kq:=kq*i;
        writeln(kq);
        close(input);
        close(output);
end.