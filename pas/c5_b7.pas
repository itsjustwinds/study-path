uses crt;
var
        a:array[1..100] of longint;
        i,n,j,dem:longint;
        kt:boolean;
begin   clrscr;
        kt:=true;
        write('nhap so luong cac phan tu');
        readln(n);
        dem:=0;
        for i:=1 to n do
        begin
        write('gia tri la:');
        readln(a[i]);
        end;
        for i:=1 to n div 2do
        if a[i]<>a[n-i+1] then
        begin
        kt:=false;
        break;
        end;
        if kt=true then write('mang doi xung')
        else write('mang khong doi xung');
        readln
end.

