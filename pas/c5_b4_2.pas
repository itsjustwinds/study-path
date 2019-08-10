var
        a:array [1..100] of longint;
        n,i,cs:longint;
        kt:boolean;
begin
        write('nhap so luong phan tu');
        readln(n);
        kt:=true;
        for i:=1 to n do
        begin
        write(a[i]);
        readln(a[i]);
        end;
        cs:=a[2]-a[1];
        for i:=1 to n-1 do
        if a[i+1]-a[i]<>cs then
        begin
        kt:=false;
        break;
        end;
        if kt=true then write('day co the la cap so cong')
        else write('day khong the la cap so cong');
        readln
end.
