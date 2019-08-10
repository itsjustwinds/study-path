var
        a:array [1..100] of longint;
        n,i:longint;
        cb:real;
        kt:boolean;
begin
        write('nhap so luong cacgia tri:');
        readln(n);
        kt:=true;
        for i:=1 to n do
        begin
        write('nhap gia tri:');
        readln(a[i]);
        end;
        cb:=a[2]/a[1];
        for i:=1 to n-1 do
        if a[i+1]/a[i]<>cb then
        begin
        kt:=false;
        break;
        end;
        if kt=true then write('day la cap so nhan')
        else write('day khong la cap so nhan');
        readln
end.
