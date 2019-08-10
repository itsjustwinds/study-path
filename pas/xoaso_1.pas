const
        fi='xoaso.inp';
        fo='xoaso.out';
var
        s:ansistring;
        i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        i:=1;
        while i<>length(s) do
        begin
                if (s[i] in ['0'..'9']) then
                delete(s,i,1)
                else inc(i);
        end;
        if (s[i] in ['0'..'9']) then delete(s,i,1);
        write(f,s);
        close(f);
end;
begin
        nhap;
        xuly;
end.
