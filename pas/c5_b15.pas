var
        a:array[1..100] of longint;
        n,i,max,dem:longint;
begin   dem:=0;
        max:=1;
        write('nhap so luong cac phan tu');
        readln(n);
        for i:=1 to n do
        begin
        write('nhap gia tri');
        readln(a[i]);
        end;
        for i:=1 to n+1 do
        if a[i] >0 then inc(dem)
        else
                begin
                        if dem>max then max:=dem;
                        dem:=0;
                end;
        write('so phan tu co trong doan duong dai nhat la:',max);
        readln
end.