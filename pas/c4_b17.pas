uses crt;
var
        i,n,su,s:longint;
begin   clrscr;
        write('n la:');
        readln(n);
        for s:=2 to n do
        begin
        su:=0;
        for i:=1 to s do
        if s mod i=0 then inc(su);
        if su=2 then write(s,' ');
        end;
        readln
end.
