var
        n,i,k:longint;
begin
        write('nhap n:');
        readln(n);
        i:=n div 4096;
        k:=i;
        if n mod 4096<>0 then
        begin
        k:=i+1;
        write('so n chiem la:',4*k);
        end;
        if n mod 4096=0 then write('n chiem la:',4*k);
        readln
end.
