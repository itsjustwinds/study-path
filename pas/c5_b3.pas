var
        a:array [1..100] of longint;
        n,max,i:longint;
begin
        writeln('nhap so luong cac phan tu');
        readln(n);
        for i:=1 to n do
        begin
        write(a[i]);
        readln(a[i]);
        end;
        max:=a[1];
        for i:=2 to n do
        if max<a[i] then max:=a[i];
        write('so lon nhat la:',max);
        readln
end.
