var
        i,n,su:longint;
begin
        write('n la:');
        readln(n);
        su:=0;
        for i:=1 to n do
        begin
        if n mod i=0 then
        su:=su+1;
        end;
        if su=2 then write('n la so nguyen to');
        if su<>2 then write('n ko la so nguyen to');
        readln
end.