var
        a:array [1..100] of longint;
        n,i:longint;
begin
        write('nhap so luong cac phan tu');
        readln(n);
        for i:=1 to n do
        begin
        write(a[i]);
        readln(a[i]);
        end;
        for i:=1 to n do
        begin
        if a[i]<0 then
        write(a[i],' ');
        end;
        writeln;
        for i:=1 to n do
        begin
        if a[i]>0 then
        write(a[i],' ');
        end;
        readln
end.
