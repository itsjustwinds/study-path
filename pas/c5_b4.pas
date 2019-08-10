var
        a:array [1..100] of longint;
        n,i,t,j:longint;
begin
        write('nhap so luong cac phan tu:');
        readln(n);
        t:=0;
        for I:=1 to n do
        begin
                write('nhap gia tri');
                readln(a[i]);
        end;
        for i:=1 to n-1 do
        begin
        for j:=n downto i do
        if a[i]=a[j]then
        t:=t+1;
        end;
        if t<>0 then
        write('co the sap xep thanh cap so cong va cap so nhan')
        else write('khong the sap xep thanh cap so cong va cap so nhan');
        readln
end.

