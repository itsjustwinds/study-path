var
        n,i,s,su:longint;
begin
        write('nhap n:');
        readln(n);
        su:=0;
        for s:=2 to n do
        begin
        for i:=1 to s do
        if s mod i=0 then
        su:=su+1;
        if su=2 then write(s,' ');
        end;
        readln
end.