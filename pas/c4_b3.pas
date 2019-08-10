var
        s,n,i:longint;
        tbc:real;
begin
        writeln('nhap n:');
        readln(n);
        s:=0;
        for i:=1 to n do s:=s+i;
        tbc:=s/n;
        writeln('tbc la:',tbc:6:2);
        readln
end.
