var
        i,n:longint;
begin
        write('nhap n:');
        readln(n);
        for i:=2 to n do
        while n mod i=0 do
        begin
        write(i);
        n:=n div i;
        if n<>0 then write('x');
        end;
        write(n);
        readln
end.
