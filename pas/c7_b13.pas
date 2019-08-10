var
        s:string;
        i,dem:longint;
begin
        dem:=0;
        readln(s);
        for i:=1 to length(s) do
                if (s[i] in['a'..'z']) or (s[i] in ['A'..'Z']) then
                begin
                        write(s[i],' ');
                        inc(dem);
                end;
        writeln;
        write('co ',dem,' chu trong day');
        readln
end.