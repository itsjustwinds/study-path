uses crt;
var
        a,b,i,c,d:longint;
        k:real;
begin   clrscr;
        write('nhap a va b ');
        readln(a,b);
        c:=a;
        d:=b;
        while a<>b do
        if a>b then a:=a-b
        else b:=b-a;
        writeln('ucln la:',a);
        write('bcnn la:',c*d div a);
        readln
end.
