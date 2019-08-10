uses crt;
var
        n:longint;
        a,ds:real;
begin   clrscr;
        write('a la:');
        readln(a);
        write('n la:');
        readln(n);
        ds:=exp(n*ln(a));
        write('dap so la:',ds:8:2);
        readln
end.