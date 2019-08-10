uses crt;
var
        a:array[1..100] of longint;
        i,n,dem,t:longint;
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
        dem:=0;
        t:=0;
        for i:=1 to n do
        if a[i] mod 2<>0 then
        begin
        dem:=dem+1;
        t:=t+a[i];
        end;
        writeln('so luong so le la:',dem);
        write('tong cac so le:',t);
        readln
end.
