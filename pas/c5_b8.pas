var
        a:array [1..1000] of qword;
        i,x,b,c,n,dem:longint;
begin
        write('nhap so luong phan tu:');
        readln(n);
        for i:=1 to n do
        begin
        write('gia tri la');
        readln(a[i]);
        end;
        dem:=0;
        for i:=1 to n do
        if (111<=a[i]) and (a[i]<1000) then
        begin
        x:=a[i] div 100;
        b:= (a[i] mod 100) div 10;
        c:= (a[i] mod 100) mod 10;
        if (x<=b) and (b<=c) then
        dem:=dem+1;
        end;
        write('so luong phu hop de la:',dem);
        readln
end.
