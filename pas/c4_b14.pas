uses crt;
var
        a,b:longint;
        c,d:real;
begin   clrscr;
        write('a va b la');
        readln(a,b);
        c:=a;
        d:=b;
        while a<>b do
        begin
        if a>b then a:=a-b
        else b:=b-a;
        end;
        c:=c/a;
        d:=d/a;
        write(c:8:0,'/',d:0:0);
        readln
end.