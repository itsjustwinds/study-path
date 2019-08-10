uses crt;
var
        n,i:longint;
begin   clrscr;
        write('nhap n:');
        readln(n);
        if n mod 2<>0 then
        for i:=1 to n do
        if i mod 2<>0 then write(i,' ');
        if n mod 2=0 then
        for i:=1 to n do
        if i mod 2=0 then write(i,' ');
        readln
end.
