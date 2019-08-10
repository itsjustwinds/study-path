var
        a:array [1..100] of longint;
        n,i,t:longint;
begin
        t:=1;
        write('nhap n');
        readln(n);
        for i:=1 to n do
        begin
        write(a[i]);
        readln(a[i]);
        end;
        for i:=1 to n do
        begin
        if trunc(sqrt(a[i]))=sqrt(a[i]) then
        t:=t*a[i];
        end;
        write('tich cac so chinh phuong la:',t);
        readln
end.

