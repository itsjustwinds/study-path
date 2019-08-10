uses crt;
var
        a:array[1..100] of longint;
        i,n:longint;
begin   clrscr;
        write('nhap so luong phan tu:');
        readln(n);
        for i:=1 to n do
        begin
                write('nhap so thu:');
                readln(a[i]);
        end;
        write('mang vua nhap la:');
        writeln;
        for i:=1 to n do
        if a[i]<0 then writeln(a[i],' o vi tri so ',i);
        readln
end.
