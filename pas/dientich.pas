var
        a,i,j:longint;
begin
        assign(input,'dientich.inp');
        assign(output,'dientich.out');
        reset(input);
        rewrite(output);
        readln(a);
        for i:=1 to a do
        begin
                for j:=1 to a do
                write('*');
                writeln;
        end;
        close(input);
        close(output);
end.