var
        a:array [1..100] of longint;
        b:array [1..100] of longint;
        i,n,j,dem,max:longint;
begin
        write('nhap so luong phan tu');
        readln(n);
        dem:=0;
        for i:=1 to n do
        begin
        write('nhap gia tri');
        readln(a[i]);
        end;
        for i:=1 to n do
        if a[i]<0 then
        begin
        dem:=dem+1;
        b[dem]:=a[i];
        end;
        max:=b[1];
        for i:=2 to dem do
        if b[i]>max then max:=b[i];
        write('so am lon nhat la:',max);
        readln
end.
