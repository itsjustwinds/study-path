var
        a:array [1..100] of longint;
        n,k,i,t:longint;
begin
        write('nhap so luong cac hang tu');
        readln(n);
        t:=0;
        for i:=1 to n do
        begin
        write(a[i]);
        readln(a[i]);
        end;
        write('nhap k:');
        readln(k);
        for i:=1 to n do
        if k=a[i] then write(i,' ');
        for i:=1 to n do
        if k=a[i] then t:=t+1;
        if t=0 then write(' khong tim thay');
        readln
end.

